# Assignment 4: Wash - A basic file manager
This assignment is worth 100 points.

## Goals
The purpose of this assignment is to give you practice with

1. Command line arguments
2. C Struct
3. Using Makefile
4. Low-level file I/O system calls
5. Handling errors

## Problem 
Create a program that helps Dr. Messy manage his files. \
Dr. Messy needs a program to help him clean up and organize his files. 
He needs you to write a program named `wash`. 
This program processes a list of files one at a time. 
The file's names are provided to the program on the command line. 
It supports the following commands. 

- 'l' list all the files along with their inode number and size 
- 'c' cat the current file contents to standard input 
- 'd' duplicate the current file, which creates a copy of the file 
- 'r' rename the current file 
- 'u' unlink the current file, which typically deletes the file 
- 't' truncate the current file, which makes the file length zero 
- 'e' display the last 100 bytes, or fewer if fewer exist, of the current file 
- 'n' next, go to the next file name 
- 'q' quit

## C struct
You must create a struct named **file** to keep track of the list of files given by the users (an array of struct files is acceptable).\
Use [**stat**](https://man7.org/linux/man-pages/man2/lstat.2.html) system call once to get information for each file when you start your program. If a given file doesn't exist, print out a meaningful message and terminate your program.\
The struct should include at least the following: file name, inode number, and size.\
Any function that uses the struct should have the function's header in the .h file and the function's implementation in the .c  file.


## Makefile
A Makefile so that I can run `make` and not have to worry about how to compile your project.

The Makefile must have at least two targets:

    - *wash* should create the `wash` executable
    
    - *clean* should clean up the directory to remove any derivable files

## System calls
Here are the list of system calls you will need to use:

[**stat**](https://man7.org/linux/man-pages/man2/lstat.2.html)

[**open**](https://man7.org/linux/man-pages/man2/open.2.html)

[**read**](https://man7.org/linux/man-pages/man2/read.2.html)

[**write**](https://man7.org/linux/man-pages/man2/write.2.html)

[**close**](https://man7.org/linux/man-pages/man2/close.2.html)

## Errors checking
In practice, you should include full error checking for **all system calls**. For this assignment, you should at least include error checking for the **stat()** and **open()**. Use **perror()** to print out meaningful error messages.

## Getting the command from the user
***If you use scanf() to read in a character for the command, you could use getchar() right after scanf() to get rid of the trailing new line character***

```
         while(1){

                char c;

                printf("Enter a character: ");

                scanf("%c", &c);

                printf("You enter : %c\n", c);

                getchar();


        }
```

## Example Run

In the example run below, italicized  text was typed in by the user, the rest is the output by the program


$ *ls -li*  
total 40  
2174881927 -rw------- 1 hdbui hdbui   17 Feb 24 10:13 bar  
2174874670 -rw------- 1 hdbui hdbui   17 Feb 24 10:12 foo  
2175150180 -rw------- 1 hdbui hdbui   24 Feb 24 10:13 foobar  
2150560114 -rw------- 1 hdbui hdbui   13 Feb 24 10:13 hello  
$ *./wash foo bar foobar*  
file foo: command: *l*  
foo 2174874670 17  
bar 2174881927 17  
foobar 2175150180 24  
file foo: command: *c*  
This is file foo  
file foo: command: *d*  
enter destination name: *newfoo*  
file foo: command: *n*    
file bar: command: *r*    
enter new name: *newbar*    
file newbar: command: *n*
file foobar: command: *u*
file foo: command: *q*
$ *ls -li*  
total 44  
2174874670 -rw------- 1 hdbui hdbui   17 Feb 24 10:12 foo  
2150560114 -rw------- 1 hdbui hdbui   13 Feb 24 10:13 hello  
2174881927 -rw------- 1 hdbui hdbui   17 Feb 24 10:13 newbar  
2175133465 -rw------- 1 hdbui hdbui   17 Feb 24 10:20 newfoo  


## Style
You are expected to follow a consistent style. Pay particular attention to:

1. File headers: You should have a file header at the top of every file explaining the purpose and author of the file, describing input/output if any.
2. Struct implementation should be in a .h and .c file.
3. Function comments: Every function should explain its purpose, input, and return.
4. Variable names: use meaningful names in all lowercase with underscore separations between words
5. Constant names: use all uppercase
6. Your code should have appropriate whitespace and avoid overly long line lengths.
7. You should have no warnings when compiled with gcc -Wall
8. Use of git: use meaningful commit messages and commit after reasonable milestones (i.e., a function has been completed)
    * A single commit for the whole project is not a good use of git
9. Functions should do one thing and one thing only.
10. Your program should include reasonable HCI such that the user does not have to guess what they are supposed to do.
11. Your program should be silent on success (except where such silence conflicts with good HCI).


## Reflection
Write a short reflection about the programming assignment in reflection.txt:

    - Which commands were the easiest to implement? most difficult?
    - How did you go about testing this program?
    - What did you learn about interacting with files using system calls?

## Final Submission   
* To GitHub:
  * Your .h .c files and Makefile
  * Your reflection of the programming assignment in reflection.txt

***Remember to double check on github.com that your files pushed. If they don’t, you need to push them. I can only see what is on github.com, not what is only on your computer.***
