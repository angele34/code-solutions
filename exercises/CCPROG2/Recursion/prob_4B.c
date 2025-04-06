#include <stdio.h>

/*
   Write a RECURSIVE implementation of the function Multipliers()
   that will display digits from the LEFT to the RIGHT 
   and their 
associated position (1s, 10s, 100s, etc..) in the 
   power of 10 number representation, i.e., ones,tens, hundreds, thousands...   

   Examples:  

      Multipliers(568, 1) will print the following as a result:
        5  100s
        6  10s
        8  1s

     
      Multipliers(90653, 1) will produce the following as a result:
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
  if (nNum == 0) // base case
      return;
   Multipliers(nNum / 10, nPlace * 10); // recursive case
   printf("%d  %ds\n", nNum % 10, nPlace);
   // non tail end recursive function
}


int main()
{
    int nNum;

    printf("Input a positive integer: ");
    scanf("%d", &nNum);  // assume nNum is positive
    
    Multipliers(nNum, 1);

    // Question: What do think is the reason for having 1 as the 
    //           2nd parameter value in Multipliers() function call? 
    // Ans: To get the place value by multiplying 10 each recursive call

    return 0;

}

 