#include <stdio.h>

void main() {
	// ����ڰ� 0~9 ������ ���ڸ� �Է��ϸ�, Ư�� ��Ģ�� ���� ��ȯ�� ��ȣ ���� ����ϴ� ���α׷�
	int num;
	printf("0~9������ ���ڸ� �Է��ϼ��� ");
	scanf_s("%d", &num);

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
			printf("�߸��� �Է��Դϴ�!");
			break;
	}

}