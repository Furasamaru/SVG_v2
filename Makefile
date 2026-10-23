TARGET = bin/main
FLAGS = -std=c99 -Wall -Werror -Wextra -fstack-protector
CC = gcc

# Trouve automatiquement tous les fichiers .c du projet (Core, application, infrastructure, front)
SRCS = $(shell find core application infrastructure front -name "*.c")

build:
	@mkdir -p bin
	$(CC) $(SRCS) -o $(TARGET) $(FLAGS)
	@echo "Good"

run: build
	./$(TARGET)

clean:
	rm -rf bin