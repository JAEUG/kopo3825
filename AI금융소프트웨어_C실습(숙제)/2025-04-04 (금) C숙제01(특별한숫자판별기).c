#include <stdio.h>
// 특별한수가 되기 위한 조건: 3의배수&홀수 or 숫자의 각 자리 숫자의 합이 7의 배수 or 숫자의 첫번째 자리 숫자가 마지막 자리 숫자보다 크다
void main() {
	double fNum;
	int num;
	int num100;
	int num10;
	int num1;
	scanf("%lf", &fNum); // 실수 입력을 일단 허용
	num = (int)fNum; // 실제 is특별 검사는 정수값으로
	num100 = num / 100;		// 백의자리
	num10 = (num / 10) % 10;// 십의자리
	num1 = num % 10;		// 일의자리
	printf("******************* [%d]를 입력하셨군요!! ********************\n", num);
	if (num >= 0 && num <= 999) { // 입력할 수 있는 숫자의 범위는 0~999까지 제한
		if (num > 0 && num <= 9) { // 유저 입력이 0~9까지의 숫자일때
			if ((num % 3 == 0) && (num % 2 == 1) || (num1 % 7 == 0)) { // 일의자리만 존재
				printf("유저님이 입력하신 [%d] <- 이 숫자는 매우 특별한 숫자입니다 아주 특별해요!!", num);
			} else {
				printf("%d은 특별하지 않아요...", num);
			}// if
		} else if (num >= 10 && num <= 99) { // 유저 입력이 10~99까지의 숫자일때
			if ((num % 3 == 0) && (num % 2 == 1) || ((num1 + num10) % 7 == 0) || num10 > num1) { // 일의자리, 십의자리 존재
				printf("유저님이 입력하신 [%d] <- 이 숫자는 매우 특별한 숫자입니다 아주 특별해요!!", num);
			} else {
				printf("%d은 특별하지 않아요...", num);
			}// if			
		} else if (num >= 100 && num <= 999) { // 유저 입력이 100~999까지의 숫자일때
			if ((num % 3 == 0) && (num % 2 == 1) || ((num1 + num10 + num100) % 7 == 0) || num100 > num1) { // 일의자리, 십의자리, 백의자리 존재
				printf("유저님이 입력하신 [%d] <- 이 숫자는 매우 특별한 숫자입니다 아주 특별해요!!", num);
			} else {
				printf("%d은 특별하지 않아요...", num);
			}// if
		} else { // 0~999까지의 입력중에 1~999까지의 경우를 제외하고 나면 0이 남는다
			printf("이런! 0은 특별하지 않습니다!!");
		}// if
	} else {
		printf("0부터 999까지의 숫자만 입력하실 수 있답니다");
	}// if

}//
