CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = mycat

SRCDIR = src
OBJDIR = obj

SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))

# Default target: build the executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule for compiling each .c into .o
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -rf $(OBJDIR) $(TARGET)

.PHONY: clean
