<div align="center">
    <h1>get_next_line</h1>
    <h3>Reading a line from a file descriptor is way too tedious</h3>
    <i>This project has been created as part of the 42 curriculum by npillet.</i>
</div>

## Table of Contents
- [Description](#description)
- [Instructions](#instructions)
- [Explanation and justification](#explanation-and-justification)
- [Resources](#resources)


## Description
The goal of this project is to create a program that reads a text file line by line, one at a time, from a file descriptor. There's no size limit to the file length.<br>
In this project, the concept of static variables will be used.

As a bonus, we can make the program able to read multiple file descriptors at the same time.<br>
For example, the code reads the first line from the first file, then moves to the first line from a second file and comes back to the first file to read the second line.<br>
It will continue that way without losing track to where it stops reading until all the files are done being read. All of that must be achieved using one static variable throughout the code.

## Instructions
A main file and a few text files will be provided during the evaluation process to test the code.
To compile this code, this command must be used:
```bash
cc -Wall -Werror -Wextra <files>.c
```
It must also work with the following flag:
```bash
-D BUFFER_SIZE=42
```
Here, 42 is a placeholder number that can be replaced by any positive number possible.
For the execution of the program, once compiled, the following is typed on the terminal:
```bash
./a.out
```
If the program is compiled for a stdin usage, it will wait for an input. Once a key or multiple of them are pressed, the enter key should be pressed and the program will return that input. To kill the process, press ctrl + d at the same time.

## Explanation and justification
For this project, I chose to approach the problem using strings.
To do so, we will move BUFFER_SIZE characters in the text file to read and copy in a string until the code notices either a '\n' or '\0' which signifies a new line in the first case or the end of the file in the other.

For the bonus, I took the code I did for the mandatory part and modified only the static variable, making it a 2D array. That way, I could take care of the multiple file descriptors I could use to read multiple files simultaneously.

## Resources
### Notions
- [Static variables](https://www.codequoi.com/variables-locales-globales-statiques-en-c/)

- [First approach](https://youtu.be/-Mt2FdJjVno)

<br>
<hr>
<br>

<div align="center">
    <img src="assets/footer.png" />
</div>
