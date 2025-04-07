#include <stdio.h>
// 이중 for문을 활용해서 202001부터 202504까지 출력하고 (2020년 1월 ~ 2025년 4월)
// 중간에 202302 ~ 202305는 스킵하기 (2023년 2월 ~ 2023년 5월은 스킵)
void main() {
	// 이중 for문 바깥 for문: 년
	// 안쪽 for문: 월
	for (int i = 2020; i <= 2025; i++) {
		for (int j = 1; j <= 9; j++) {
			if (i == 2023 && (j >= 2 && j <= 5)) { // 2023년 02월 ~ 2023년 05은 skip
				printf("생략되었습니다.\n");
				continue;
			}
			if (i == 2025 && j >= 5) { // 2025년은 05월부터 skip(04월까지만)
				continue;
			}
			printf("%d0%d\n", i, j);
		}// for
	}// for

}// main
