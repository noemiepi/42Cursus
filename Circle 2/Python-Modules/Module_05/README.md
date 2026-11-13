<div align="center">
    <h1>Python Fundamentals</h1>
    <h3>Polymorphic Data Streams in the Digital Matrix</h3>
    <i>This project has been created as part of the 42 curriculum by npillet.</i>
</div>

## 📚 Table of Contents
- [Description](#-description)
- [Instructions](#-instructions)
- [Knowledge](#knowledge)
    - [Abstract Class I](#abstract-class-i)
    - [Polymorphism & Overriding](#polymorphism--overriding)
- [Resources](#-resources)

## 📜 Description
This module introduces us to abstract classes and how they work.

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
### Abstract Class I
An abstract class is a class that cannot be instantiated on its own and is designed to be a blueprint for other classes. They allow us to define methods that must be implemented by subclasses.<br>
We can use them when we want to:
- Define a common interface for all subclasses
- Enforce implementation of certain methods in child classes
- Provide a shared functionality while still requiring subclasses to implement specific behavior
<br>

Creating an abstract class follows the same process as a regular class, except that it inherits the `ABC` class which is imported from the abstract library, like this:
```python
from abc import ABC


class ClassName(ABC):
```
<br>

Using abstract classes can help with:
- Designing scalable software systems
- Machine Learning
- Libraries
- Database Access
- Graphics Engines

### Polymorphism & Overriding
Method overriding occurs when a subclass defines a method with the same name, same parameters, and same return type as a method in its superclass.<br>
When you call this method on an instance of the subclass, the subclass version is executed instead of the superclass version.<br>
Because of this, the code will be clearer to read and by creating a base method, implementing it on a new subclass will be easier.
<br>

There's also polymorphism, which is similar to overriding yet there's still a difference.<br>
Method overriding happens when you call a method in the subclass with the same signature as the one in the superclass.<br>
Polymorphism, on the other hand, happens when you are not sure of the object's type at runtime, the behaviors method may differ depending on this.<br>
Overriding is a type of polymorphism.
<br>

By allowing functions and classes to operate on objects of different types with shared interfaces the combination of method overriding and subtype polymorphism enables building scalable and maintainable data processing systems.

## 📚 Resources
### Notions
- [Abstract Classes](https://www.geeksforgeeks.org/python/abstract-classes-in-python/)

- [Overriding](https://algomaster.io/learn/python/method-overriding)

- [Logging Levels](http://docs.python.org/3/library/logging.html#logging-levels)

- [Protocol](https://dev.to/shameerchagani/what-is-a-protocol-in-python-3fl1)

- [Polymorphism](https://www.acte.in/what-is-polymorphism-in-python#Real)

### GitHub:
- [shadox254](https://github.com/shadox254/Module-Python/tree/main/Module-05)

<br>
<hr>
<br>

<div align="center">
    <img src="../assets/banners/footer.png" />
</div>