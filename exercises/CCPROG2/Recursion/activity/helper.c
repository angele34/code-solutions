/******************************************************************************
 * DO NOT MODIFY THIS FILE.
 *
 * This file contains helper functions for displaying the output.
 ******************************************************************************/
#ifndef HELPER_C
#define HELPER_C

#include <stdio.h>
#include <string.h>

/******************************************************************************
 * [GIVEN / DO NOT MODIFY] CONSTANTS
 ******************************************************************************/
#define MAX 20 // Max number of elements in the array

/******************************************************************************
 * [GIVEN / DO NOT MODIFY] FUNCTION PROTOTYPES
 *
 * These are the function prototypes for the functions that you need to
 * implement in the file LastnameFirstnameinitial_recursion.c
 *
 * You are not allowed to modify/change the return type nor parameters.
 ******************************************************************************/
float power(int base, int exp);
int sum(int arr[], int n);
int linearSearch(int arr[], int n, int key);
void getMinMax(int *min, int *max, int arr[], int n);
void evenNumbers(int evens[], int *n, int start, int end);
void oddNumbersReverse(int odds[], int *n, int start, int end);
int binarySearch(int arr[], int key, int low, int high);
int mysterySequence(int n);

/******************************************************************************
 * [GIVEN / DO NOT MODIFY] HELPER FUNCTIONS
 ******************************************************************************/
void initArray(int arr[])
{
  int i;
  for (i = 0; i < MAX; i++)
    arr[i] = 0;
}

void getArrayAndSize(int result[], int *n, int arr[])
{
  int i = 0;
  while (arr[i] != 999 && i < MAX)
  {
    result[i] = arr[i];
    i++;
  }
  *n = i;
}

void displayArray(int arr[], int n, int addNewline)
{
  int i;

  printf("{ ");
  for (i = 0; i < n; i++)
    if (i != n - 1)
      printf("%d, ", arr[i]);
    else
      printf("%d ", arr[i]);

  printf("}");

  if (addNewline)
    printf("\n");
}

void displaySearchResult(int arr[], int n, int key, int result)
{
  printf("Looking for ( %d ) in ", key);
  displayArray(arr, n, 1);

  if (result == -1)
    printf(" > Not found! ( %d )\n\n", result);
  else
    printf(" > Found at index %d\n\n", result);
}

/******************************************************************************
 * [GIVEN / DO NOT MODIFY] DISPLAY OUTPUT
 ******************************************************************************/
void displayPowerResult(int base, int exp)
{
  printf("( %d ) raised to ( %d )\n > %.4f\n\n", base, exp, power(base, exp));
}

void displayPower()
{
  displayPowerResult(2, 0);
  displayPowerResult(2, 4);
  displayPowerResult(2, -3);
  displayPowerResult(-2, 4);
  displayPowerResult(-3, 3);
}

void displaySumResult(int input[])
{
  int arr[MAX], n;
  getArrayAndSize(arr, &n, input);
  printf("The sum of ");
  displayArray(arr, n, 1);
  printf(" > %d\n\n", sum(arr, n));
}

void displaySum()
{
  int a[MAX] = {1, 2, 3, 4, 5, 999};
  int b[MAX] = {10, 23, 11, 63, -55, 99, -20, 88, 999};
  int c[MAX] = {6, 8, 22, -7, 8, 999};
  int d[MAX] = {4, -7, 10, 999};
  int e[MAX] = {54, 91, 44, -75, 13, -89, 999};
  displaySumResult(a);
  displaySumResult(b);
  displaySumResult(c);
  displaySumResult(d);
  displaySumResult(e);
}

void displayLinearSearchResult(int input[], int key)
{
  int arr[MAX], n;
  getArrayAndSize(arr, &n, input);
  displaySearchResult(arr, n, key, linearSearch(arr, n, key));
}

