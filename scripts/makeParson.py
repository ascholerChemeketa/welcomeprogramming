import os
import re
import sys
import shutil

partial_order = False
if len(sys.argv) != 1:
    if sys.argv[1] == "p":
        partial_order = True

lines = []
with open("parson.txt", 'r') as f:
    lines = f.readlines()

blockStart = "<block>\n" if not partial_order else "<block name=\"\" depends=\"\">\n"

with open("parsons-out.txt", 'w') as f:
    f.write("<blocks>\n")
    for line in lines:
        f.write("  " + blockStart)
        f.write("    <cline><![CDATA[")
        f.write(line.rstrip())
        f.write("]]></cline>\n")
        f.write("  </block>\n")
    f.write("\n")
    f.write("  " + blockStart)
    f.write("    <cline>\n")
    f.write("    </cline>\n")
    f.write("  </block>\n")
    f.write("  " + blockStart)
    f.write("    <choice>\n")
    f.write("      <cline correct=\"yes\">\n")
    f.write("      </cline>\n")
    f.write("    </choice>\n")
    f.write("    <choice>\n")
    f.write("      <cline>\n")
    f.write("      </cline>\n")
    f.write("    </choice>\n")
    f.write("  </block>\n")
    f.write("</blocks>\n")

