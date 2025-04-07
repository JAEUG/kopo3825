#include <stdio.h>

void main() {
	double score;
	char grade;
	printf("당신의 시험 점수, 그것이 알고싶다: "); 
	scanf("%lf", &score);
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

		printf("보너스(해당된다면)가 반영된 시험점수: %lf", score);
	} else {
		grade = 0;
		printf("얘! 세상에 그런 시험 점수가 어디있니?");

	}// if

}// main
