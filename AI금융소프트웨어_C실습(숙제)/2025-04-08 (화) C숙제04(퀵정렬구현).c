#include <stdio.h>
#include <windows.h>
// quick sort: divide and conquer
void swap(int* first, int* second) { // first와 second의 값을 교환
	int temp;
	temp = *second;
	*second = *first;
	*first = temp;
}// swap

void quick(int arr[], int start, int end) {
	if (start >= end) return;// 배열의 크기가(분할되어 재귀호출 되었을때를 생각) 0이 되었을때는 함수를 종료
	int *pArr = &arr[0];	 // 배열 arr를 조작하기 위한 포인터 배열
	int left = start + 1;	 // 왼쪽 포인터
	int right = end;	 // 오른쪽 포인터		
	int pivot = start;	 // pivot위치
	
	while (left <= right) { // 왼쪽 포인터(진행방향:--->)가 오른쪽 포인터(진행방향:<---)와 만날때까지만 실행
		while (left <= end && pArr[left] <= pArr[pivot]) { // 왼쪽 포인터 시작지점(start + 1)부터 배열의 끝까지, 왼쪽포인터가 가리키는 값이 pivot값보다 작거나 같을 동안만
			left++; // 왼쪽 포인터를 -> 로 1칸씩 이동
		}
		while (right > start && pArr[right] >= pArr[pivot]) { // 오른쪽 포인터 시작지점(end) 부터 start + 1까지, 오른쪽 포인터가 가리키는 값이 pivot값보다 크거나 같을 동안만
			right--; // 오른쪽 포인터를 <- 로 1칸씩 이동
		}
	}// while

	if (left >= right) { // 왼쪽 포인터와 오른쪽 포인터가 엇갈렸다면(ex) (left: 3 right: 3) or (left: 4 right: 2))
		swap(&pArr[pivot], &pArr[right]); // right가 가리키는 값과 pivot값을 교체(자리교환) 
	} else { // 왼쪽 포인터와 오른쪽 포인터가 엇갈리기 전에 멈췄다면
		swap(&pArr[right], &pArr[left]); // left가 가리키는 값과 right가 가리키는 값을 교체(자리교환)
	}

	quick(pArr, start, right - 1); // pivot위치 기준으로 분할 - 왼쪽 배열을 인자로 quick재귀호출
	quick(pArr, right + 1, end); // pivot위치 기준으로 분할 - 오른쪽 배열을 인자로 quick재귀호출

	//for (int i = 0; i < arrSize - 1; i++) { // 배열 크기 -1 만큼 반복
	//	pivot = pArr[0]; // pivot값은 pArr[start]; 즉 모든 배열의 0번째 요소
	//	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ 현재 PIVOT Value:: %d  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n", pivot);
	//	printf("<<<<<<<<<<<<<<<<<<<<<< left: %d, right: %d >>>>>>>>>>>>>>>>>>>>>>>>>\n", left, right);
	//	if (left >= right && pivot > right) { // left 와 right가 교차 했음
	//		printf("\n*************** Pivot과 Right가 위치를 서로 바꿉니다 !!***************\n");
	//		swap(&pArr[0], &pArr[right]);
	//		for (int q = 0; q < arrSize; q++) {
	//			printf("(((%d)))  ", pArr[q]);
	//		}//
	//		Sleep(2000);
	//		printf("\n\n\n\n\n\n\n=========================== ▼ 왼쪽 재귀 호출 START ===========================\n");
	//		quick(pArr, 0, right - 1);	// 재귀 함수 호출(pivot기준으로 왼쪽 배열)
	//		printf("\n\n\n\n\n\n\n=========================== ▼ 오른쪽 재귀 호출 START ===========================\n");
	//		quick(pArr, right + 1, end);		// 재귀 함수 호출(pivot기준으로 오른쪽 배열)
	//		// call quick() here?
	//	}// if
	//	if (arr[left] > pivot && leftFlag != 1) {
	//		biggerThanPivotIndex = left;
	//		leftFlag = 1; // left가 -> 쪽으로 탐색하다가 pivot보다 큰 값을 발견했음!
	//		printf("@left: I found it!  biggerThanPivotIndex is $[%d]$!!  ", biggerThanPivotIndex);
	//	}// if
	//	if (arr[right] < pivot && rightFlag != 1) {
	//		smallerThanPivotIndex = right;
	//		rightFlag = 1; // right가 <- 쪽으로 탐색하다가 pivot보다 작은 값을 발견했음!
	//		printf("@right: I found it!  smallerThanPivotIndex is $[%d]$!!  ", smallerThanPivotIndex);
	//	}// if
	//	if (left == right) {
	//		isCrossed = 1; // left 와 right가 탐색하다가 같은 index 위치에서 만났음!
	//	}
	//	// left 와 right가 만나지 않았을때 ...left-> 랑데뷰포인트  <- right...
	//	if (isCrossed != 1 && leftFlag == 1 && rightFlag == 1) { // pivot보다 큰 값과 작은 값 둘 모두를 찾았을때
	//		printf("\nsmallerThanPivotIndex is $$&& %d &&$$!!  biggerThanPivotIndex is $$&& %d &&$$!!   ", smallerThanPivotIndex, biggerThanPivotIndex);
	//		printf("\n|||||||||||||||||*************** pivot보다 큰 값과 작은 값이 서로 위치를 바꿉니다 !!***************|||||||||||||||||\n");
	//		swap(&pArr[smallerThanPivotIndex], &pArr[biggerThanPivotIndex]); // 두 요소를 swap(자리교체)
	//		leftFlag = 0;	// flag 초기화
	//		rightFlag = 0;	// flag 초기화
	//		left++;  // left 커서를 오른쪽으로 한 칸 이동
	//		right--; // right 커서를 왼쪽으로 한 칸 이동
	//		continue;
	//	}// if
	//	
	//	if (leftFlag != 1) left++;		// left가 pivot보다 큰 값을 발견하지 못했으면 left의 커서를 오른쪽으로 한 칸 이동
	//	if (rightFlag != 1) right--;	// right가 pivot보다 작은 값을 발견하지 못했으면 right의 커서를 왼쪽으로 한 칸 이동
	//	//printf("left: <%d>, right: <%d>\n", left, right); // left와 right 현재 커서 위치 출력
	//	printf("\n◆◆◆◆◆ for문 끝에서 찍어보는 pArr 스테이터스: ");
	//	for (int k = 0; k < arrSize; k++) {
	//		printf("(%d) ", pArr[k]);
	//		if (k == arrSize - 1) printf("\n\n");
	//	}// for
	//}// for

	//printf("\n■■■■■■■■■ 함수 끝에서 찍어보는 pArr 스테이터스: ");
	//for (int i = 0; i < arrSize; i++) {
	//	printf("|<<[ %d ]>>|  ", pArr[i]);
	//}

}// quick

void main() {
	int arr[] = {5, 4, 3, 2, 1};
	int arrSize = sizeof(arr) / sizeof(int);

	for (int i = 0; i < arrSize; i++) {
		printf(".%d. ", arr[i]);
	}//

	quick(arr, 0, arrSize - 1);
	printf("\n\n");
	
	for (int i = 0; i < arrSize; i++) {
		printf("<<%d>>  ", arr[i]);
	}

}// main
