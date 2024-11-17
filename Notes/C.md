## Basics of C Language course

### Session 1

- What is Embedded System?
- Environment Setup
  - MingW Installation
  - Notepad++
- Hello World Program
- Data Types
- Naming Rules
- Operators
  - Binary Operators
  - Unary Operators

### x++ vs x = x + 1

- x++ -> inc in one instruction
- x = x + 1 -> Load Modify Store

### Session 2

- Lab1
- binary note or observation: (0111)~2~ = 8 , (1000)~2~ = 7

###### observation

Lab 4

shift left like multiplication / 2
shift right like division / 2

- x = 7 << 1; means x \* 2 = 14;
- x = 7 << 2; means x \* 4 = 28;

###### Assignment operators

=, +=, /=, >>= , ...

- take care: `x =+ 1`
- best practice: use x = x+1 to fail safe

###### bitwise operators

operate on binary scale

###### Relational Operators

```c
    int res = 5;
    res = x ==5; // true
    res = x !=5; // false
    res = x > 5; // false
    res = x < 5; // false
```

###### conditional statements

- if
- switch
- lab:

###### rules of statement in C

1. else if , else are optional
2. No code is available between if, else if, else
3. nested if is allowed( recommeded no more than 3 stages of nesting)
4. if u have combination of condition use brackets

###### switch statement

- syntax
- switch statment rules
  1. const must be unique
  2. const can't be a variable
  3. only be decimal value
  4. default is optional
  5. only one default is allowed
  6. default can be any where
  7. must be break to ends case or default

##### what is the advantage of switch?

use lookup table
so the answer always will be in 1 check
but if else if may be the true condition in the last else if condition so it took check or more.

###### observation

if the program requires more than 2 checks (equalilty check) use switch case

## Session 3

-Lab: set , clear, toggle operation on real numbers

- lab for loop
- for
- while
- do while
- break
- continue
- float comparsion
- lab: factorial iterative way

###### websites

leetcode
indiabix
codeforwin
hackerrank
codeforces
uva

### Session 4

- %c format specifier

```c
// bug: u have to put space before %c
    printf("Enter operation: ");
    scanf(" %c", &operation);
```

- lab: simple calculator
- ternary operator
- goto
- function
  - local , global variables
- swap function : pass by value, pass by reference

### Session 5

### Session 6

### Session 7

### Session 8

### Session 9

### Session 10
