<div align="center">
    <img src="../assets/banners/book_banner.jpeg" />
    <h1>Python Fundamentals</h1>
    <h3>Welcome to the Real World of Data Engineering</h3>
    <i>This project has been created as part of the 42 curriculum by npillet.</i>
</div>

## 📚 Table of Contents
- [Description](#-description)
- [Instructions](#-instructions)
- [Knowledge](#knowledge)
    - [Pip](#pip)
    - [Poetry](#poetry)
    - [.env](#env)
- [Resources](#-resources)

## 📜 Description
This module introduces us to isolated environments, program dependencies and system variables.

## 📖 Instructions
To verify if the norm is correctly applied in the different files:
```bash
flake8
```
<br>

If there is an issue, the command will send back said issue. Otherwise, nothing will be sent back to the terminal.
<br>

To create the virtual environment:
```bash
python3 -m venv matrix_env
```
<br>

To enter the virtual environment:
```bash
source matrix_env/bin/activate
```
<br>

To execute the program, once in the corresponding file, use:
```bash
python3 <name of the program>
```
<br>

To exit a virtual environment, use the command `deactivate` in the terminal.
<br>

## Knowledge
### Pip
To install the dependencies present in requirements.txt, use this:
```bash
pip install -r requirements.txt
```

### Poetry
To install poetry, use this command:
```bash
curl -sSL https://install.python-poetry.org | python3 -
```
<br>

To create a pyproject.toml:
```bash
poetry init
```
<br>

Then to install dependencies inside pyproject.toml:
```bash
poetry install
```
<br>

The command to run any program with poetry:
```bash
poetry run python3 *.py
```

### .env
First, install dotenv dependency:
```bash
pip install python-dotenv
```
<br>

Use the .env.example in the folder to create the .env (you can copy it using `cp`) and put your own values inside to protect your confidential data.
```bash
cp .env.example .env
```
<br>

Use this to test the priority between the .env file and the console output to override some values like this:
```bash
MATRIX_MODE=production API_KEY=secret123 python3 oracle.py
```

## 📚 Resources
### Notions
- [Site module](https://www.w3schools.com/python/ref_module_site.asp)

- [Os module](https://www.w3schools.com/python/module_os.asp)

- [Virtual Environment](https://stackoverflow.com/questions/1871549/how-to-determine-if-python-is-running-inside-a-virtualenv)

- [.toml files](https://packaging.python.org/en/latest/guides/writing-pyproject-toml/)

- [DataFrame Pandas](https://www.w3schools.com/python/pandas/pandas_dataframes.asp)

- [matplotlib](https://www.w3schools.com/python/matplotlib_pyplot.asp)

- [python-dotenv](https://stackoverflow.com/questions/41546883/what-is-the-use-of-python-dotenv)

### GitHub
- [fclaval42](https://github.com/fcaval42/Python_module_08)

<br>
<hr>
<br>

<div align="center">
    <img src="../assets/banners/footer.png" />
</div>
