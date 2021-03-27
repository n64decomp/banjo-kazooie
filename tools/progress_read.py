import argparse
import os
import re
import sys
import csv
import anybadge

def RGB_to_hex(RGB):
    ''' [255,255,255] -> "#FFFFFF" '''
    # Components need to be integers for hex to make sense
    RGB = [int(x) for x in RGB]
    return "#"+"".join(["0{0:x}".format(v) if v < 16 else
                        "{0:x}".format(v) for v in RGB])

def main(csv_name, version, overlay):
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
        percent = ((done_byte/total_byte) * 100)
        print("bytes: %3.4f%% (%d/%d), funcs: %3.4f%% (%d/%d)" % (percent, done_byte, total_byte,((done_func/total_func) *100), done_func, total_func ))
        green = min(255, round(min(1, (percent / 100) * 2) * 256))
        red = min(255, round(min(1, ((100 - percent) / 100) * 2) * 256))
        color = RGB_to_hex([red, green, 0])
        if overlay == 'total':
            badge = anybadge.Badge("Banjo-Kazooie (us.v10)", "%3.4f%%" % (percent), default_color=color)
        else:
            badge = anybadge.Badge(overlay, "%3.4f%%" % (percent), default_color=color)
        badge.write_badge('progress_' + overlay + '.svg',overwrite=True)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Create progress csv based on map file',
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('csv_name', type=str,
                        help="csv to read")
    parser.add_argument('ver_str', type=str,
                        help="version")
    parser.add_argument('overlay', type=str,
                        help="overlay name")
    args = parser.parse_args()

    main(args.csv_name, args.ver_str, args.overlay)