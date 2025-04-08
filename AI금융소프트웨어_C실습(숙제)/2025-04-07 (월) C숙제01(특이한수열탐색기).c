#include <stdio.h>
// 특이한 수열 탐색기
void main() {
	int m, n;

	int dummy = scanf("%d %d", &m, &n);

	if (n >= m && n > 0 && m > 0) {
		for (int i = m; i <= n; i++) {
			if (i % 7 == 0 || i % 10 == 7 || (i / 10) % 10 == 7 || i / 100 == 7 || i / 1000 == 7 || i / 10000 == 7 || i / 100000 == 7 || i / 1000000 == 7 || i / 1000000 == 7 || i / 10000000 == 7 || i / 100000000 == 7) {
				continue;
			}
			printf("[%d]  ", i);
			if (i % 5 == 0) {
				break;
			}
		}// for
	} else {
		printf("m과 n의 입력값은 0이상어야 하며, n의 입력값은 m의 입력값보다 크거나 같아야합니다.");
	}
}// main
