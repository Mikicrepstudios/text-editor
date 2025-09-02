PROGRAM = editr

CC := clang
CFLAGS := -Wall -Wextra -Iinclude -fsanitize=address,undefined -lncurses -ggdb
SRC := $(wildcard src/*.c)
OBJ := $(patsubst src/%.c, build/%.o, $(SRC))
BIN := bin/$(PROGRAM)

all: $(BIN) compile_commands.json format

$(BIN): $(OBJ) | bin
	$(CC) $(CFLAGS) $^ -o $@

build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

build:
	mkdir -p build

bin:
	mkdir -p bin

compile_commands.json: clean
	bear -- make $(BIN)

open:
	./bin/editr

clean:
	rm -rf build bin compile_commands.json

format:
	@find src/ -iname "*.h" -o -iname "*.c" | xargs clang-format -i

run: all
	@./$(BIN)

.PHONY:
	run clean all
