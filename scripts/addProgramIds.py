import os
import re
import sys
import shutil
import os.path
from pathlib import Path


def verifyPrograms():
    result = True
    for root, dirs, files in os.walk(sys.argv[1]):
        for filename in files:
            file = os.path.join(root, filename)
            if ".ptx" not in file:
                continue
            with open(file, 'r') as f:
                lines = f.readlines()
                curSection = ""
                curCounter = 1
                i = 0
                while i < len(lines):
                    line = lines[i]
                    if ('section' in line or 'chapter' in line) and 'xml:id' in line:
                        groups = re.search(r'xml:id=\"([\w_-]+)\"', line)
                        curSection = groups.group(1)
                        # print("======================")
                        # print(curSection)
                        curCounter = 1
                    if '<program' in line:
                        programBody = []
                        filename = f"{root}/../programs/{curSection}-{curCounter}.cpp"
                        if not os.path.isfile(filename):
                            print(file)
                            print(root)
                            print(filename)
                            result =  False
                        curCounter += 1
                    i += 1
    return result
            # print(text)
            # with open(file, 'w') as f:
            #     f.write(text)

def insertIDs():
    for root, dirs, files in os.walk(sys.argv[1]):
        for filename in files:
            file = os.path.join(root, filename)
            if ".ptx" not in file:
                continue
            outlines = []
            foundCount = 0
            with open(file, 'r') as f:
                lines = f.readlines()
                curSection = ""
                curCounter = 1
                i = 0
                inProgram = False
                while i < len(lines):
                    line = lines[i]
                    if ('section' in line or 'chapter' in line) and 'xml:id' in line:
                        groups = re.search(r'xml:id=\"([\w_-]+)\"', line)
                        curSection = groups.group(1)
                        curCounter = 1
                        line = line.replace(">", ' xmlns:xi="http://www.w3.org/2001/XInclude">')
                        outlines.append(line)
                    elif '<program>' in line:
                        id = f"{curSection}-{curCounter}"
                        filename = f"{root}/../programs/{curSection}-{curCounter}.cpp"
                        programBody = Path(filename).read_text()
                        activecode = ""
                        if " main(" in programBody:
                            activecode = ' interactive="activecode"'
                        replace = f'<program xml:id="{id}"{activecode}>'
                        line = line.replace('<program>', replace)
                        print(f"Replaced {line} with {replace}")
                        curCounter += 1
                        outlines.append(line)
                        outlines.append(f'<xi:include href="../programs/{id}.cpp" parse="text"/>\n')
                        inProgram = True
                        foundCount += 1
                    elif '</program>' in line:
                        inProgram = False
                        outlines.append(line)
                    elif inProgram:
                        pass
                    else:
                        outlines.append(line)
                    i += 1

            body = "".join(outlines)
            Path(file).write_text(body)


OK = verifyPrograms()
if OK:
    print("All programs have a match.")
    insertIDs()