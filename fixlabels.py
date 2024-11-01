import os
import re
import shutil

def makeLabel(name):
    name = name.lower()
    name = name.replace("and ", "")
    name = name.replace("the ", "")
    name = name.replace("in ", "")
    name = name.replace("of ", "")
    name = name.replace("an ", "")
    name = re.sub(r"\s{2,}", " ", name)
    name = re.sub(r"[^\w\s]+", "", name)
    name = name.replace(" ", "-")
    return name


for item in os.listdir('.'):
    if os.path.isfile(os.path.join(".", item)):
        file = os.path.join(".", item)
        if ".tex" not in file:
            continue
        if not (re.search(r'ch\d', file) or re.search(r'app\w', file)):
            continue
        print(file)
        shutil.copy2(file, os.path.join("backups", file))
        outLines = []
        with open(file, 'r') as f:
            lines = f.readlines()
            curChapter = ""
            i = 0
            while i < len(lines):
                line = lines[i]
                outLines.append(line)
                if re.search(r'chapter\*?{', line):
                    title = re.search(r'chapter\*?{(.+?)}', line).group(1)
                    print(" chapter " + title)
                    label = makeLabel(title)
                    curChapter = label
                    print("   label " + label)
                    outLines.append("\\label{" + label + "}\n")
                    if re.search(r'label{', lines[i + 1]):
                        print(" HAS LABEL")
                        i += 1
                if re.search(r'section\*?{', line):
                    title = re.search(r'section\*?{(.+?)}', line).group(1)
                    print(" section " + title)
                    label = curChapter + "_" + makeLabel(title)
                    print("   label " + label)
                    outLines.append("\\label{" + label + "}\n")
                    if re.search(r'label{', lines[i + 1]):
                        i += 1
                i += 1
        text = "".join(outLines)
        # print(text)
        with open(file, 'w') as f:
            f.write(text)

