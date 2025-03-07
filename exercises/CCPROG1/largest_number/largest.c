int main() {
    int nNum, nMax = 0;
    do {
        printf("Enter a number: ");
        scanf("%d", &nNum);
        if (nNum > nMax) {
            nMax = nNum;
        }
    } while (nNum != 0);
    printf("The largest number entered is: %d\n", nMax);
    return 0;
}