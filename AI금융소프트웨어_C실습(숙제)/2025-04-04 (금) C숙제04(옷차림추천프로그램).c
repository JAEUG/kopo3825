#include <stdio.h>

void main() {
	double temp;
	int outfitRecomm = 0;
	printf("���� �µ��� �� ���ΰ���? ");
	scanf_s("%lf", &temp);

	if (temp >= 30) {
		outfitRecomm = 1;
	} else if (temp >= 25) {
		outfitRecomm = 2;
	} else if (temp >= 15) {
		outfitRecomm = 3;
	} else if (temp >= 5) {
		outfitRecomm = 4;
	} else if (temp >= 0) {
		outfitRecomm = 5;
	} else {
		outfitRecomm = 6;
	}// if

	switch (outfitRecomm) {
		case 1:
			printf("�ʹ� ������! ���Ȱ� �ݹ����� ��������.");
			break;
		case 2:
			printf("������ �����Դϴ�! ������ ���� ��������.");
			break;
		case 3:
			printf("������ �����Դϴ�! ������ �ѿ��� ì�⼼��.");
			break;
		case 4:
			printf("���� �ҽ��մϴ�! ������ ���� ��������.");
			break;
		case 5:
			printf("�ſ� ����ϴ�! �β��� ������ �� ��������.");
			break;
		case 6:
			printf("���� ���! �е��� �尩, ���ڸ� �����ϼ���.");
			break;
		default:
			printf("INTERNAL SYSTEM ERROR OCCURED");
			break;
	}// switch

}// main