#include <stdio.h>

void main() {
    int n;
    scanf("%d", &n);
    int i = 1;
    if (n >= 1) {
        while (i <= n) { // for문처럼 증감이 루프마다 자동으로 되는게 아니기 때문에( for문도 증감 부분을 따로 빼서 쓸 수 있긴하더라... ) 
            if (i % 2 == 1) {
                i++;    // continue가 있을때는 조건이 True일때 바로 루프의 시작지점으로 돌아가기 때문에 continue를 하기 전에 i를 증가시켜줘야 한다!
                continue;
            }
            printf("%d ", i);
            i++;        // 위에 continue가 있으면 이 부분(i를 증가시키는)이 실행이 안된다
        }// while 
    } else {
        printf("1이상의 정수를 입력하세요");
    }
}// main
