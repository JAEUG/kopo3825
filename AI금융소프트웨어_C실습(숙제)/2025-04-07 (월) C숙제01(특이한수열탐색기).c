#include <stdio.h>
// Ư���� ���� Ž����
void main() {
	int m, n;

	int dummy = scanf("%d %d", &m, &n);

	if (n >= m && n > 0 && m > 0) {
		for (int i = m; i <= n; i++) {
			if (i % 7 == 0 || i % 10 == 7 || (i / 10) % 10 == 7 || i / 100 == 7 || i / 1000 == 7 || i / 10000 == 7) {
				continue;
			}
			printf("[%d]  ", i);
			if (i % 5 == 0) {
				break;
			}
		}// for
	} else {
		printf("m�� n�� �Է°��� 0�̻��� �ϸ�, n�� �Է°��� m�� �Է°����� ũ�ų� ���ƾ��մϴ�.");
	}
}// main