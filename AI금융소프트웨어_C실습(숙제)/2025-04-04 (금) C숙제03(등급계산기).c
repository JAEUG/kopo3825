#include <stdio.h>

void main() {
	double score;
	char grade;
	printf("����� ���� ����, �װ��� �˰�ʹ�: "); 
	scanf_s("%lf", &score);
	if (score <= 100 && score >= 0) {
		if (score >= 90 && score <= 100) {
			grade = 'A';
		} else if (score >= 80 && score <= 89) {
			grade = 'B';
		} else if (score >= 70 && score <= 79) {
			grade = 'C';
		}else if (score >= 60 && score <= 69) {
			grade = 'D';
		} else {
			grade = 'F';
		}

		switch (grade) {
			case 'A':
				score = score * 1.1;
				break;
			case 'B':
				score = score * 1.05;
				break;
			default:
				score = score;
				break;
		}// switch

		printf("���ʽ�(�ش�ȴٸ�)�� �ݿ��� ��������: %lf", score);
	} else {
		grade = 0;
		printf("��! ���� �׷� ���� ������ ����ִ�?");

	}// if

}// main
