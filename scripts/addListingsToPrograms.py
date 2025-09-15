import os
import re
import sys
import shutil
import os.path
from pathlib import Path

def extractElement(lines, start_line, element):
    element_lines = []
    in_element = True
    i = start_line
    end_tag = f"</{element}>"
    while i < len(lines) and in_element:
        line = lines[i]
        if end_tag in line:
            in_element = False
        element_lines.append(line)
        i += 1
    return ''.join(element_lines), i

def shorten(element_name):
    if element_name in ['activity']:
        return element_name[:3]
    
    return element_name[:2]


def addListingWrappers(write=False):
    result = True
    for root, dirs, files in os.walk(sys.argv[1]):
        for filename in files:
            file = os.path.join(root, filename)
            if ".ptx" not in file:
                continue
            outlines = []
            with open(file, 'r') as f:
                lines = f.readlines()
                curCounter = 1
                i = 0
                in_exercise = False
                in_listing = False
                print(f"{file}...")
                while i < len(lines):
                    line = lines[i]
                    for ex_type in ['exercise', 'activity']:
                        has_ex = re.search(f'<{ex_type}[ >]', line)
                        if has_ex:
                            in_exercise = True
                        has_end_ex = re.search(f'</{ex_type}>', line)
                        if has_end_ex and in_exercise:
                            in_exercise = False

                    for list_type in ['listing']:
                        has_list = re.search(f'<{list_type}[ >]', line)
                        if has_list:
                            in_listing = True
                        has_end_list = re.search(f'</{list_type}>', line)
                        if has_end_list and in_listing:
                            in_listing = False

                    has_prog = re.search(f'<program[ >]', line)
                    if has_prog:
                        element_content, end_line = extractElement(lines, i, "program")
                        length = end_line - i -2
                        i = end_line
                        is_interactive = 'interactive=' in element_content
                        if has_prog and (is_interactive or length >= 5) and not in_listing and not in_exercise:
                            print(f"Adding listing wrapper in {file} at line {i+1}: {line.strip()}")
                            if length >= 5:
                                print(f"  (***********{length}*************)")
                            starting_spaces = re.search(r'^\s*', element_content).group(0)
                            outlines.append(f"{starting_spaces}<listing>\n")
                            outlines.append(element_content)
                            outlines.append(f"{starting_spaces}</listing>\n")
                        else:
                            outlines.append(element_content)
                    else:
                        outlines.append(line)
                        i += 1

            if write:
                body = "".join(outlines)
                Path(file).write_text(body)
    return result


#addListingWrappers(write=False)
addListingWrappers(write=True)