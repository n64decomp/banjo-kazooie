import argparse
import os
import re
import sys
import csv

def main(csv_name, version):
    with open(csv_name, mode='r') as csv_file:
        csv_reader = csv.DictReader(csv_file)
        line_count = 0
        total_func = 0
        done_func = 0
        total_byte = 0
        done_byte = 0
        for row in csv_reader:
            if(row["version"] == version):
                total_func += 1
                total_byte += int(row['length'])
                if row['language'] == 'c':
                    done_func += 1
                    done_byte += int(row['length'])
        print("Progress: bytes: %3.4f%% (%d/%d), funcs: %3.4f%% (%d/%d)" % ((done_byte/total_byte * 100), done_byte, total_byte,((done_func/total_func) *100), done_func, total_func ))

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Create progress csv based on map file',
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('csv_name', type=str,
                        help="csv to read")
    parser.add_argument('ver_str', type=str,
                        help="version")
    args = parser.parse_args()

    main(args.csv_name, args.ver_str)