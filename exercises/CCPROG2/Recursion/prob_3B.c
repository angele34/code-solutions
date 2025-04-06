#include <stdio.h>


/*
   Write a RECURSIVE implementation of the function LargestDigit()
   wich will determine and return the largest digit in nNum.  

   Examples:  
      LargestDigit(1234, 0) returns 4.
      LargestDigit(634852, 0) returns 8.
*/

int 
LargestDigit(int nNum, int temp)
{
    /* You are NOT allowed to declare a local variable here. */
    /* DO NOT use printf() inside this function. */
  
    /* 
       THINK ABOUT THE FOLLOWING FIRST!
       
       1. What is the condition for the base case?
  
          What are the processing steps needed for the base case?
       
       2. What is the condition for the recursive case? 
          What are the processing steps needed for the recursive case?
    */
   if (nNum == 0) // base case
      return temp;
    
   if ((nNum % 10) > temp)
      temp = nNum % 10;
   return LargestDigit(nNum / 10, temp); // recursive case to remove the rightmost digit
}


int 
main()
{
    int nNum;

    printf("Input a positive integer: ");
    scanf("%d", &nNum); // assume nNum is positive
    
    printf("LargestDigit(%d, 0) is %d.\n", LargestDigit(nNum, 0), LargestDigit(nNum, 0)); 

    // Question: What do think is the reason for having 0 as the 
    //           2nd parameter value in LargestDigit() function call? 
    // Ans: 0 is set to be initially be the largest value for comparison

    return 0;

}

 