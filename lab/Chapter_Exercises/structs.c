#include <stdio.h>

#define INT_MAX 99999
#define FLOAT_MAX 99999.00

struct aTag {
    char ch;
    int i;
};

struct bTag {
    float f;
    double d;
};
struct cTag {
    struct aTag a;
    struct bTag b;
    int A[5];
};

typedef struct aTag aType; 
typedef struct bTag bType; 
typedef struct cTag cType;

aType a, A[5];
bType b, B[5];
cType c, C[5];
aType *pa;
bType *pb;
cType *рс;

void InputFunc1(cType *ptr) { // 3.2
    scanf(" %c %i %f %d", &(*ptr).a.ch, &(*ptr).a.i, &(*ptr).b.f, &(*ptr).b.d);
    for (int i = 0; i < 5; i++) {
        scanf("%d", &(*ptr).A[i]);
        for (int j = 0; j < 5; j++) {
            scanf("%d", &(*ptr).A[j]);
        }
    }
}

cType InputFunc2(void) { // 3.3
    cType temp;
    scanf(" %c %i %f %d", &temp.a.ch, &temp.a.i, &temp.b.f, &temp.b.d);
    for (int i = 0; i < 5; i++) {
        scanf("%d", &temp.A[i]);
        for (int j = 0; j < 5; j++) {
            scanf("%d", &temp.A[j]);
        }
    }
    return temp;
}

void InputFunc3(cType C[], int n) { // 3.4
    for (int i = 0; i < n; i++) {
        scanf("%d", &C[i]);
    }
}


void OutputFunc1(cType *ptr) { // 3.5
    printf("%c %d %.2f %lf\n", (*ptr).a.ch, (*ptr).a.i, (*ptr).b.f, (*ptr).b.d);
    int i;
    for (int i = 0; i < 5; i++) {
        printf("%d", (*ptr).A[i]);   
     }
}

void OutputFunc2(cType *ptr) { // 3.6
    printf("%c %d %.2f %lf\n", ptr->a.ch, ptr->a.i, ptr->b.f, ptr->b.d);
    for (int i = 0; i < 5; i++) {
        printf("%d", ptr->A[i]);
    }
}

void OutputFunc3(cType C[], int n) { // 3.7
    for (int i = 0; i < n; i++) {
        printf("%c %d %.2f %lf\n", C[i].a.ch, C[i].a.i, C[i].b.f, C[i].b.d);
        for (int j = 0; j < 5; j++) {
            printf("%d", C[i].A[j]);
        }
        printf("\n");
    }
}

void OutputFunc4(cType C[], int n) { // 3.8
    for (int i = 0; i < n; i++) {
        printf("%c %d %.2f %lf\n", C[i].a.ch, C[i].a.i, C[i].b.f, C[i].b.d);
        for (int j = 0; j < 5; j++) {
            printf("%d", (C+i)->A[j]);
        }
    }
}

int Total1(aType A[], int n) { // 3.9
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i].i;
    }
    return sum;
}

int Total2(cType c) { // 3.10
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += c.A[i];
    }
    return sum;
}

int Total3(cType C[], int n) { // 3.11
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            sum += C[i].A[j];
        }
    }
    return sum;
}

int Minimum(cType c) { // 3.12
    int min = INT_MAX, minIdx = -1;
    for (int i = 0; i < 5; i++) {
        if (c.A[i] < min) {
            min = c.A[i];
            minIdx = i;
        }
    }
    return minIdx;
}

float fMinimum(bType B[], int n) { // 3.13
    float min = FLOAT_MAX, minIdx = -1;
    for (int i = 0; i < n; i++) {
        if (B[i].f < min) {
            min = B[i].f;
            minIdx = i;
        }
    }
    return minIdx;
}

double dMaximum(bType B[], int n) { // 3.14
    double largest = -1;
    int i, largestIdx = -1;
    for(i = 0; i < n; i++) {
        if (B[i].d > largest) {
            largest = B[i].d;
            largestIdx = i;
        }
    }
    return largestIdx;
}

void SortFunc1(aType A[], int n) { // 3.15
    int i,j, min;
    for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++) {
            if (A[j].i < A[min].i)
                min = j;
        }
        if (i!=min) {
            aType temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }
    }
}

void SortFunc2(bType B[], int n) { // 3.16
    int i,j, max;
    for (i = 0; i < n-1; i++) {
        max = i;
        for (j = i+1; j < n; j++) {
            if (B[j].d > B[max].d)
                max = j;
        }
        if (i!=max) {
            bType temp = B[i];
            B[i] = B[max];
            B[max] = temp;
        }
    }
}

void CopyFunc(cType sourceArr[], cType destArr[], int n) { // 3.17
    int i;
    for (i = 0; i < n; i++) {
        destArr[i] = sourceArr[i];
    }
}

int main() {
    cType ptr;
    ptr.a.ch = 'T';
    ptr.a.i = 1;
    ptr.b.f = 2.43;

    OutputFunc1(&ptr);
    OutputFunc2(&ptr);
}