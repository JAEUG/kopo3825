#include <stdio.h>

void main() {
	int inputNum; 
	int dummy = scanf("%d", &inputNum); // ����� �Է�
	int numberOfStars = inputNum; // �� �ٿ� �μ�� ���� ����
	// ����� �Է°��� 1 �̻����� ����
	if (inputNum > 0) {
		for (int i = 0; i < inputNum; i++) {
			for (int j = numberOfStars; j > 0; j--) { 
				printf("*");
			}// for
			printf("\n");
			numberOfStars--; // ���� �ٲ���� ���� ������ �����ϰ� 
		}// for
	} else {
		printf("1�̻��� ������ �Է��ϼ���");
	}
}// main