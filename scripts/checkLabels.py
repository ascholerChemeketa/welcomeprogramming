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

def shorten(element_name):
    if element_name in ['activity']:
        return element_name[:3]
    
    return element_name[:2]

def verifyExerciseLabels(write=False):
    result = True
    for root, dirs, files in os.walk(sys.argv[1]):
        for filename in files:
            file = os.path.join(root, filename)
            if ".ptx" not in file:
                continue
            outlines = []
            with open(file, 'r') as f:
                lines = f.readlines()
                curSection = ""
                curCounter = 1
                i = 0
                while i < len(lines):
                    line = lines[i]
                    if ('<exercises' in line or '<section' in line or '<chapter' in line):
                        element_content, end_line = extractElement(lines, i)
                        i = end_line - 1
                        line = element_content
                        xmlid = re.search(r'xml:id=\"([\w_-]+)\"', line)
                        if xmlid:
                            curSection = xmlid.group(1)
                            curCounter = 1

                    for ex_type in ['exercise']:
                        has_ex = re.search(f'<{ex_type}[ >]', line)
                        if has_ex:
                            element_content, end_line = extractElement(lines, i)
                            # print(element_content)
                            cur_idx = re.search(r'xml:id=\"([^"]+)\"', line)
                            cur_label = re.search(r'label=\"([^"]+)\"', line)
                            new_label = f"{curSection}-{shorten(ex_type)}-{curCounter}"
                            if cur_idx:
                                print(" Has xml:id{} {} {} {}".format(ex_type, file, curSection, curCounter))
                                print(" label is {}".format(cur_label.group(1) if cur_label else "None"))
                                print(" new label is {}".format(new_label))
                            if cur_label:
                                element_content = re.sub(r'label=\"[^"]+\"', f'label="{new_label}"', element_content)
                            else:
                                element_content = element_content.replace(f'<{ex_type}', f'<{ex_type} label="{new_label}"')
                            i = end_line - 1
                            line = element_content
                            curCounter += 1

                    outlines.append(line)
                    i += 1

            if write:
                body = "".join(outlines)
                Path(file).write_text(body)
    return result


def verifyProgramIds(write=False):
    result = True
    for root, dirs, files in os.walk(sys.argv[1]):
        for filename in files:
            file = os.path.join(root, filename)
            if ".ptx" not in file:
                continue
            outlines = []
            with open(file, 'r') as f:
                lines = f.readlines()
                curSection = ""
                curCounter = 1
                i = 0
                in_exercise = False
                while i < len(lines):
                    line = lines[i]
                    if ('<exercises' in line or '<section' in line or '<chapter' in line):
                        element_content, end_line = extractElement(lines, i)
                        i = end_line - 1
                        line = element_content
                        xmlid = re.search(r'xml:id=\"([\w_-]+)\"', line)
                        if xmlid:
                            curSection = xmlid.group(1)
                            curCounter = 1

                    for ex_type in ['exercise']:
                        has_ex = re.search(f'<{ex_type}[ >]', line)
                        if has_ex:
                            in_exercise = True
                            element_content, end_line = extractElement(lines, i)
                            cur_id = re.search(r'xml:id=\"([^"]+)\"', line)
                            if cur_id:
                                print(" Ex has xml:id {} {} {} {}".format(ex_type, file, curSection, curCounter))
                                print(" Ex has xml:id {}".format(element_content))
                            cur_label = re.search(r'label=\"([^"]+)\"', line)
                            new_id = f"{curSection}-{shorten(ex_type)}-{curCounter}"
                            i = end_line - 1
                            line = element_content
                      
                        has_end_ex = re.search(f'</{ex_type}>', line)
                        if has_end_ex and in_exercise:
                            in_exercise = False

                    for prog_type in ['program']:
                        has_prog = re.search(f'<{prog_type}[ >]', line)
                        if has_prog:
                            element_content, end_line = extractElement(lines, i)
                            cur_id = re.search(r'xml:id=\"([^"]+)\"', element_content)
                            cur_label = re.search(r'label=\"([^"]+)\"', element_content)
                            is_interactive = re.search(r'interactive=', element_content)
                            if cur_id and cur_label:
                                # leave alone
                                pass
                                #print(" Has both {} {} {} {}".format(prog_type, file, curSection, curCounter))
                            else:
                                if cur_id:
                                    # nuke all ids wihtout labels
                                    cur_id = cur_id.group(1)
                                    element_content = element_content.replace(f' xml:id="{cur_id}"', '')
                                if cur_label:
                                    cur_label = cur_label.group(1)
                                    element_content = element_content.replace(f' label="{cur_label}"', '')
                                if is_interactive and not in_exercise:
                                    new_label = f"{curSection}-program-{curCounter}"
                                    element_content = element_content.replace(f'<program', f'<program label="{new_label}"')
                                    curCounter += 1
                            
                            i = end_line - 1
                            line = element_content

                    outlines.append(line)
                    i += 1

            if write:
                body = "".join(outlines)
                Path(file).write_text(body)
    return result


verifyExerciseLabels(write=True)
verifyProgramIds(write=False)

# verifyExerciseLabels(write=True)
# verifyProgramIds(write=True)