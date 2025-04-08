#include <stdio.h>

void main() {
	int inputNum; 
	int dummy = scanf("%d", &inputNum); // 사용자 입력
	int numberOfStars = inputNum; // 한 줄에 인쇄될 별의 갯수
	// 사용자 입력값은 1 이상으로 제한
	if (inputNum > 0) {
		for (int i = 0; i < inputNum; i++) {
			for (int j = numberOfStars; j > 0; j--) { 
				printf("*");
			}// for
			printf("\n");
			numberOfStars--; // 줄이 바뀔수록 별의 갯수가 감소하게 
		}// for
	} else {
		printf("1이상의 정수를 입력하세요");
	}
}// main