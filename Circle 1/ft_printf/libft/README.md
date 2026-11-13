<div align="center">
    <h1>Libft</h1>
    <h3>Your very first own library</h3>
    <i>This project has been created as part of the 42 curriculum by npillet.</i>
</div>

## Table of Contents
- [Description](#description)
- [Instructions](#instructions)
- [Functions in the Library](#functions-in-the-library)
    - [Checkers & Converters](#checkers--converters)
    - [String](#string)
    - [Memory](#memory)
    - [File-descriptor](#file-descriptor)
    - [Linked-list (bonuses)](#linked-list-bonuses)

## Description
A library is group of functions can be imported into a code so the user can use them freely. When one is made in C, a .h file reuniting is created.

For this project, we need to create a C library containing recoded fucntions from the original standard C library that will be used for some future projects.<br>
As a bonus, we can code linked-list functions. 

## Instructions
To compile this code, this command must be used:
```bash
make
```
To add the bonuses:
```bash
make bonus
```
There are two ways to test the functions:
- either one by one with:
```bash
cc -Wall -Werror -Wextra <function_name>.c libft.a
```
- or using a main testing each of them at the same time:
```bash
cc -Wall -Werror -Wextra libft_main.c libft.a
```

## Functions in the Library

### Checkers & Converters:

| Function | Description | Function | Description |
| :---: | --- | :---: | --- |
| `ft_isalpha` | It checks for an alphabetic character. | `ft_toupper` | It converts lowercase letters to uppercase. |
| `ft_isdigit` | It checks for a digit (between 0 and 9). | `ft_tolower` | It converts uppercase letters to lowercase. |
| `ft_isalnum` | It checks for an alphanumeric character. | `ft_atoi` | It converts the string into an int. |
| `ft_isascii` | It checks if a character fits the ASCII set. | `ft_itoa` | It converts the int into a string. |
| `ft_isprint` | It checks for an alphanumeric character. |

### String:

| Function | Description | Function | Description |
| :---: | --- | :---: | --- |
| `ft_strlen` | It calculates the lenght of the string and exclude the `\0` character. | `ft_strdup` | It duplicates the string. |
| `ft_strlcpy` | It copies a certain lenght of the input string into the destination string. | `ft_substr` | It duplicates the string from the given position for the given lenght. |
| `ft_strcat` | It catenates the input string into a  destination string. | `ft_strjoin` | It joins two strings together. |
| `ft_strchr` | It returns a pointer to the first occurrence of the character in the string. | `ft_strtrim` | It trims the string from the given set of characters. |
| `ft_strrchr` | It returns a pointer to the last occurrence of the character in the string. | `ft_split` | It returns an array of strings obtained by splitting the original string using the given character as a delimiter |
| `ft_strncmp` | It compares only the first *n* bytes of two strings. | `ft_strmapi` | It applies the function to each character of the string and returns a new string. |
| `ft_strnstr` | It locates the first occurrence of the null-terminated string *little* in the string *big*, where not more than *len* characters are searched. | `ft_striteri` | It applies the function to each character of the string. |

### Memory:

| Function | Description |
| :---: | --- |
| `ft_memset` | It fills the first *n* bytes of memory area.  |
| `ft_bzero` | It erases the data in the *n* bytesof the memory starting at the given location by writing zeros. |
| `ft_memcpy` | It copies *n* bytes from memory area *src* to memory area *dest*. The memory areas **must not** overlap. |
| `ft_memmove` | It copies *n* bytes from memory area *src* to memory area *dest*. The memory areas may overlap. |
| `ft_memchr` | It scans the initial *n* bytes of the memory area of the string for the first instance of the given character. |
| `ft_memcmp` | It compares the first *n* bytes of the memory area of two strings. |
| `ft_calloc` | It allocates memory for an array of elements of a given size and returns the allocated memory. |

### File-descriptor:

| Function | Description |
| :---: | --- |
| `ft_putchar_fd` | It ouputs the character to the specified file descriptor. |
| `ft_putstr_fd` | It ouputs the string to the specified file descriptor. |
| `ft_putendl_fd` | It ouputs the string to the specified file descriptor followed by a newline. |
| `ft_putnbr_fd` | It ouputs the integer to the specified file descriptor. |

### Linked-list (bonuses):

| Function | Description | Function | Description |
| :---: | --- | :---: | --- |
| `ft_lstnew` | It creates a new node. | `ft_lstdelone` | It deletes the node. |
| `ft_lstadd_front` | It adds the node at the beginning of the list. | `ft_lstclear` | It deletes the node and all its successors. |
| `ft_lstsize` | It counts the number of nodes in the list. | `ft_lstiter` | It iterates through the list and applies the functions to the content of each node. |
| `ft_lstlast` | It returns the last node of the list. | `ft_lstmap` | It iterates through the list and applies the functions to the content of each node and returns a new list with the result. |
| `ft_lstadd_back` | It adds the node at the end of the list. |

<br>
<hr>
<br>

<div align="center">
    <img src="assets/footer.png" />
</div>
