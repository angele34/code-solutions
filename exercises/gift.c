#include <stdio.h>

int main() {
    int persons;
    printf("Enter number of persons who dropped out: ");
    scanf("%d", &persons);
    printf("Original contribution per person: Php1000.00\n");
    float additional = ((10000.00 / (10.00 - persons)) - 1000.00);
    printf("Additional contribution per person: Php%.2f\n", additional);
    printf("Computed contribution per person: Php%.2f\n", additional + 1000.00);
    return 0;
}