#include <stdio.h>
#include <stdlib.h> // abs함수 이용하기 위해 include
// abs함수: 정수 입력을 절대값 처리하여 return
void main() {
	
	int num;
	scanf("%d", &num);
    	if (num <= 999 && num >= -999) {
	    	int num100 = abs(num) / 100;		// 백의자리 값
	    	int num10 = abs((num / 10)) % 10;	// 십의자리 값
	    	int num1 = abs(num) % 10;		// 일의자리 값
		printf("자리수의 합: %d", num100 + num10 + num1);
	} else {
	        printf("정수(최대3자리)를 입력하세요");
	}// if
    
}// main
