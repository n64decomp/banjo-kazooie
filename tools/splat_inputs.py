#!/usr/bin/env python3
# Script to get a list of input files that are referenced by a splat file
import argparse
import sys
sys.path.append("./tools/n64splat")

from split import *

def main(config_path):
    # Load config
    with open(config_path) as f:
        config = yaml.load(f.read(), Loader=yaml.SafeLoader)

    options.initialize(config, config_path, None, None)
    options.set("modes", [])
    options.set("verbose", False)

    all_segments = initialize_segments(config["segments"])

    objs = ""

    for segment in all_segments:
        linker_entries = segment.get_linker_entries()
        for entry in linker_entries:
            src_paths = entry.src_paths
            for path in src_paths:
                objs += str(path) + " "
    
    return objs


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Get objects for splat file',
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('yamls', nargs='+', help="Splat files")
    args = parser.parse_args()

    obj_lists = map(main, args.yamls)
    # map(print, obj_lists)
    for obj_list in obj_lists:
        print(obj_list)

