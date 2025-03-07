#include <stdio.h>
#include <string.h>


int main() {
    char num[1000];
    scanf("%s", num);

    int freq[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < strlen(num); i++) {
        int count = 0;
        if (num[i] >= '0' && num[i] <= '9') {
            // Get the index by converting the element of array num[] (char) to (int) and increment the digits in array freq[] 
            freq[num[i] - '0']++;
        }
    }
    // Print the elements with a single space
    for (int x = 0; x < 10; x++) {
        printf("%d ", freq[x]);
    }
    return 0;
}

