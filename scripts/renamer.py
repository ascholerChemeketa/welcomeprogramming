import os
import re
import sys
import shutil
import os.path
from pathlib import Path


def rename():
    from_part = "methods-testing"
    to_part = "functions-testing"
    for root, dirs, files in os.walk(sys.argv[1]):
        for filename in files:
            file = os.path.join(root, filename)
            file_extension = os.path.splitext(file)[1]
            if file_extension not in [".cpp", ".ptx"]:
                continue
            if from_part in file:
                new_file = file.replace(from_part, to_part)
                print(f"Renaming {file} to {new_file}")
                os.rename(file, new_file)

rename()