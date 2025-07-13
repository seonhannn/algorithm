# 컴파일러 및 설정
CC = gcc
CFLAGS = -Wall -Iinclude

# 디렉토리
SRCDIR = src
INCDIR = include
BUILDDIR = build
BINDIR = bin

# 파일들
SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SOURCES))
TARGET = $(BINDIR)/myapp

# 기본 빌드 타겟
all: $(TARGET)

# 링커: 실행 파일 만들기
$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(OBJECTS) -o $(TARGET)

# 컴파일러: .c → .o
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# h 파일 생성
headers:
	python3 generate_headers.py

# 실행
run: $(TARGET)
	./$(TARGET)

# 정리
clean:
	rm -rf $(BUILDDIR) $(BINDIR)

.PHONY: all run clean
