/*
https://www.hackerrank.com/challenges/students-marks-sum/problem?
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int marks_summation(int* marks, int number_of_students, char gender) {
  int sum_marks = 0;
  if (gender == 'b') {
      for (int mark = 0; mark < number_of_students; mark+=2) {
          sum_marks += marks[mark];
      }
  }
  
  else if (gender == 'g') {
      for (int mark = 1; mark < number_of_students; mark+=2) {
          sum_marks +=marks[mark];
      }
  }
  return sum_marks;
}

int main() {
    int number_of_students;
    char gender;
    int sum;
  
    scanf("%d", &number_of_students);
    int *marks = (int *) malloc(number_of_students * sizeof (int));
 
    for (int student = 0; student < number_of_students; student++) {
        scanf("%d", (marks + student));
    }
    
    scanf(" %c", &gender);
    sum = marks_summation(marks, number_of_students, gender);
    printf("%d", sum);
    free(marks);
 
    return 0;
}