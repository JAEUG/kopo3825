#include <stdio.h>

void main() {
	int inputNum;
	int dummy = scanf("%d", &inputNum);
	int numberOfStars = inputNum;
	
	for (int i = 0; i < inputNum; i++) {
		for (int j = numberOfStars; j > 0; j--) {
			printf("*");
		}// for
		printf("\n");
		numberOfStars--;
	}// for

}// main
