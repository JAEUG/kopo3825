#include <stdio.h>
void printPyramid(int lines) {

    int pNumber = 1;
    int blanks;
    blanks = lines - 2;
    for (int i = 1; i <= lines; i++) {
        for (int k = blanks; k >= 0; k--) {
            printf("  ");
        }
        
        for (int j = 1; j <= i; j++) {
            printf("%3d ", pNumber);
            pNumber++;
        }
        printf("\n");
        blanks--;
    }    
}

void main() {
    int lines;
    printf("입력값(줄 수):");
    scanf("%d", &lines);    
    printPyramid(lines);
}