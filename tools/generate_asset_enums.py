#!/usr/bin/env python3
import argparse
import yaml
import re
import os
from typing import Dict, List
from pathlib import Path


def build_asset_map(assets_file: str) -> Dict[str, str]:
    file_types_to_skip = (
        'LevelSetup',       # 0x071D - 0x07B5
        'DemoInput',        # 0x09A2 - 0x0A0A
        'QuizQuestion',     # 0x1213 - 0x13D5
        'GruntyQuestion',   # 0x1407 - 0x1424
        'Midi'              # 0x1516 - 0x15C2
    )
    
    file_type_to_asset_type = {
        'Animation': 'ANIM',
        'Model': 'MODEL',
        'Sprite_I4': 'SPRITE',
        'Sprite_I8': 'SPRITE',
        'Sprite_CI4': 'SPRITE',
        'Sprite_CI8': 'SPRITE',
        'Sprite_RGBA16': 'SPRITE',
        'Sprite_RGBA32': 'SPRITE',
        'Sprite_UNKNOWN(256)': 'SPRITE',
        'Dialog': 'DIALOG',
    }

    asset_map = {}
    with open(assets_file, 'r') as stream:
        try:
            data = yaml.safe_load(stream)
            if "files" not in data:
                raise Exception("Expected to find 'files' key in assets file")
            files = data["files"]
            for file in files:
                file_type = file["type"]
                if file_type in file_types_to_skip:
                    continue

                if file_type not in file_type_to_asset_type:
                    continue

                asset_type = file_type_to_asset_type[file_type]
                address = file["uid"]
                asset_map[f"{address:X}"] = f"ASSET_{address:X}_{asset_type}_UNKNOWN"
        except yaml.YAMLError as exc:
            print(exc)

    return asset_map


def get_existing_asset_enums(assets_enum_file: str) -> Dict[str, str]:
    with open(assets_enum_file, "r") as enums_stream:
        existing_asset_match = re.compile(r"^\s*(ASSET_([A-F0-9]+)_\w+)", re.IGNORECASE)
        existing_asset_mappings = {}
        for line in enums_stream:
            asset_line = existing_asset_match.match(line)
            if asset_line is not None:
                asset_address = asset_line.group(2).upper()
                existing_asset_mappings[asset_address] = asset_line.group(1)

    return existing_asset_mappings


def build_asset_enum(asset_map: Dict[str, str], existing_assets: Dict[str, str]) -> List[str]:
    asset_enum_lines = []
    address_already_defined = False
    for i in range(1, int(0x1516)):
        address = f"{i:X}"
        if address in existing_assets:
            if address_already_defined is False:
                asset_enum_lines.append(
                    f"{existing_assets[address]} = 0x{address},")
                address_already_defined = True
            else:
                asset_enum_lines.append(f"{existing_assets[address]},")
        elif address in asset_map:
            if address_already_defined is False:
                asset_enum_lines.append(f"{asset_map[address]} = 0x{address},")
                address_already_defined = True
            else:
                asset_enum_lines.append(f"{asset_map[address]},")
        else:
            asset_enum_lines.append(f"// {address} unused")
            address_already_defined = False

    asset_enum_lines = remove_unnecessary_unused_asset_lines(asset_enum_lines)

    # Remove trailing comma in last asset line
    last_line: str = asset_enum_lines[-1]
    if last_line.endswith(","):
        last_line = last_line.replace(",", "")
        asset_enum_lines[-1] = last_line

    return map(lambda x: f"    {x}", asset_enum_lines)


def remove_unnecessary_unused_asset_lines(lines: List[str]) -> List[str]:
    prev_unused = False
    unused_asset_line_indexes = []
    # Create list of lines that contain "// xx is unused"
    for idx, line in enumerate(lines):
        if line.endswith('unused') is False:
            continue
        
        if idx + 1 >= len(lines):
            continue

        prev: str | None = lines[idx - 1]
        prev_unused = prev is not None and prev.endswith('unused')

        next: str | None = lines[idx + 1]
        next_unused = next is not None and next.endswith('unused')

        if prev_unused and next_unused:
            unused_asset_line_indexes.append(idx)

    # "Group" lines where multiple "// xx is unused" lines occur in a row
    groups = []
    group = []
    target = None
    for idx, line_index in enumerate(unused_asset_line_indexes):
        if target is not None and target > idx:
            continue
        else:
            target = None

        for next in range(0, len(unused_asset_line_indexes) - idx):
            if unused_asset_line_indexes[next + idx] == line_index + next:
                group.append(next + idx)
            else:
                break

        if len(group) == 0:
            continue

        combine_from_index = group[0]
        combine_from = unused_asset_line_indexes[combine_from_index]
        combine_to_index = group[len(group)-1]
        combine_to = unused_asset_line_indexes[combine_to_index]
        groups.append((combine_from - 1, combine_to + 1))
        group = []
        target = next + idx

    # Replace the "unnecessary" lines with a single line that lists the range that is unused
    offset = 0
    address_regex = re.compile(r"^// (\w+) unused$")
    for group in groups:
        (start, end) = group
        start -= offset
        start_line = lines[start]
        start_match = address_regex.match(start_line)

        end -= offset
        end_line = lines[end]
        end_match = address_regex.match(end_line)

        if start_match is not None and end_match is not None:
            lines[start:end+1] = [
                f"// 0x{start_match.group(1)} - 0x{end_match.group(1)} unused"
            ]

        offset += end - start

    return lines


def write_enum_file(asset_lines: List[str], out_file: str):
    with open(out_file, "w") as enums_out:
        lines = [
            "enum asset_e",
            "{",
            *asset_lines,
            "};"
        ]
        enums_out.write("\n".join(lines))


def main():
    parser = argparse.ArgumentParser(
        description='Generate asset_e enum from assets/assets.yaml and include/enums.h files',
        formatter_class=argparse.RawDescriptionHelpFormatter
    )
    parser.add_argument(
        'basedir',
        type=str,
        help="base directory (containing src/)"
    )
    args = parser.parse_args()

    asset_map = build_asset_map(
        assets_file=f"{args.basedir}{os.sep}assets{os.sep}assets.yaml"
    )
    existing_assets = get_existing_asset_enums(
        assets_enum_file=f"{args.basedir}{os.sep}include{os.sep}enums.h"
    )

    asset_enum_lines = build_asset_enum(asset_map, existing_assets)
    write_enum_file(
        asset_enum_lines,
        out_file=f"{args.basedir}{os.sep}assets.h"
    )


if __name__ == '__main__':
    main()
