#include <stdio.h>

void main() {
	
	int num;
	scanf_s("%d", &num);

	int num100 = num / 100;			// �����ڸ� ��
	int num10 = (num / 10) % 10;	// �����ڸ� ��
	int num1 = num % 10;			// �����ڸ� ��

	printf("�ڸ����� ��: %d", num100 + num10 + num1);

}