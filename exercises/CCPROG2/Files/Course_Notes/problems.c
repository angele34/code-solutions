#include <stdio.h>
#include <stdlib.h>

typedef char String20[20];
struct nameTag {
    String20 first;
    String20 last;
};

struct studentTag {
    int ID; // student ID number
    struct nameTag name;
    float grade;
};

/*
a. 1st col: student ID num
b. 2nd col: student's first name
c. 3rd col: student's last name
d: 4th col: student's grade (0.0 to 4.0)
*/

/* CHALLENGE #1:
Read all the contents of "STUDENTS.TXT" and printf() the student information.
*/

void Challenge_1(struct studentTag student) {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("ERROR: File does not exist.\n");
        exit(1);
    }
    char buffer[100];
    while(fgets(buffer, sizeof(buffer), fp) != NULL) {
        sscanf(buffer, "%d %s %s %f", &student.ID, student.name.first, student.name.last, &student.grade);
        printf("%-4d  %-3s %-5s\t%.1f\n", student.ID, student.name.first, student.name.last, student.grade);
    }
    fclose(fp);
}

/* CHALLENGE #2:
Read all the contents of "STUDENTS.TXT" and produce as a result two text files:
a. FAIL.TXT - contains data about students who failed (0.0)
b. PASS.TXT - contains data about students who passed (> 0.0)
*/

void Challenge_2(struct studentTag student) {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("ERROR: File does not exist.\n");
        exit(1);
    }

    FILE *output1 = fopen("FAIL.TXT", "w");
    if (output1 == NULL) {
        printf("ERROR: Could not open FAIL.TXT\n");
        exit(1);
    }

    FILE *output2 = fopen("PASS.TXT", "w");
    if (output2 == NULL) {
        printf("ERROR: Could not open PASS.TXT\n");
        fclose(output1);
        exit(1);
    }
    char buffer[100];
    while(fgets(buffer, sizeof(buffer), fp) != NULL) {
        sscanf(buffer, "%d %s %s %f", &student.ID, student.name.first, student.name.last, &student.grade);
        
        if (student.grade == 0.0) {
            fprintf(output1, "%-4d %3s %-5s %.1f\n", 
                    student.ID, student.name.first, student.name.last, student.grade);
        } else {
            fprintf(output2, "%-4d %3s %-5s %.1f\n", 
                    student.ID, student.name.first, student.name.last, student.grade);
        }
    }
    fclose(output1);
    fclose(output2);
    fclose(fp);
}

/* CHALLENGE #3:
Ask the user to input data for one more student, and append the data to "STUDENTS.TXT"
*/

void Challenge_3(struct studentTag student) {
    FILE *fp = fopen("students.txt", "a");
    if (fp == NULL) {
        printf("ERROR: File does not exist.\n");
        exit(1);
    }
    printf("Input ID: ");
    scanf("%d", &student.ID);

    printf("Input first name: ");
    scanf("%s", student.name.first);
    printf("Input last name: ");
    scanf("%s", student.name.last);

    printf("Input grade: ");
    scanf("%f", &student.grade);

    fprintf(fp, "%d %s %s %.1f", student.ID, student.name.first, student.name.last, student.grade);
    fclose(fp);
}

int main() {
    struct studentTag student;
    Challenge_1(student);
    Challenge_2(student);
    Challenge_3(student);
    return 0;
}