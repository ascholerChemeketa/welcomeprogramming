import os
import re
import sys
import shutil
import os.path
from pathlib import Path


def move_files():
    for root, dirs, files in os.walk(sys.argv[1]):
        for filename in files:
            file = os.path.join(root, filename)
            file_extension = os.path.splitext(file)[1]
            folder = filename.split('_')[0]
            folder = folder.replace(".ptx", "")
            folder_path = os.path.join(root, folder)
            if not os.path.exists(folder_path):
                os.makedirs(folder_path)
            rest = "".join(filename.split('_')[1:])
            if rest == '':
                rest = "index.ptx"
            # print(file)
            # print(folder)
            # print(rest)
            # print(os.path.join(root, folder, rest))
            # print()
            try:
                shutil.move(file, os.path.join(root, folder, rest))
            except:
                print("Error " + file)
          

# def rename_includes():
#     for root, dirs, files in os.walk(sys.argv[1]):
#         for filename in files:
#             file = os.path.join(root, filename)
#             file_extension = os.path.splitext(file)[1]
#             print(file)
#             if ".ptx" not in filename:
#                 continue

#             with open(file, 'r') as f:
#                 data = f.readlines()

#             for i in range(len(data)):
#                 if "xi:include href=\"../programs" in data[i]:
#                     print(data[i])
                    # data[i] = data[i].replace(".include", ".include \"../")
                    # data[i] = data[i].replace("\n", "\"\n")

            # with open(file, 'w') as f:
            #     f.write(data)
            # os.rename(file, os.path.join(root, folder, rest))


#move_files()
rename_includes()