void displayLinearSearch()
{
  int a[MAX] = {10, 23, 11, 63, -55, 99, -20, 88, 999};
  int b[MAX] = {4, -7, 10, 999};
  displayLinearSearchResult(a, 10);
  displayLinearSearchResult(a, -55);
  displayLinearSearchResult(a, 99);
  displayLinearSearchResult(a, 4);
  displayLinearSearchResult(b, 4);
  displayLinearSearchResult(b, 10);
  displayLinearSearchResult(b, -55);
}

void displayGetMinMaxResult(int input[])
{
  int arr[MAX], n, min, max;
  getArrayAndSize(arr, &n, input);

  min = arr[0];
  max = arr[0];
  getMinMax(&min, &max, arr, n);

  displayArray(arr, n, 1);
  printf(" > Min = ( %d ), Max = ( %d )\n\n", min, max);
}

void displayGetMinMax()
{
  int a[MAX] = {1, 2, 3, 4, 5, 999};
  int b[MAX] = {10, 23, 11, 63, -55, 99, -20, 88, 999};
  int c[MAX] = {6, 8, 22, -7, 8, 999};
  int d[MAX] = {4, -7, 10, 999};
  int e[MAX] = {54, 91, 44, -75, 13, -89, 999};
  displayGetMinMaxResult(a);
  displayGetMinMaxResult(b);
  displayGetMinMaxResult(c);
  displayGetMinMaxResult(d);
  displayGetMinMaxResult(e);
}

void displayEvenNumbersResult(int start, int end)
{
  int evens[MAX], n = 0;
  printf("The even numbers from ( %d ) to ( %d ) are\n > ", start, end);
  evenNumbers(evens, &n, start, end);
  displayArray(evens, n, 1);
  printf("\n");
}

void displayEvenNumbers()
{
  displayEvenNumbersResult(1, 10);
  displayEvenNumbersResult(-10, 0);
  displayEvenNumbersResult(-5, 13);
}

void displayOddNumbersReverseResult(int start, int end)
{
  int odds[MAX], n = 0;
  printf("The odd numbers from ( %d ) to ( %d ) in reverse are\n > ", start, end);
  oddNumbersReverse(odds, &n, start, end);
  displayArray(odds, n, 1);
  printf("\n");
}

void displayOddNumbersReverse()
{
  displayOddNumbersReverseResult(1, 10);
  displayOddNumbersReverseResult(-10, 0);
  displayOddNumbersReverseResult(-5, 13);
}

void displayBinarySearchResult(int input[], int key)
{
  int arr[MAX], n;
  getArrayAndSize(arr, &n, input);
  displaySearchResult(arr, n, key, binarySearch(arr, key, 0, n - 1));
}

void displayBinarySearch()
{
  int a[MAX] = {-55, -20, 10, 11, 23, 63, 88, 99, 999};
  int b[MAX] = {-7, 4, 10, 999};
  displayBinarySearchResult(a, 10);
  displayBinarySearchResult(a, -55);
  displayBinarySearchResult(a, 99);
  displayBinarySearchResult(a, 4);
  displayBinarySearchResult(b, 4);
  displayBinarySearchResult(b, 10);
  displayBinarySearchResult(b, -55);
}

void displayMysterySequenceResult(int n)
{
  int lastDigit = n % 10;
  char orderStr[3];

  if (n == 11 || n == 12 || n == 13)
    strcpy(orderStr, "th");
  else
    switch (lastDigit)
    {
    case 1:
      strcpy(orderStr, "st");
      break;
    case 2:
      strcpy(orderStr, "nd");
      break;
    case 3:
      strcpy(orderStr, "rd");
      break;
    default:
      strcpy(orderStr, "th");
      break;
    }

  printf(" > The %d%s number in the mystery sequence is ( %d )\n\n", n, orderStr, mysterySequence(n));
}

void displayMysterySequence()
{
  displayMysterySequenceResult(0);
  displayMysterySequenceResult(1);
  displayMysterySequenceResult(2);
  displayMysterySequenceResult(3);
  displayMysterySequenceResult(6);
  displayMysterySequenceResult(11);
}

#endif // HELPER_C