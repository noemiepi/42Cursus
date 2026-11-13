<div align="center">
    <h1>Push-Swap</h1>
    <h3>Because Swap_push doesn't feel as natural</h3>
    <i>This project has been created as part of the 42 curriculum by npillet.</i>
</div>

## Table of Contents
- [Description](#description)
    - [Operations](#operations)
- [Instructions](#instructions)
- [Thought process](#thought-process)
    - [1. The Parsing and Error Management](#1-the-parsing-and-error-management)
    - [2. Small Stack Sort](#2-small-stack-sort)
    - [3. The Algorithm](#3-the-algorithm)
- [Resources](#resources)

## Description
The goal of this project is to sort a list of integers in ascending order and display the shortest sequence of operations needed.

For the maximum project validation (100%) and eligibility for bonuses, it is required to:
- Sort 100 random numbers in fewer than 700 operations
- Sort 500 random numbers in no more than 5500 operations.


For the minimal project validation (minimum 80%), it is required to either:
- Sort 100 numbers in under 1100 operations and 500 numbers in under 8500 operations
- Sort 100 numbers in under 700 operations and 500 numbers in under 11500 operations
- Sort 100 numbers in under 1300 operations and 500 numbers in under 5500 operations

### Operations
We start with two stacks **a** and **b**:
- Stack **a** contains a random series of numbers, negative and positive alike.
- Stack **b** is empty.

<br>

We have to sort the numbers in stack **a** in ascending order. The following operations will help us achieve it:
- *sa (swap a)*: Swaps the first 2 elements at the top of stack **a**.
Does nothing if there is only one element or none.
- *sb (swap b)*: Swaps the first 2 elements at the top of stack **b**.
Does nothing if there is only one element or none.
- *ss*: Does **sa** and **sb** at the same time.
- *pa (push a)*: Take the first element at the top of **b** and put it at the top of **a**.
Does nothing if **b** is empty.
- *pb (push b)*: Take the first element at the top of **a** and put it at the top of **b**.
Does nothing if **a** is empty.
- *ra (rotate a)*: Shift up all the elements of stack **a** by 1.
The first element becomes the last one.
- *rb (rotate b)*: Shift up all the elements of stack **b** by 1.
The first element becomes the last one.
- *rr*: Does **ra** and **rb** at the same time.
- *rra (reverse rotate a)*: Shift down all the elements of stack **a** by 1. The last element becomes the first one.
- *rrb (reverse rotate b)*: Shift down all the elements of stack **b** by 1. The last element becomes the first one.
- *rrr*: Does **rra** and **rrb** at the same time.

## Instructions
Firstly, compile the files used in the project by using:
```bash
make
```

Use this command to execute the code:
```bash
./push_swap "3 -6 4 98 45 10 1"
```
or
```bash
./push_swap 3 -6 4 98 45 10 1
```
or
```bash
./push_swap "3 -6 4" 98 45 "10 1"
```
It can be any random series of numbers.

## Thought process
### &emsp;1. The Parsing and Error Management
The program will start by filling our **stack_a** by checking what kind of input it is and if it is correct. The filling process is similar in the case of a simple argument or a string as an argument. The string will be split to analyze every number inside it.
For both cases, we will verify if:
- There are only numbers *(with or without the + or - sign)*
- Said number is between the minimum and maximum int
If it's not the case, an error message will be sent on the error output.
It will then be added to **stack_a**.
Once every argument is added to the stack, the program will check if there's a number present at least twice in the stack. If there is an error, a message is sent.
When everything is done, we check if the stack is already sorted, in which case we free the list and stop the program. Otherwise, we continue with the sorting.


### &emsp;2. Small Stack Sort
We calculate the size of the stack first to better sort it.
With a stack of two, a simple swap is enough.

#### Stack of Three
With a stack of three, the function *sort_three* is used.
We sort the stack in ascending order with a minimal number of operations by comparing in which position the value is. There are only five possibilities to handle here.
- A combination of **sa** and **ra** or **rra** is needed when the first number is either the maximum or the minimum and the second is bigger than the third.
- Else, a single action is needed to correctly and efficiently sort the stack.

#### Stack of Four
With a stack of four, the function *sort_four* is used.
We sort the stack in ascending order with a minimal number of operations by:
- Finding the position of the minimum value and pushing it in **stack_b**
- Using the function *sort_three* if the **stack_a** is not already sorted
- Searching the correct position the pushed value needs to be taken by moving **stack_a** around
- Pushing the value back in **stack_a** and applying the necessary operations to place **stack_a**'s values back correctly.

#### Stack of Five
With a stack of five, the function *sort_five* is used.
We sort the stack in ascending order with a minimal number of operations by:
- Pushing the first two values in **stack_b** and putting them in descending order
- Using the function *sort_three* if the **stack_a** is not already sorted
- Searching the correct position, the first value in **stack_b** needs to be taken by moving **stack_a** around
- Pushing the value back in **stack_a** and repeating the process with the second value in **stack_b**
- Applying the necessary operations to place **stack_a**'s values back correctly.

### &emsp;3. The Algorithm
The one used here is the Turk algorithm. It consists of calculating the cost of moving a number from one stack to another and putting it in the desired position. That way, the stack will be sorted with a minimum number of actions done.

#### Pushing A to B
A list grouping every number in a stack is created to calculate each cost. That way, we can easily access the cheapest number to move.
That way, a function will push the cheapest in **stack_b** in descending order until just three numbers remain in **stack_a**. We check if it's already sorted; if not, we sort it.

#### Pushing B to A
To push everything back in **stack_a** in ascending order, we:
- Search the correct position the first value in **stack_b** needs to take by moving **stack_a** around
- Push the value back in **stack_a** and repeat the process with the second value in **stack_b**
- Apply the necessary operations to place **stack_a**'s values back correctly.
Just like the end of the *sort_five* function.

## Resources
### Notions
#### Parsing
- [Parsing in C](https://openclassrooms.com/forum/sujet/le-parsing-en-c)

- [Introduction to Parsers](https://www.geeksforgeeks.org/compiler-design/introduction-of-parsing-ambiguity-and-parsers-set-1/)

#### Algorithm
- [push_swap find best algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

- [push_swap algorithm](https://github.com/Akadil/42project_push_swap/tree/main/srcs/part2)

#### Visualizer and tests
- [Visualizer](https://github.com/o-reo/push_swap_visualizer)

- [Tests](https://github.com/alizealebaron/push_swap/blob/main/todoom_list.md)

### GitHub:
- [naha7777](https://github.com/naha7777/Push_Swap)

<br>
<hr>
<br>

<div align="center">
    <img src="assets/footer.png" />
</div>