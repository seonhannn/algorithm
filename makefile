# 컴파일러 및 설정
CC = gcc
CFLAGS = -Wall -Iinclude

# 디렉토리
SRCDIR = src
INCDIR = include
BUILDDIR = build
BINDIR = bin

# 모든 .c 파일 전체 경로 추출
SOURCES := $(shell find $(SRCDIR) -name '*.c')

# .c 파일을 .o 파일로 변환 (src 경로를 build 경로로 바꿈)
OBJECTS := $(patsubst $(SRCDIR)/%, $(BUILDDIR)/%, $(SOURCES:.c=.o))

# 실행 파일 이름
TARGET = $(BINDIR)/myapp

# 기본 타겟
all: $(TARGET)

# 실행 파일 만들기
$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(OBJECTS) -o $(TARGET)

# 각 .c → .o 만들기 (빌드 디렉토리 구조 유지)
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# 헤더 자동 생성
headers:
	python3 generate_headers.py

# 실행
run: all
	./$(TARGET)

# 정리
clean:
	rm -rf $(BUILDDIR) $(BINDIR)

.PHONY: all run clean headers
