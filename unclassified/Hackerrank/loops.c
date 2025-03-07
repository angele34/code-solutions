#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
https://www.hackerrank.com/challenges/for-loop-in-c/problem?
*/
int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
  	for (int i = a; i <= b; i++) {
          if (i <= 9) {
              if (i == 1) printf("%s", "one\n");
              if (i == 2) printf("%s", "two\n");
              if (i == 3) printf("%s", "three\n");
              if (i == 4) printf("%s", "four\n");
              if (i == 5) printf("%s", "five\n");
              if (i == 6) printf("%s", "six\n");
              if (i == 7) printf("%s", "seven\n");
              if (i == 8) printf("%s", "eight\n");
              if (i == 9) printf("%s", "nine\n");
          } 
         if (i > 9 && i%2==0) {
            printf("%s", "even\n");
        } else if (i > 9 && i%2==1) {
            printf("%s", "odd\n");
        }
      }
    return 0;
}

