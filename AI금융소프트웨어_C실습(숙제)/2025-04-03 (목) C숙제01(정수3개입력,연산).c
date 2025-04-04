#include <stdio.h>

int main() {
    // 수식: (a + b) * c - (a - b) / c
    printf("정수 3개를 입력하세요: ");
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    if ((int)c == 0) {
        printf("0은 입력하실 수 없습니다 sorry");
        return 0;
    }
    int iA = (int)a; int iB = (int)b; int iC = (int)c;
    printf("%d, %d, %d", iA, iB, iC);
    int calcResult = (iA + iB) * iC - (iA - iB) / iC;
    
    printf("\n(%d + %d) x %d - (%d - %d) / %d = %d", iA, iB, iC, iA, iB, iC, calcResult);
    
    return 0;
}
