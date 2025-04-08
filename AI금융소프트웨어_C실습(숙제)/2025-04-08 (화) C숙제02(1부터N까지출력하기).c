#include <stdio.h>

void main() {
    int n;
    scanf_s("%d", &n);
    int i = 1;
    if (n >= 1) {
        while (i <= n) {
            printf("%d ", i);
            i++;
        }// while 
    } else {
        printf("1 이상의 정수를 입력하세요");
    }
}// main
