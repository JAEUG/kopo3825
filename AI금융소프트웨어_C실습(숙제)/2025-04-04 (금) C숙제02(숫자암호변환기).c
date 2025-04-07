#include <stdio.h>

void main() {
	// 사용자가 0~9 사이의 숫자를 입력하면, 특정 규칙에 따라 변환된 암호 값을 출력하는 프로그램
	int num;
	printf("0~9사이의 숫자를 입력하세요 ");
	scanf("%d", &num);

	switch (num) {
		case 0:
			printf("0 -> A");
			break;
		case 1:
			printf("1 -> B");
			break;
		case 2:
			printf("2 -> C");
			break;
		case 3:
			printf("3 -> D");
			break;
		case 4:
			printf("4 -> E");
			break;
		case 5:
			printf("5 -> F");
			break;
		case 6:
			printf("6 -> G");
			break;
		case 7:
			printf("7 -> H");
			break;
		case 8:
			printf("8 -> I");
			break;
		case 9:
			printf("9 -> J");
			break;
		default:
			printf("잘못된 입력입니다!");
			break;
	}

}
