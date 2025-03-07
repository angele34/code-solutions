#include <stdio.h>

// uncomment the main files to get output

void getCoordinates(int store, int *xCoordinate, int *yCoordinate) {
    *yCoordinate = store % 100;
    store /= 100;
    *xCoordinate = store % 100;
}

int getMidpoint(int c1, int c2) {
    int y = ((c1 % 100) + (c2 % 100)) / 2;
    int x = ((c1 / 100) + (c2 / 100)) / 2;
    return x*100+y;
}

float getPerpendicularSlope(int *x1, int *y1, int *x2, int *y2) {
    if (*y1 == *y2) {
        return 1.0;
    }
    float x = *x2-*x1;
    float y = *y1-*y2;
    return x / y;
}

void getLineInfo(int q, int m, int *a, int *b, int *c) {
    int xCoordinate, yCoordinate;
    *a = (q % 10) * -1;
    *b = 1;
    getCoordinates(q, &xCoordinate, &yCoordinate);
    *c = -yCoordinate  + (m*xCoordinate);
}

void solveTheMystery(int line1Pt1, int line1Pt2, int line2Pt1, int line2Pt2) {
    int c1, c2;
    getMidpoint(line1Pt1, line1Pt2);
    int x1,y1,x2,y2;
    getPerpendicularSlope(line1Pt1, line2Pt1, &x1, &y1);
    getPerpendicularSlope(line1Pt1, line2Pt1, &x2, &y2);
    
}

// main for solvethemystery
int main() {

}
// main for getlineinfo
// int main() {
//     int q, m, a, b, c;

//     printf("q: ");
//     scanf("%d", &q);
//     printf("slope: ");
//     scanf("%d", &m);
//     getLineInfo(q, m, &a, &b, &c);
//     printf("a: %d\n", a);
//     printf("b: %d\n", b);
//     printf("c: %d\n", c);
//     return 0;
// }

// main for perpendicular slope cause im lazy to combine them all
// int main() {
//     int w,x,y,z;
//     printf("Enter x1: ");
//     scanf("%d", &w);
//     printf("Enter y1: ");
//     scanf("%d", &y);
//     printf("Enter x2: ");
//     scanf("%d", &x);
//     printf("Enter y2: ");
//     scanf("%d", &z);
//     float slope = getPerpendicularSlope(&w, &x, &y, &z);
//     printf("%.1f", slope);
// }

// main for midpoint
// int main() {
//     int c1, c2;
//     printf("c1: ");
//     scanf("%d", &c1);
//     printf("c2: ");
//     scanf("%d", &c2);
//     int midpoint = getMidpoint(c1,c2);
//     printf("%d", midpoint);
// }

// main for getCoordinates
// int main() {
//     int store, x, y;
//     printf("store: ");
//     scanf("%d", &store);
//     getCoordinates(store, &x, &y);
//     printf("a: %d b: %d", x, y);
//     return 0;
// }