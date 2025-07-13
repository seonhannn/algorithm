import os
import re

SRC_DIR = "src"
INC_DIR = "include"

os.makedirs(INC_DIR, exist_ok=True)

func_pattern = re.compile(
    r'^(int|void|char|float|double)\s+(\w+)\s*\(([^)]*)\)\s*{?$'
)

for filename in os.listdir(SRC_DIR):
    if filename.endswith(".c"):
        base = filename[:-2]
        h_filename = base + ".h"
        src_path = os.path.join(SRC_DIR, filename)
        inc_path = os.path.join(INC_DIR, h_filename)

        guard = h_filename.upper().replace(".", "_")

        with open(src_path, "r") as src, open(inc_path, "w") as hdr:
            hdr.write(f"#ifndef {guard}\n")
            hdr.write(f"#define {guard}\n\n")

            lines = src.readlines()
            i = 0
            while i < len(lines):
                line = lines[i].strip()

                # 함수 선언 한 줄 또는 여러 줄에 걸쳐 있어도 인식
                if func_pattern.match(line):
                    sig = line
                    # 만약 {가 없고, 라인이 끝나지 않았다면 다음 줄 붙이기
                    while not line.endswith("{") and not line.endswith(")") and i + 1 < len(lines):
                        i += 1
                        line = lines[i].strip()
                        sig += " " + line
                    # 함수 시그니처에서 { 제거
                    sig = sig.rstrip("{").strip()
                    hdr.write(sig + ";\n")
                i += 1

            hdr.write(f"\n#endif // {guard}\n")
