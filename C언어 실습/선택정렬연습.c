#include <stdio.h>
// 죽이고 싶은 선택정렬과의 n선
void main() {
	int arr[] = {7000, 12312, 7549, 12000, 11, 9999};
	int arrLength = sizeof(arr) / sizeof(int);
	int arrIndex = 0;
	int tmp = arr[arrIndex];
	int arrLoc = 0;
	int minLoc;
	int j;
	for (int i = 0; i < arrLength; i++) {
		tmp = arr[arrIndex]; // tmp 초기화
		minLoc = arrIndex; // 이거를 안해서... 이거를 안해서!!! 이거를 몰라서 ㅠㅠ 이게 키 였다는 말이냐!!
		printf("그래서 tmp의 값이 뭔데: %d\n", tmp);
		printf("★ arrIndex(바깥 for문 사이클마다 1씩 증가하는 인덱스 값): %d\n", arrIndex);
		printf("● arr(바깥 for문 사이클마다 배열의 0번째 값만 보기): %d\n", arr[i]);
		// arrLoc = arrIndex;
		for (j = i; j < arrLength; j++) {
			// printf("arrLoc(안쪽 for문에서 1씩 증가하는 인덱스 값)의 값: %d\n", arrLoc);
			if (tmp > arr[j]) {
				tmp = arr[j];
				//arr[j] = arr[arrIndex];
				//arr[arrIndex] = tmp;
				minLoc = j;

				// arr[minLoc] = arr[arrIndex];
				// arr[arrIndex] = tmp;
				printf("최소값 위치: %d\n", minLoc);
			}
		}// for
		printf("------------------------------------사이클마다 최소값(안쪽 for문이 끝날때마다 선정되는 최소값): %d\n", tmp);
		// 무조건 실행되는 부분이니깐 대입되는 값이 위에서 변하는 경우와, 변하지 않는 경우를 모두 생각해줘야한다 ㅠㅠ
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