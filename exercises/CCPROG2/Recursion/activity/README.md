# Exercise 04 - File Handling

> *If you don't have a built-in markdown viewer, you can copy the content of this file and paste it into <https://markdownlivepreview.org/> to view it formatted.*

The goal of this exercise is to:

- Design and implement simple recursive algorithms
- Continue practicing proper code documentation
- Review and strengthen previously learned concepts

## Folder Content

- [`LastnameFirstnameinitial_recursion.c`](LastnameFirstnameinitial_recursion.c)
  - The skeleton file containing some initial code you need to complete
- [`helper.c`](helper.c)
  - Contains helper functions for displaying the output

## Restrictions

You are **NOT ALLOWED** to do the following:

- Declare and use global variables (i.e., variables declared outside any function)
- Use `exit`, `goto` (i.e., to jump from code segments to code segments), `break` (except in `switch` statements), or `continue` statements
- Use `return` statements to prematurely terminate a loop, function, or program
  - NOTE: Early returns are okay in recursion
- Call the `main()` function to repeat the process instead of using loops
- Include other library/header other than those already in the template

Regarding built-in functions in `string.h`:

- You may only use: `strlen`, `strcpy`, `strcmp`, `strcat`

You may only use ideas / constructs / syntax / built-in functions previously learned in class.

## Activity Instructions

1. Implement as many of the functions as you can within class time. All of these functions must showcase recursion.

2. Implement your solution in the provided activity template.

    Compile:

    ```shell
    prompt~> gcc -Wall -std=c99 LastnameFirstnameinitial_recursion.c -o app
    ```

    Run in Mac/Linux:

    ```shell
    prompt~> ./app
    ```

    Run in Windows:

    ```shell
    prompt~> app
    ```

3. The output formatting is already handled for you.

## Functions to Implement

For this exercise, implement as many functions as you can within the class time. The implementations must showcase recursion. Assume the input parameters are always valid.

- This exercise is 15 points, wherein 5 of these points is if your code is able to compile properly
- This means you need 10 more points for the full credit
- The points per function is indicated below

### `float power(int base, int exp)` [3 pts]

Write a recursive function `power()` that will raise a certain integer `base` by a certain integer `exp`. It should consider the cases when    Multipliers(90653, 1) will produce the following as a result:
        9  10000s
        0  1000s 
        6  100s  
        5  10s
        3  1s   
*/
void 
Multipliers(int nNum, int nPlace)
{
   /* You are NOT allowed to declare a local variable here. */
   /* You haev to use printf() in this function to print the results. */
  
   /* 
       THINK ABOUT THE FOLLOWING FIRST!
       
       1. What is the condition for the base case?
  
          What are the processing steps needed for the base case?
       
       2. What is the condition for the recursive case? 
          What are the processing steps needed for the recursive case?
   */
  if (nNum == 0)
      //
   Multipliers(nNum / 10, nPlace * 10);
   printf("%d %d", nNum % 10, nPlace);


}
`exp` is zero, positive, or negative.

- $2^0 = 1$

- $2^4 = 2 \times 2 \times 2 \times 2 = 16$

- $2^{-3} = \dfrac{1}{2^3} = \dfrac{1}{2 \times 2 \times 2} = 0.125$

- $-2^4 = -2 \times -2 \times -2 \times -2 = 16$

- $-3^3 = -3 \times -3 \times -3 = -27$

The formula is as follows:

$$
base^{exp} = \begin{cases}
  1 & \text{if } exp = 0 \\
  base \times base^{exp-1} & \text{if } exp > 0 \\
  \dfrac{1}{base^{exp}} & \text{if } exp < 0
\end{cases}
$$

### `int sum(int arr[], int n)` [3 pts]

Recall the `getSum()` function from a previous exercise. Given an array of integers `arr` and the number of elements `n`, rewrite the function such that it uses recursion instead of a loop.

- The sum of `{1, 2, 3, 4, 5}` is `15`
- The sum of `{10, 23, 11, 63, -55, 99, -20, 88}` is `219`

### `int linearSearch(int arr[], int n, int key)` [3 pts]

Recall the `linearSearch()` function from a previous exercise. Given an array of integers `arr`, the number of elements `n`, and the search key `key`, rewrite the function such that it uses recursion instead of a loop. The function should return the index number if `key` is found, -1 otherwise.

- Is `10` in `{10, 23, 11, 63, -55, 99, -20, 88}`?
  - Found at index `0`
- Is `4` in `{10, 23, 11, 63, -55, 99, -20, 88}`?
  - Not found (`-1`)

### `void getMinMax(int *min, int *max, int arr[], int n)` [4 pts]

Recall the `getMinimum()` and `getMaximum` functions from a previous exercise. Given an array of integers `arr` and the number of elements `n`, rewrite the function such that it uses recursion instead of a loop. `min` and `max` are pointers to the current minimum and maximum values, which are initialized to the 1st element of `arr` before the start of the recursive call.

- `{10, 23, 11, 63, -55, 99, -20, 88}`
  - Min = `-55`, Max = `99`

### `void evenNumbers(int even[], int *n, int start, int end)` [4 pts]

Write a recursive function that populates the `evens` array of integers with the even numbers from `start` to `end` (inclusive). `n` is the pointer to the size of the `evens` array, which is initialized to 0 before the start of the recursive call.

- The even numbers from `1` to `10` are `{ 2, 4, 6, 8, 10 }`
- The even numbers from `-5` to `13` are `{ -4, -2, 0, 2, 4, 6, 8, 10, 12 }`

### `void oddNumbersReverse(int even[], int *n, int start, int end)` [4 pts]

Write a recursive function that populates the `odds` array of integers with the odd numbers from `start` to `end` (inclusive) in reverse order. `n` is the pointer to the size of the `odds` array, which is initialized to 0 before the start of the recursive call.

- The odd numbers from `1` to `10` in reverse are `{ 9, 7, 5, 3, 1 }`
- The odd numbers from `-5` to `13` in reverse are `{ 13, 11, 9, 7, 5, 3, 1, -1, -3, -5 }`

### `int binarySearch(int arr[], int key, int low, int high)` [5 pts]

Recall the `binarySearch()` function from a previous exercise. Given an array of integers `arr` and the search key `key`, rewrite the function such that it uses recursion instead of a loop. The parameters `low` and `high` determines the bounds of the search area within the array. The function should return the index number if `key` is found, -1 otherwise.

- Is `10` in `{-55, -20, 10, 11, 23, 63, 88, 99}`?
  - Found at index `0`
- Is `4` in `{-55, -20, 10, 11, 23, 63, 88, 99}`?
  - Not found (`-1`)

### `int mysterySequence(int n)` [5 pts]

The number sequence is  `0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...`. Deductively, try to see the behavior of the sequence of numbers in the mystery sequence and write a function that will accept as parameter a non-negative integer `n` and return the corresponding $n$th item in the sequence.

- `mysterySequence(0)` = 0
- `mysterySequence(1)` = 1
- `mysterySequence(2)` = 1
- `mysterySequence(3)` = 2
- `mysterySequence(6)` = 8
- `mysterySequence(11)` = 89
