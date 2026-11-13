<div align="center">
    <h1>Python Fundamentals</h1>
    <h3>Digital Preservation in the Cyber Archives</h3>
    <i>This project has been created as part of the 42 curriculum by npillet.</i>
</div>

## 📚 Table of Contents
- [Description](#-description)
- [Instructions](#-instructions)
- [Knowledge](#knowledge)
    - [File reading](#file-reading)
    - [Error handeling](#error-handeling)
    - [R.A.I.I.](#raii)
- [Resources](#-resources)

## 📜 Description
This module introduces us to files and how to open, read, write and close them, how to secure the entire process and different error types linked to this.

## 📖 Instructions
To verify if the norm is correctly applied in the different files:
```bash
flake8
```
<br>

If there is an issue, the command will send back said issue. Otherwise, nothing will be sent back to the terminal.
<br>

To execute the program, once in the corresponding file, use:
```bash
python3 <name of the program>
```
<br>

## Knowledge
### File reading
To read or write in a file, the first step is to open it with `open()`.
```python
f = open('<file name>', '<initial of the action>')
```
<br>

This function will prepare the file for:
- Reading it with `r`
- Writing inside it with `w` (and create it beforehand if it doesn't already exist)

After this, depending on the initial, another function is needed to do the wanted action:
- `f.read()` to read the file
- `f.write()` to write in the file

In both cases, the `f` is the name of the opened file given when using the `open()` function. It can be named whatever the coder wants.

<br>

After doing what was wanted with the file, the function `close()` is used to properly close the file after usage.
A limit on how many files can be opened at once exists, therefore, it will prevent us from getting to that limit but also data loss will be avoided.

### Error handeling
Different kinds of errors dedicated to files exist, for instance:
- `FileNotFoundError`: it appears when the file wasn't found.
- `FileExistsError`: it appears when trying to write in or create a file that already exists.
- `PermissionError`: it appears when trying to access a file to which the user doesn't have the permission.

For further security, on top of the error handling, the function `with` can be used like below:
```python
with open('classified_data.txt', 'r') as file:
```
<br>

In case of an error during manipulation of the file, it will automatically close the file, preventing any kind of data loss or corruption.<br>
If there aren't any errors, then it will still automatically close the file after reading, printing or writing the content.

<br>

There are different output streams. It helps distinguish the errors from the data and therefore be able to choose to display only the standard data from the errors or both at the same time.<br>
There are:
- `stdin` is where the program is expected to read the output.
- `stdout` is where it is expected to write the normal output.
- `stderr` is where it is expected to write error messages.

<br>

### R.A.I.I.
Resource Acquisition Is Initialization (RAII) means that an object's creation and destruction are tied to a resource being acquired and released.<br>
It is used to organize resource allocation lifetime and can help reduce code complexity, improve readability and make it more difficult to break the code when functions become longer.

## 📚 Resources
### Notions
#### Functions
- [read()](https://www.w3schools.com/python/ref_file_read.asp)

- [write()](https://www.w3schools.com/python/ref_file_write.asp)

- [with](https://www.geeksforgeeks.org/python/with-statement-in-python)

#### Different ouput
- [stdin, stdout and stderr](https://certiquizz.com/fr/cours/programmation/python/python-pour-developpeurs-le-guide-complet-et-avance/redirection-des-entrees-sorties)

- [stdout vs stderr](https://retrocomputing.stackexchange.com/questions/11499/what-was-the-point-of-separating-stdout-and-stderr)

#### Concept
- [RAII](https://creatronix.de/raii-in-c-and-python-for-custom-types/#RAII_for_custom_types_in_Python)

### Github:
- [Overtek](https://github.com/Overtekk/Python-Module-00-10/blob/main/Python%20Module%2004/ex4/create_files.py)

<br>
<hr>
<br>

<div align="center">
    <img src="../assets/banners/footer.png" />
</div>
