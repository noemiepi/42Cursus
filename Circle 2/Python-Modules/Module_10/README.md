<div align="center">
    <h1>Python Fundamentals</h1>
    <h3>Master the Ancient Arts of Functional Programming</h3>
    <i>This project has been created as part of the 42 curriculum by npillet.</i>
</div>

## 📚 Table of Contents
- [Description](#-description)
- [Instructions](#-instructions)
- [Knowledge](#knowledge)
    - [Lambda](#lambda)
    - [First-Class Citizen](#first-class-citizen)
    - [Wrapper](#wrapper)
    - [Functools](#functools)
    - [Decorators](#decorators)
- [Resources](#-resources)

## 📜 Description
This module introduces us to Lambda Codex, higher-order functions, decorators and lexical scoping.

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
### Lambda
Lambda expressions can make code more concise by taking any number of arguments.<br>
It can be used when an anonymous function is needed for a short period of time.

### First-Class Citizen
Functions are first-class citizens in Python, meaning they can be passed around, stored in variables, and transformed just like any other data.<br>
These functions can be used as parameters in other functions.
<br>

The function callable() checks if an object is callable, meaning it can be called like a function.

### Wrapper
Closures enable functions to "remember" their creation environment by using non-local variables. With it, we store the new data to "remember" inside.<br>
Lexical scoping in functional programming isolates a functionality and uses it anytime it is needed throughout the program.<br>
A global variable will be remembered throughout the file while a nonlocal is only remembered inside the function it's used in.

### Functools
`functools.reduce` can greatly reduce the number of lines in the code as you can reduce a series of operations into one line in some cases.
<br>

`lru_cache` makes the action faster and decreases the load on computing resources.

### Decorators
A static method, defined by this `@staticmethod` on top of the function, has to be used in every child of the parent class unlike any regular instance methods.

## 📚 Resources
### Notions
- [Python Lambda](https://www.w3schools.com/python/python_lambda.asp)

- [Using lambda](https://www.geeksforgeeks.org/python/ways-sort-list-dictionaries-values-python-using-lambda-function/)

- [kwargs and args](https://www.golinuxcloud.com/python-kwargs-args-examples/)

- [Wrappers](https://www.geeksforgeeks.org/python/function-wrappers-in-python/)

- [Non-local](https://www.geeksforgeeks.org/python/python-nonlocal-keyword/)

- [Functools](https://www.geeksforgeeks.org/python/functools-module-in-python/)

### GitHub
- [shadox254](https://github.com/shadox254/Module-Python/tree/main/Module-10)

- [sosanche](https://github.com/sorayasanchezz/Python_Module10/tree/main)

- [anacharp](https://github.com/naha7777/Python_modules/tree/main/python_module_10)

<br>
<hr>
<br>

<div align="center">
    <img src="../assets/banners/footer.png" />
</div>
