#include <stdio.h>

int main() {
    // Displacement/distance (meters)
    double s, v, a, t;
    printf("To solve for the displacement, please input the following values\n");

    printf("Initial velocity: ");
    scanf("%lf", &v);

    printf("Time: ");
    scanf("%lf", &t);

    printf("Acceleration: ");
    scanf("%lf", &a);

    // Compute for the displacement
    s = v * t + 0.5 * a * (t * t);

    printf("\n");
    // Convert displacement to yard
    // 1 yard = 0.9144 meters
    printf("The object's displacement is: %.3lf\n", s);
    s /= 0.9144;
    printf("The object's displacement in yards is: %.3lf\n", s);
    return 0;
}