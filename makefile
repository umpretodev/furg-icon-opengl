CC=g++
SOURCE=main.cpp
BIN=code
LIBRARYS=-lglut -lGLU -lGL -lm

all: clean build

# Clean builds
clean:
	@echo "Cleaning up..."
	rm -r build

# Build binary code
build:
	mkdir -p build
	$(CC) $(SOURCE) -o build/$(BIN) $(LIBRARYS)

# Run binary code
run:
	./build/$(BIN)
