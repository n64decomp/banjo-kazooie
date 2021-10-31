import argparse
import os
import re
import sys
import csv
import anybadge

# Read using `mips-linux-gnu-readelf -S`
overlay_sizes = {
    'bk_boot'   : (0x5BE0 - 0x1000),
    'core1'     : 0x034b70 + 0x003080,
    'core2'     : 0x0dc600,
    'CC'        : 0x0036b0,
    'MMM'       : 0x0055f0,
    'GV'        : 0x00a7e0,
    'TTC'       : 0x005fc0,
    'MM'        : 0x0034a0,
    'BGS'       : 0x00a2a0,
    'RBB'       : 0x009c60,
    'FP'        : 0x00b600,
    'SM'        : 0x0046d0,
    'cutscenes' : 0x006f60,
    'lair'      : 0x00c8c0,
    'fight'     : 0x00af90,
    'CCW'       : 0x008760,
}

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
        incomplete_func = 0
        if overlay == 'total':
            total_byte = sum(overlay_sizes.values())
        else:
            total_byte = overlay_sizes[overlay]
        incomplete_byte = 0
        for row in csv_reader:
            if(row["version"] == version):
                total_func += 1
                if row['matching'] != 'yes':
                    incomplete_func += 1
                    incomplete_byte += int(row['length'])
        done_byte = total_byte - incomplete_byte
        done_func = total_func - incomplete_func
        percent = ((done_byte/total_byte) * 100)
        print("%s: bytes: %3.4f%% (%d/%d), nonstatic funcs: %3.4f%% (%d/%d)" % (overlay, percent, done_byte, total_byte,((done_func/total_func) *100), done_func, total_func ))
        green = min(255, round(min(1, (percent / 100) * 2) * 256))
        red = min(255, round(min(1, ((100 - percent) / 100) * 2) * 256))
        color = RGB_to_hex([red, green, 0])
        if overlay == 'total':
            badge = anybadge.Badge("Banjo-Kazooie (us.v10)", "%3.4f%%" % (percent), default_color=color)
        else:
            badge = anybadge.Badge(overlay, "%3.4f%%" % (percent), default_color=color)
        badge.write_badge('progress/progress_' + overlay + '.svg',overwrite=True)


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