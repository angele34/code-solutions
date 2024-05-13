/* 
https://www.hackerrank.com/challenges/sum-numbers-c/problem?
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int n,m;
    float x,y;
    scanf("%d %d", &n, &m);
    scanf("%f %f", &x, &y);
   
    printf("%d %d\n", (n+m), (n-m));
    // Rounds off to one dec. place
    printf("%.1f %.1f\n", round((x+y) * 10.0) / 10.0, round((x-y) * 10.0) / 10.0);
    return 0;
}