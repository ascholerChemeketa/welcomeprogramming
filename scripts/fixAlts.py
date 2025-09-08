import os
import re
import sys
import shutil
import os.path
from pathlib import Path

def extractElement(lines, start_line):
    element_lines = []
    in_element = True
    i = start_line
    end_tag = f">"
    while i < len(lines) and in_element:
        line = lines[i]
        if end_tag in line:
            in_element = False
        element_lines.append(line)
        i += 1
    return ''.join(element_lines), i

def fixImageAlts(write=False):
    result = True
    for root, dirs, files in os.walk(sys.argv[1]):
        for filename in files:
            file = os.path.join(root, filename)
            print(f"Processing file: {file}")
            if ".ptx" not in file:
                continue
            outlines = []
            with open(file, 'r') as f:
                lines = f.readlines()
                curSection = ""
                i = 0
                while i < len(lines):
                    line = lines[i]
                    if ('<image'):
                        element_content, end_line = extractElement(lines, i)
                        i = end_line - 1
                        line = element_content
                        spaceMatch = re.search(r'(\s*)<image', line)
                        altMatch = re.search(r'alt=\"([^"]*)\"', line)
                        if altMatch:
                            altText = altMatch.group(1)
                            print(" Has alt {} {}".format(altMatch.group(0), altText))
                            is_self_closing = re.search(r'/>', line)
                            if is_self_closing:
                                element_content = element_content.replace('/>', '>')
                                element_content = element_content.replace(altMatch.group(0), '')
                                element_content = element_content + f'{spaceMatch.group(1)}  <shortdescription>{altText}</shortdescription>\n'
                                element_content = element_content + f'{spaceMatch.group(1)}</image>\n'
                                print("  New element content: {}".format(element_content))
                                line = element_content
                            else:
                                element_content = element_content.replace(altMatch.group(0), '')
                                element_content = element_content + f'{spaceMatch.group(1)}  <shortdescription>{altText}</shortdescription>\n'
                                print("  New element content: {}".format(element_content))
                                line = element_content

                    outlines.append(line)
                    i += 1

            if write:
                body = "".join(outlines)
                Path(file).write_text(body)
    return result


fixImageAlts(write=True)
# fixImageAlts(write=True)
