import argparse
import os
import re
import sys
import subprocess
import glob

def get_functions(elffile, section, ending=None):
    try:
        result = subprocess.run(['objdump', '-x', elffile], stdout=subprocess.PIPE)
        nm_lines = result.stdout.decode().split("\n")
    except:
        sys.stderr.write(f"Error: Could not run objdump on {elffile} - make sure that the project is built")
        sys.exit(1)

    functions = {}

    for line in nm_lines:
        if f"g     F {section}" in line:
            components = line.split()
            size = int(components[4], 16)
            name = components[5]
            functions[name] = {"function": name, "length": size}

    return functions

def generate_csv(functions, nonmatching_funcs, version, section, subcode):
    ret = []
    ret.append("version,section,function,length,matching")
    for func in functions:
        length = functions[func]["length"]
        if length > 0:
            matching = "no" if func in nonmatching_funcs else "yes"
            # Strip the boot_ prefix off symbols in bk_boot
            func_name = func if subcode else func[5:]
            ret.append(f"{version},{section},{func_name},{length},{matching}")
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


def main(basedir, elffile, section, ending, version, subcode):
    functions = get_functions(elffile, section, ending)
    section_name = section.split("_")[-1] # .code_game -> game
    nonmatching_funcs = get_nonmatching_funcs(basedir, subcode)
    csv = generate_csv(functions, nonmatching_funcs, version, section_name, subcode)
    print(csv)

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Create progress csv based on map file',
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('basedir', type=str,
                        help="base directory (containing src/)")
    parser.add_argument('elffile', type=str,
                        help=".elf file to be read")
    parser.add_argument('section', type=str,
                        help=".text section of the map")
    parser.add_argument('--ending', type=str,
                        help="section name that marks the end of 'section'")
    parser.add_argument('--version', type=str, default='us',
                        help="ROM version, us, eu, debug, ects")
    parser.add_argument('--subcode', type=str, default=None,
                        help="Subcode for section to get progress of")
    args = parser.parse_args()

    main(args.basedir, args.elffile, args.section, args.ending, args.version, args.subcode)