import os
import re
import sys
import shutil


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
            programBody = []
            inProgram = False
            while i < len(lines):
                line = lines[i]
                if 'section xml' in line:
                    groups = re.search(r'xml:id=\"([\w_-]+)\"', line)
                    curSection = groups.group(1)
                    print("======================")
                    print(curSection)
                    curCounter = 1
                if '<program' in line:
                    programBody = []
                    inProgram = True
                elif '</program' in line:
                    # print("".join(programBody).strip())
                    inProgram = False
                    with open(os.path.join("programs", curSection + "-" + str(curCounter) + ".java"), 'w+') as p:
                        p.write("".join(programBody).strip())
                    curCounter += 1
                elif inProgram:
                    programBody.append(line)

                i += 1
        # print(text)
        # with open(file, 'w') as f:
        #     f.write(text)

