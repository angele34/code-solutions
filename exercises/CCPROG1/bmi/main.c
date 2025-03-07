#include "bmi.c"

int main() {
    int nHeight, nWeight;
    printf("Enter your Height in inches: ");
    scanf("%d", &nHeight);
    printf("Enter your Weight in pounds: ");
    scanf("%d", &nWeight);

    float convertInchesToMeters(int nHeight);
    float convertPoundsToKg(int nWeight);
    float BMI = getBMI(nHeight, nWeight);
    printf("Your BMI is: %.2f\n", BMI);
    return 0;
}