#include <stdio.h>
// ���̰� ���� �������İ��� n��
void main() {
	int arr[] = {7000, 12312, 7549, 12000, 11, 9999};
	int arrLength = sizeof(arr) / sizeof(int);
	int arrIndex = 0;
	int tmp = arr[arrIndex];
	int arrLoc = 0;
	int minLoc;
	int j;
	for (int i = 0; i < arrLength; i++) {
		tmp = arr[arrIndex]; // tmp �ʱ�ȭ
		minLoc = arrIndex; // �̰Ÿ� ���ؼ�... �̰Ÿ� ���ؼ�!!! �̰Ÿ� ���� �Ф� �̰� Ű ���ٴ� ���̳�!!
		printf("�׷��� tmp�� ���� ����: %d\n", tmp);
		printf("�� arrIndex(�ٱ� for�� ����Ŭ���� 1�� �����ϴ� �ε��� ��): %d\n", arrIndex);
		printf("�� arr(�ٱ� for�� ����Ŭ���� �迭�� 0��° ���� ����): %d\n", arr[i]);
		// arrLoc = arrIndex;
		for (j = i; j < arrLength; j++) {
			// printf("arrLoc(���� for������ 1�� �����ϴ� �ε��� ��)�� ��: %d\n", arrLoc);
			if (tmp > arr[j]) {
				tmp = arr[j];
				//arr[j] = arr[arrIndex];
				//arr[arrIndex] = tmp;
				minLoc = j;

				// arr[minLoc] = arr[arrIndex];
				// arr[arrIndex] = tmp;
				printf("�ּҰ� ��ġ: %d\n", minLoc);
			}
		}// for
		printf("------------------------------------����Ŭ���� �ּҰ�(���� for���� ���������� �����Ǵ� �ּҰ�): %d\n", tmp);
		// ������ ����Ǵ� �κ��̴ϱ� ���ԵǴ� ���� ������ ���ϴ� ����, ������ �ʴ� ��츦 ��� ����������Ѵ� �Ф�
		arr[minLoc] = arr[arrIndex];
		arr[arrIndex] = tmp;
		arrIndex++;

		for (int z = 0; z < 6; z++) {
			printf("[%d] ", arr[z]);
		}
		printf("\n");

	}// for
	
	for (int i = 0; i < arrLength; i++) {
		printf("\n%d ", arr[i]);
	}// for

}