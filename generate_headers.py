import os
import re

SRC_DIR = "src"
INC_DIR = "include"

os.makedirs(INC_DIR, exist_ok=True)

func_pattern = re.compile(r'^(int|void|char|float|double)\s+\w+\s*\(.*\)\s*{?$')

for root, dirs, files in os.walk(SRC_DIR):
    for filename in files:
        if filename.endswith(".c"):
            base = filename[:-2]
            src_path = os.path.join(root, filename)
            inc_path = os.path.join(INC_DIR, base + ".h")

            guard = base.upper() + "_H"

            with open(src_path, "r") as src, open(inc_path, "w") as hdr:
                hdr.write(f"#ifndef {guard}\n")
                hdr.write(f"#define {guard}\n\n")

                lines = src.readlines()
                i = 0
                while i < len(lines):
                    line = lines[i].strip()
                    if func_pattern.match(line):
                        sig = line
                        while not line.endswith("{") and not line.endswith(")") and i + 1 < len(lines):
                            i += 1
                            line = lines[i].strip()
                            sig += " " + line
                        sig = sig.rstrip("{").strip()
                        hdr.write(sig + ";\n")
                    i += 1

                hdr.write(f"\n#endif // {guard}\n")
