/******************************************************************************
 * Topic   : Recursion
 * Name    : LastName, FirstName
 * Section : S##
 ******************************************************************************
 *
 * 1. Encode your name and section above, as well as rename this file in the
 *    following format: LastnameFirstnameinitial_recursion.c
 *     - Example: DelaCruzJ_recursion.c
 *
 * 2. Read and understand the problem specs.
 *
 * 3. Implement your solution in this file. This is the C source file that you
 *    should submit/upload in AnimoSpace. Follow all the instructions in the
 *    accompanying specifications file and the instructions written (as function
 *    comments) in this file.
 *
 *    Compile:
 *      prompt~> gcc -Wall -std=c99 LastnameFirstnameinitial_recursion.c -o app
 *
 *    Run in Mac/Linux:
 *      prompt~> ./app
 *
 *    Run in Windows:
 *      prompt~> app
 *
 * 4. The output formatting is already handled for you.
 *
 * Prepared by
 * - Email  : kristine.kalaw@dlsu.edu.ph
 * - @author: Kristine Kalaw
 *            Department of Software Technology
 *            College of Computer Studies
 *            De La Salle University
 *
 * Kindly inform me if there are any corrections needed for this template
 ******************************************************************************/

#include "helper.c"

/******************************************************************************
 * [TODO] FUNCTION IMPLEMENTATIONS
 *
 * The section area below is where you will complete the functions as described
 * in the problem specs.
 *
 * Ideally, all functions must observe proper and complete function
 * documentation. This means it has a function description, a list of parameters
 * with description, and if it returns something, a description of the return
 * value.
 *
 * For this exercise, you are NOT ALLOWED to define any other convenience/helper
 * function.
 ******************************************************************************/

/**
 * <Provide complete function documentation>
 */
float power(int base, int exp)
{ /*
    You may declare and use your own local variables
    Do NOT use printf() nor scanf() in your final solution
    Do NOT modify/change the return type nor parameters
  */
 if (exp == 0)
  return 1;
  else if (exp > 0)
    return power(base, exp-1) * base;
  else
   return power(base, exp + 1) / base;
}

/**
 * <Provide complete function documentation>
 */
int sum(int arr[], int n)
{ /*
    You may declare and use your own local variables
    Do NOT use printf() nor scanf() in your final solution
    Do NOT modify/change the return type nor parameters
  */
  if (n == 0)
    return 0;
  return arr[n-1] + sum(arr, n-1);
}

/**
 * <Provide complete function documentation>
 */
int linearSearch(int arr[], int n, int key)
{ /*
    You may declare and use your own local variables
    Do NOT use printf() nor scanf() in your final solution
    Do NOT modify/change the return type nor parameters
  */
  if (n == 0)
    return -1;
  if (arr[n-1] == key)
    return n-1;
  return linearSearch(arr, n-1, key);
}

/**
 * <Provide complete function documentation>
 */
void getMinMax(int *min, int *max, int arr[], int n)
{ /*
    You may declare and use your own local variables
    Do NOT use printf() nor scanf() in your final solution
    Do NOT modify/change the return type nor parameters
  */
 if (n == 0)
    return;
  getMinMax(min, max, arr, n-1);
  if (*min > arr[n-1])
    *min = arr[n-1];
  if (*max < arr[n-1])
    *max = arr[n-1];
}

/**
 * <Provide complete function documentation>
 */
void evenNumbers(int evens[], int *n, int start, int end)
{ /*
    You may declare and use your own local variables
    Do NOT use printf() nor scanf() in your final solution
    Do NOT modify/change the return type nor parameters
  */

  if (start > end)
    return;
  if (start % 2 == 0) {
    evens[*n] = start;
    (*n)++;
  }
  evenNumbers(evens, n, start+1, end);
}

/**
 * <Provide complete function documentation>
 */
void oddNumbersReverse(int odds[], int *n, int start, int end)
{ /*
    You may declare and use your own local variables
    Do NOT use printf() nor scanf() in your final solution
    Do NOT modify/change the return type nor parameters
  */
  if (end+1 == start)
    return;
  if (end % 2 != 0) {
    odds[*n] = end;
    (*n)++;
  }
  oddNumbersReverse(odds, n, start, end-1);
}

/**
 * <Provide complete function documentation>
 */
int binarySearch(int arr[], int key, int low, int high)
{ /*
    You may declare and use your own local variables
    Do NOT use printf() nor scanf() in your final solution
    Do NOT modify/change the return type nor parameters
  */
 if (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == key) 
      return mid;
    else if (arr[mid] < key) // search right half
      return binarySearch(arr, key, mid + 1, high);
    else  
      return binarySearch(arr, key, low, mid - 1); // search left half
 }
 return -1;
}

/**
 * <Provide complete function documentation>
 */
int mysterySequence(int n)
{ /*
    You may declare and use your own local variables
    Do NOT use printf() nor scanf() in your final solution
    Do NOT modify/change the return type nor parameters
  */
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  return mysterySequence(n-1) + mysterySequence(n-2);
}

/******************************************************************************
 * [GIVEN / DO NOT MODIFY] MAIN FUNCTION
 ******************************************************************************/
int main()
{
  printf("+-----------+\n");
  printf("| RECURSION |\n");
  printf("+-----------+\n");

  printf("\n========== power ==========\n\n");
  displayPower();

  printf("\n========== sum ==========\n\n");
  displaySum();

  printf("\n========== linearSearch ==========\n\n");
  displayLinearSearch();

  printf("\n========== getMinMax ==========\n\n");
  displayGetMinMax();

  printf("\n========== evenNumbers ==========\n\n");
  displayEvenNumbers();

  printf("\n========== oddNumbersReverse ==========\n\n");
  displayOddNumbersReverse();

  printf("\n========== binarySearch ==========\n\n");
  displayBinarySearch();

  printf("\n========== mysterySequence ==========\n\n");
  displayMysterySequence();

  return 0;
}