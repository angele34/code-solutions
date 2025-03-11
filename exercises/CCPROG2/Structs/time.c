/*
Define a structure named Time with members hours, minutes, and seconds. 
Write a C program to input two times, add them, and display the result in proper time format.
*/

#include <stdio.h>

typedef struct {
    int hours;
    int minutes;
    int seconds;
} Time;

void inputTime(Time time[]) {
    int i = 0;
    while(i < 2) {
        printf("Enter time #%d\n", i+1);
        printf("Hours: ");
        scanf("%d", &time[i].hours);
        printf("Minutes: ");
        scanf("%d", &time[i].minutes);
        printf("Seconds: ");
        scanf("%d", &time[i].seconds);
        i++;
        printf("\n");
    }
}

void addTime(Time time[], Time *result) {
    result->seconds = time[0].seconds + time[1].seconds;
    result->minutes = time[0].minutes + time[1].minutes;
    result->hours = time[0].hours + time[1].hours;

    if (result->seconds >= 60) {
        result->seconds -= 60;
        result->minutes += 1;
    }

    if (result->minutes >= 60) {
        result->minutes -= 60;
        result->hours += 1;
    }
}

void displayTime(Time *result) {
    printf("%d:%d:%d", result->hours, result->minutes, result->seconds);
}

int main() {
    Time time[2];
    Time result = {0};
    inputTime(time);
    addTime(time, &result);
    printf("\n");
    displayTime(&result);
}