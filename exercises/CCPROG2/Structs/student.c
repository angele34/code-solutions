/*
Create a structure called "Student" with members name, age, and total marks. Write a C program
 to input data for two students, display their information, and find the average of total marks.
*/

#include <stdio.h>

typedef char str[50];

typedef struct {
    str name;
    int age;
    float totalMarks;
} Student;

void inputData(Student students[], int nStudents) {
    int i;
    for (i = 0; i < nStudents; i++) {
        printf("\nInput the details for Student %d\n", i+1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("Total marks: ");
        scanf("%f", &students[i].totalMarks);
    }
}

void displayInfo(Student students[], int nStudents) {
    int i;
    for (i = 0; i < nStudents; i++) {
        printf("\nStudent %d Information", i+1);
        printf("\nName: %s\nAge: %d\nTotal Marks: %.2f\n", students[i].name, students[i].age, students[i].totalMarks);
    }
}

float findAverage(Student students[], int nStudents) {
    float avg = 0.0;
    int i;
    for (i = 0; i < nStudents; i++) {
        avg += students->totalMarks;
    }
    return avg / nStudents;
}

int main() {
    Student student[2];
    inputData(student, 2);
    printf("\n");
    displayInfo(student, 2);
    printf("\n");
    float avg = findAverage(student, 2);
    printf("Average of total marks: %.2f", avg);
}