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

    fprintf(fp, "%d %s %s %.1f\n", student.ID, student.name.first, student.name.last, student.grade);
    fclose(fp);
}

/* CHALLENGE #4: 
Read all the contents of "STUDENTS.TXT" and produce as a result a new binary file named
“STUDENTS.BIN” which contains the same student data from the input text file. 
You should fscanf() the student data into a student structure variable, 
and fwrite() it to the binary file.
*/

void Challenge_4(struct studentTag student) {
    FILE *fp = fopen("STUDENTS.TXT", "r");
    if (fp == NULL) {
        printf("ERROR: File STUDENTS.TXT not found.\n");
        exit(1);
    }
    FILE *output = fopen("STUDENTS.BIN", "wb");
    if (output == NULL) {
        printf("ERROR: Could not open STUDENTS.BIN for writing.\n");
        fclose(fp);
        exit(1);
    }
    while(fscanf(fp, "%d %s %s %f", &student.ID, student.name.first, student.name.last, &student.grade) == 4) {
        // write student data to bin file, file pointer is output
        fwrite(&student, sizeof(struct studentTag), 1, output);
    }
    fclose(fp);
    fclose(output);
}

/* CHALLENGE #5:
Read all the contents of the binary file “ STUDENTS.BIN” and printf() the student information. Please
take note that you do not know in advance how many student data values are stored in the binary file.
*/

void Challenge_5(struct studentTag student) {
    FILE *fp_bin = fopen("STUDENTS.BIN", "rb");
    if (fp_bin == NULL) {
        printf("ERROR: File STUDENTS.BIN not found\n");
        exit(1);
    }
    printf("\n\nBinary file output:\n");
    while (fread(&student, sizeof(struct studentTag), 1, fp_bin) == 1) {
        printf("%d %s %s %.1f\n", student.ID, student.name.first, student.name.last, student.grade);
    }
    fclose(fp_bin);
}

/* CHALLENGE #6:
Read contents of the binary file “ STUDENTS.BIN” in **reversed order** and copy them onto a new
binary file named “STUDENTS-REV.BIN”.
*/

void Challenge_6(struct studentTag student) {
    FILE *fp_bin = fopen("STUDENTS.BIN", "rb");
    if (fp_bin == NULL) {
        printf("ERROR: File STUDENTS.BIN not found\n");
        exit(1);
    }
    FILE *cpy_bin = fopen("STUDENTS-REV.BIN", "wb");

    fseek(fp_bin, 0, SEEK_END);
    long file_size = ftell(fp_bin);
    int n = file_size / sizeof(struct studentTag);

    // Copy the contents of STUDENTS.BIN in reverse
    for (int i = n-1; i >= 0; i--) {
        fseek(fp_bin, i*sizeof(struct studentTag), SEEK_SET);
        fread(&student, sizeof(struct studentTag), 1, fp_bin);
        fwrite(&student, sizeof(struct studentTag), 1, cpy_bin);
    }
    fclose(fp_bin);
    fclose(cpy_bin);
}

/* CHALLENGE 7:
Perform linear search on the “STUDENTS.BIN” binary file. The user will input the ID number. 
If the ID number is found, the program should print the information about the student.
Otherwise, it should output “NOT FOUND!” 
The search will be repeated until the user inputs a sentinel value of -999, in which case the program outputs
“END SEARCH”.
*/

void Challenge_7(struct studentTag student) {
    FILE *fp_bin = fopen("STUDENTS.BIN", "rb");
    if (fp_bin == NULL) {
        printf("ERROR: File STUDENTS.BIN not found\n");
        exit(1);
    }
    int ID;
    do {
        printf("\nInput ID for search: ");
        scanf("%d", &ID);
        fseek(fp_bin, 0, SEEK_SET); // reset file pointer
        int found = 0;
        while (fread(&student, sizeof(struct studentTag), 1, fp_bin) == 1) {
            if (ID == student.ID) {
                printf("%d %s %s %.1f\n", student.ID, student.name.first, student.name.last, student.grade);
                found = 1;
                break;
            }
        }
        if (!found)
            printf("NOT FOUND!\n");
    } while (ID != -999);

    printf("END SEARCH\n");
    fclose(fp_bin);
}

int main() {
    struct studentTag student;
    Challenge_1(student);
    Challenge_2(student);
    Challenge_3(student);
    Challenge_4(student);
    Challenge_5(student);
    Challenge_6(student);
    Challenge_7(student);
    return 0;
}