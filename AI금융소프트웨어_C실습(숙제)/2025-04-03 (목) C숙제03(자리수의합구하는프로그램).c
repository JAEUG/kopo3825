#include <stdio.h>

void main() {
	
	int num;
	scanf_s("%d", &num);

	int num100 = num / 100;			// 백의자리 값
	int num10 = (num / 10) % 10;	// 십의자리 값
	int num1 = num % 10;			// 일의자리 값

	printf("자리수의 합: %d", num100 + num10 + num1);

}