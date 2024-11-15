CC=g++
SOURCE=main.cpp
BIN=code
LIBRARYS=-lglut -lGLU -lGL -lm

all: clean compile

clean:
	@echo "Cleaning up..."
	rm -f ${BIN}

build:
	mkdir build && $(CC) $(SOURCE) -o build/$(BIN) $(LIBRARYS)

run:
	./build/$(BIN)
