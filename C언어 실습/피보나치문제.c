#include <stdio.h>

void printFibo() {
    int y = 0;
    int x = 1;
    int sum;
    int nums;
    int total = 0;
    int evenCount = 0;
    int oddCount = 0;
    printf("몇 개를 출력할까요? ");
    scanf("%d", &nums);
    
    for (int i = 0; i < nums; i++) {
        sum = x + y;
        x = y;
        y = sum;
        
        total = total + y;
        printf("%d ", y);
        
        if (y % 2 == 0) {
            evenCount++;
        } else if (y % 2 == 1) {
            oddCount++;
        }
    }
    printf("\n합: %d", total);
    printf("\n홀/짝 : %d/%d", oddCount, evenCount);    
};

void main() {
    printFibo();
}
