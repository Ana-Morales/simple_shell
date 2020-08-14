# Simple shell Holberton School

This project contains the implementation of a UNIX simple line command interpreter.

## File Descriptions

- shell.c -> contains the main program for the simple_shell.
- getenv.c-> contains the function that brings the enviromen variable PATH.
- functions_prints.c -> contains the functions allowed to print to the standar output.
- check_builtin.c -> contains the function that checks if a command is a builtin function or not. 
- aux_func.c -> contains the auxiliar function to deal with string manipulation.
- holberton.h -> contains the definition of functions, structures and shared libraries.
- man_1_simple_shell -> manual page archive


## Usage

Simple_shell is an sh-compatible command language interpreter that executes commands read from the standard input.

## Example

```c
#include "holberton.h"  
/*Invocation*/
bash $ ./simple_shell
bash $
$
/* command execution interactive */
$ ls -l /usr
total 76
drwxr-xr-x   2 root root 36864 Aug 13 18:02 bin
drwxr-xr-x   2 root root  4096 Apr 10  2014 games
drwxr-xr-x  35 root root  4096 Jul 18 01:02 include
drwxr-xr-x  78 root root  4096 Aug 13 18:02 lib
drwxr-xr-x   3 root root  4096 Jun 11 03:45 lib32
drwxr-xr-x   3 root root  4096 Jun 11 03:45 libx32
drwxr-xr-x  10 root root  4096 Nov  7  2019 local
drwxr-xr-x   2 root root  4096 Jun  2 04:21 sbin
drwxr-xr-x 140 root root  4096 Aug 13 18:02 share
drwxr-xr-x   5 root root  4096 Nov  7  2019 src
```
$pwd
/home/vagrant/simple_shell

/* command execution directly from bash using pipes*/
bash $ echo "ls -l /usr" | ./simple_shell
total 76
drwxr-xr-x   2 root root 36864 Aug 13 18:02 bin
drwxr-xr-x   2 root root  4096 Apr 10  2014 games
drwxr-xr-x  35 root root  4096 Jul 18 01:02 include
drwxr-xr-x  78 root root  4096 Aug 13 18:02 lib
drwxr-xr-x   3 root root  4096 Jun 11 03:45 lib32
drwxr-xr-x   3 root root  4096 Jun 11 03:45 libx32
drwxr-xr-x  10 root root  4096 Nov  7  2019 local
drwxr-xr-x   2 root root  4096 Jun  2 04:21 sbin
drwxr-xr-x 140 root root  4096 Aug 13 18:02 share
drwxr-xr-x   5 root root  4096 Nov  7  2019 src
bash $

## Authors

- Ana Ruth Morales [Github](https://github.com/Ana-Morales)
- Sebastian Orozco [Github](https://github.com/oomsebas)