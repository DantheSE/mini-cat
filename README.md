## mini-cat

Project Overview
mini-cat is a small command‑line program that reads a file and writes its content to the terminal. It uses only raw POSIX system calls (`open`, `read`, `write`, `close`) and supports optional line numbering and a binary flag.

Features

* Read and write using low‑level syscalls
* Optional `-n` flag to add line numbers
* Optional `-b` or `--binary` flag for binary mode
* Error messages for bad arguments or file errors

Usage:
mini-cat [-n] [-b|--binary] <filename>

* `-n`: number each line
* `-b`/`--binary`: treat file as binary

Building

1. `make` to compile
2. `./mini-cat` to run

Project Structure

* `src/`

  * `main.c`: handles CLI and calls modules
  * `args.c`/`args.h`: argument parsing
  * `reader.c`/`reader.h`: file reading and line numbering
  * `utils.c`/`utils.h`: helper functions (`numToString`)
* `Makefile`: automates build

Notes

* No standard C library I/O is used
* All writes handle partial‑write safety

NB:Docs written with help from chatgpt, just couldn't bring myself to do it :)
