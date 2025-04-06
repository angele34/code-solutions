#include <stdio.h>

/*
   Write a RECURSIVE implementation of the function EvenDigits_LeftRight(nNum)
   that will display only those digits of nNum that are even, starting from the
   leftmost to the rightmost digit.

   Examples:  
      EvenDigits_LeftRight(1234) displays 24

      EvenDigits_LeftRight(8634452) displays 86442
*/

void 
EvenDigits_LeftRight(int nNum)
{
    /* You are NOT allowed to declare a local variable here. */
    /* You will need to use printf() inside this function. */
  
    /* 
       THINK ABOUT THE FOLLOWING FIRST!
       1. What is the condition for the base case?
  
          What are the processing steps needed for the base case?
       
       2. What is the condition for the recursive case? 
          What are the processing steps needed for the recursive case?
    */

   if (nNum == 0) // base case
      return;
   EvenDigits_LeftRight(nNum / 10); // remove rightmost digit (recursive case)
   if ((nNum % 10) % 2 == 0) 
      printf("%d", nNum % 10);
      
}
int 
main()
{
    int nNum;

    printf("Input a positive integer: ");
    scanf("%d", &nNum); // assume nNum is positive
    
    EvenDigits_LeftRight(nNum); 

    return 0;

}

 