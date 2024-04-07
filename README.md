# my_ls: Custom Implementation of the ls Command

The `my_ls` project is a re-creation of the Unix `ls` command, a fundamental part of the Unix System Programming (B-PSU-100) coursework. This custom version is designed to mimic the essential functionalities of the original `ls` command, including various flags for detailed, recursive, and sorted listings of directory contents.

## Features

- **Basic Listing:** Like the original `ls` command, `my_ls` lists the contents of directories.
- **Support for `-l`, `-a`, `-R`, `-d`, `-r`, and `-t` flags:** 
  - `-l` for detailed listings,
  - `-a` to include hidden files,
  - `-d` to list directories themselves, not their contents,
  - `-r` to reverse the order of the sort,
  - `-t` to sort by modification time, newest first.
- **File and Directory Selection:** It's possible to specify files or directories to list, beyond just the current working directory.
- **Bonus Features:** Column formatting without `-l`, sorting, and coloring of output. Additional flags `-uFgf` as an extended feature.

## Getting Started

### Prerequisites

- A Unix-like operating system
- GCC or any standard C compiler
- Basic knowledge of terminal and Unix/Linux commands

### Compilation

This project comes with a Makefile for easy compilation. To compile, just run the following command in the root directory of the project:

```bash
make
```

## Usage
To use my_ls, you can simply call the executable followed by any flags and directories or files you wish to list. For example:

```bash
./my_ls -l
```
Or to list the contents of /dev and /usr/sbin directories with detailed information:

```bash
./my_ls -l /dev /usr/sbin
```
Flags can be combined, e.g., -lt for a detailed listing sorted by modification time.

## Authorized Functions
This project limits its use to specific system calls to mirror the constraints found in Unix system programming. These include:

- opendir, readdir, closedir, stat, lstat, write, getpwuid, getgrgid, time, ctime, readlink, malloc, free, perror, strerror, exit
