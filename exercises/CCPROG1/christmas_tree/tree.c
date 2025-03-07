/* Christmas Tree Exercise */

#include "tree.h"

int validateInput(int nValue) {
  if (nValue % 2 == 1 && nValue >= 3) {
    return TRUE;
  }
  return FALSE; 
}

void displayTree(int nSize) {
  // Print Christmas Tree
  for (int i = 1; i <= nSize + 2; i++) {
    for (int j = 0; j < nSize + 2 - i; j++) {
      printf(" ");
    }
    for (int j = 0; j < 2*i-1; j++) {
      printf("*");
    }
    printf("\n");
  }
  
  // Print the tree legs
  for (int i = 0; i < nSize / 2 + 1; i++) {
    for (int j = 0; j < (nSize/2) + 2; j++) {
      printf(" ");
    }
    for (int j = 0; j < nSize; j++) {
      printf("*");
    }
    printf("\n");
  }
}

void displayInvertedTree(int nSize)
{
  // Print the tree legs first
  for (int i = 0; i < nSize / 2 + 1; i++) {
    for (int j = 0; j < (nSize/2) + 2; j++) {
      printf(" ");
    }
    for (int j = 0; j < nSize; j++) {
      printf("*");
    }
    printf("\n");
  }
  // Print inverted tree
  for (int i = nSize + 2; i >= 1; i--) {
    for (int j = 0; j < nSize + 2 - i; j++) {
      printf(" ");
    }
    for (int j = 0; j < 2*i-1; j++) {
      printf("*");
    }
    printf("\n");
  }
}
