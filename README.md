# Overview
This is a UNIX command line interpreter based on the simple shell(sh). It reads user input from the command line, interprets it, and executes the commands.

# Usage
After compiling the program, one may use it in interactive or non-interactive mode.
## Interactive Mode
* From the command line, enter "./" , followed by the executable name (ex: "./a.out").
* After the "$ " prompt appears, type in a command to be executed. Repeat as desired.
* To exit the program, you can type in either crtl + d or "exit".
## Non-Interactive Mode
```
\ echo "pwd" | ./a.out
```
## simple_shell Built-ins
| COMMAND | DESCRIPTION |
| ---- | ----------- |
| env |  prints the environment |
| exit | exits out of our shell program |
## Example Usage
* ``` ls ``` lists the contents of a directory
* ``` pwd ``` prints the working directory
* ``` cd ``` changes the working directory to another
## Files
| FILE | DESCRIPTION |
| ---- | ----------- |
| ```execute.c``` |        |
| ```main.c``` |           |
| ```main.h``` |           |
| ```_printer.c``` |       |
| ```_string.c``` |        |
| ```_strtok.c```|         |
| ```built_ins.c```|       |
| ```README.md```|         |
## About
All our files are compiled on Ubuntu 20.04 LTS using ```gcc```, using the options ```-Wall -Werror -Wextra -pedantic -std=gnu89```
