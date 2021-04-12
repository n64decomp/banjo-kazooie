import argparse
import os
import re
import sys
import subprocess
import glob

def parse_map(mapfile, section, ending=None):
    functions = {}
    files = {}

    in_code = False

    filename = None
    function = None
    total_size = None

    previous_offset = 0

    while True:
        line = mapfile.readline()
        if not line:
            break

        if not in_code:
            if line.startswith(section):
                in_code = True
                split_line = line.split()
                if len(split_line) > 2:
                    # should we take file offset from individual offsets?
                    total_size = int(split_line[1], 16) + int(split_line[2], 16)
                else:
                    # try nextline
                    line = mapfile.readline()
                    split_line = line.split()
                    if len(split_line) < 2:
                        print("Could not determine total size, aborting")
                        break
                    total_size = int(split_line[0], 16) + int(split_line[1], 16)
                continue
        else:
            if (ending and line.startswith(ending)) or (ending is None and len(line) in [0, 1, 2]):
                in_code = False
                if function and total_size:
                    functions[function]["length"] = total_size - functions[function]["offset"]
                else:
                    print("No function / unable to determine total size")
                break
            # assuming "build/src/..."
            if line.startswith(" build/"):
                filename = line[7:].replace(".o(.text)", "").strip()
                files[filename] = []
                continue
            if line.startswith(" .text "):
                continue
            # should we use regex?
            split_line = line.split()
            if len(split_line) == 2:
                offset, new_function = split_line
                offset = int(offset, 16)
            else:
                continue
            if offset < previous_offset:
                continue
            if function:
                # not 100% accurate due to nops but.. it'll do for now
                functions[function]["length"] = offset - functions[function]["offset"]
            functions[new_function] = {"offset": offset, "filename": filename, "language": "asm"}
            files[filename].append(new_function)
            function = new_function
            previous_offset = offset

    return (files, functions)


def parse_file(basedir, filename, file_funcs):
    updates = []
    c_path = os.path.join(basedir, filename + ".c")
    pattern = re.compile(r'#pragma GLOBAL_ASM\(".*\/([^\/]+)\.s"\)')
    if os.path.isfile(c_path):
        global_asms = []
        with open (c_path, "r") as f:
            while True:
                line = f.readline()
                if not line:
                    break
                match = pattern.match(line)
                if match:
                    global_asms.append(match.group(1))
        for function in file_funcs:
            if not function in global_asms:
                updates.append(function)
    return updates


def generate_csv(files, functions, nonmatching_funcs, version, section):
    ret = []
    ret.append("version,section,filename,function,offset,length,matching")
    for filename, funcs in files.items():
        basename = os.path.basename(filename)
        for func in funcs:
            matching = "no" if func in nonmatching_funcs else "yes"
            offset = functions[func]["offset"]
            length = functions[func]["length"]
            ret.append(f"{version},{section},{basename},{func},{offset},{length},{matching}")
    return "\n".join(ret)

def get_nonmatching_funcs(basedir, subcode):
    grepstr = r'#pragma GLOBAL_ASM\(.*/\K.*(?=\.s)'
    if subcode:
        try:
            funcs = set(subprocess.check_output(['grep', '-ohPR', grepstr, basedir + '/src/' + subcode]).decode('ascii').split())
        except subprocess.CalledProcessError as grepexc:
            if grepexc.returncode != 1:
                raise grepexc
            funcs = set()
    else:
        args = ['grep', '-ohPs', '-d', 'skip', grepstr]
        args.extend(glob.glob(basedir + '/src/*'))
        try:
            funcs = set(subprocess.check_output(args).decode('ascii').split())
        except subprocess.CalledProcessError as grepexc:
            if grepexc.returncode != 1:
                raise grepexc
            funcs = set()
        try:
            funcs = funcs.union(set(subprocess.check_output(['grep', '-ohPR', grepstr, basedir + '/src/done']).decode('ascii').split()))
        except subprocess.CalledProcessError as grepexc:
            if grepexc.returncode != 1:
                raise grepexc
    return funcs


def main(basedir, mapfile, section, ending, version, subcode):
    files, functions = parse_map(mapfile, section, ending)
    for filename, file_funcs in files.items():
        c_functions = parse_file(basedir, filename, file_funcs)
        for c_function in c_functions:
            functions[c_function]["language"] = "c"
    section_name = section.split("_")[-1] # .code_game -> game
    nonmatching_funcs = get_nonmatching_funcs(basedir, subcode)
    csv = generate_csv(files, functions, nonmatching_funcs, version, section_name)
    print(csv)

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Create progress csv based on map file',
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('basedir', type=str,
                        help="base directory (containing src/)")
    parser.add_argument('mapfile', type=argparse.FileType('r'),
                        help=".map file to be parsed")
    parser.add_argument('section', type=str,
                        help=".text section of the map")
    parser.add_argument('--ending', type=str,
                        help="section name that marks the end of 'section'")
    parser.add_argument('--version', type=str, default='us',
                        help="ROM version, us, eu, debug, ects")
    parser.add_argument('--subcode', type=str, default=None,
                        help="Subcode for section to get progress of")
    args = parser.parse_args()

    main(args.basedir, args.mapfile, args.section, args.ending, args.version, args.subcode)