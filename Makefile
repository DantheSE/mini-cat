CC      := gcc
CFLAGS  := -Wall -Wextra -std=c99 -g

SRCDIR  := src
BUILDDIR:= build

SRCS    := $(SRCDIR)/main.c \
           $(SRCDIR)/args.c \
           $(SRCDIR)/utils.c \
           $(SRCDIR)/reader.c

HDRS    := $(SRCDIR)/args.h \
           $(SRCDIR)/utils.h \
           $(SRCDIR)/reader.h

OBJS    := $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SRCS))

TARGET  := mini-cat

.PHONY: all clean directories

all: directories $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILDDIR)/%.o: $(SRCDIR)/%.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

directories:
	@mkdir -p $(BUILDDIR)

clean:
	rm -rf $(BUILDDIR)/*.o $(TARGET)
