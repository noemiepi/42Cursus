<div align="center">
    <h1>Python Fundamentals</h1>
    <h3>Discover Pydantic Models & Validation</h3>
    <i>This project has been created as part of the 42 curriculum by npillet.</i>
</div>

## 📚 Table of Contents
- [Description](#-description)
- [Instructions](#-instructions)
- [Knowledge](#knowledge)
    - [Pydantic](#pip)
- [Resources](#-resources)

## 📜 Description
This module introduces us to the Pydantic library.

## 📖 Instructions
To verify if the norm is correctly applied in the different files:
```bash
flake8
```
<br>

If there is an issue, the command will send back said issue. Otherwise, nothing will be sent back to the terminal.

To execute the program, once in the corresponding file, use:
```bash
python3 <name of the program>
```
<br>

## Knowledge
### Pydantic
Pydantic is a data validation library. Depending on the conditions given by the coder, it will validate or not the received data.<br>
To do so, a class needs to be created. It will inherit `BaseModel`. Inside, variables will be defined and to set the conditions of validations, we use `Field()`, like in this example:
```python
<variable>: str = Field(..., <conditions>)
```
<br>

The three dots `...` indicate that there must be a given value for that variable.<br>
If it isn't required, `None` would be in that place.<br>
It's also possible to put a default value by using `default=`
<br>

For the condition, we can put:
- `min_length=<value>`
- `max_length=<value>`
- `ge=<value>`: greater than or equal to
- `le=<value>`: less than or equal to
- `gt=<value>`: greater than
- `lt=<value>`: less than
<br>

Pydantic automatically converts a type into another when it's possible.
<br>

If the model is nested, it will first handle the nested model's errors and then the model in which the nested one is.

## 📚 Resources
### Notions
- [Pydantic](https://pydantic.com.cn/en/)

- [Field](https://docs.pydantic.dev/2.6/concepts/fields/)

- [Limits with Field](https://stackoverflow.com/questions/61326020/how-can-i-set-max-string-field-length-constraint-in-pydantic)

- [model_validator](https://docs.pydantic.dev/latest/concepts/validators/#model-after-validator)

<br>
<hr>
<br>

<div align="center">
    <img src="../assets/banners/footer.png" />
</div>
