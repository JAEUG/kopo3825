#include <stdio.h>
#include <windows.h>
// quick sort: divide and conquer
void swap(int* first, int* second) { // first�� second�� ���� ��ȯ
	int temp;
	temp = *second;
	*second = *first;
	*first = temp;
}// swap

void quick(int arr[], int start, int end) {
	if (start >= end) return;// �迭�� ũ�Ⱑ(���ҵǾ� ���ȣ�� �Ǿ������� ����) 0�� �Ǿ������� �Լ��� ����
	int *pArr = &arr[0];	 // �迭 arr�� �����ϱ� ���� ������ �迭
	int left = start + 1;	 // ���� ������
	int right = end;		 // ������ ������		
	int pivot = start;		 // pivot��ġ
	
	while (left <= right) { // ���� ������(�������:--->)�� ������ ������(�������:<---)�� ������������ ����
		while (left <= end && pArr[left] <= pArr[pivot]) { // ���� ������ ��������(start + 1)���� �迭�� ������, ���������Ͱ� ����Ű�� ���� pivot������ �۰ų� ���� ���ȸ�
			left++; // ���� �����͸� -> �� 1ĭ�� �̵�
		}
		while (right > start && pArr[right] >= pArr[pivot]) { // ������ ������ ��������(end) ���� start + 1����, ������ �����Ͱ� ����Ű�� ���� pivot������ ũ�ų� ���� ���ȸ�
			right--; // ������ �����͸� <- �� 1ĭ�� �̵�
		}
	}// while

	if (left >= right) { // ���� �����Ϳ� ������ �����Ͱ� �����ȴٸ�(ex) (left: 3 right: 3) or (left: 4 right: 2))
		swap(&pArr[pivot], &pArr[right]); // right�� ����Ű�� ���� pivot���� ��ü(�ڸ���ȯ) 
	} else { // ���� �����Ϳ� ������ �����Ͱ� �������� ���� ����ٸ�
		swap(&pArr[right], &pArr[left]); // left�� ����Ű�� ���� right�� ����Ű�� ���� ��ü(�ڸ���ȯ)
	}

	quick(pArr, start, right - 1); // pivot��ġ �������� ���� - ���� �迭�� ���ڷ� quick���ȣ��
	quick(pArr, right + 1, end); // pivot��ġ �������� ���� - ������ �迭�� ���ڷ� quick���ȣ��

	//for (int i = 0; i < arrSize - 1; i++) { // �迭 ũ�� -1 ��ŭ �ݺ�
	//	pivot = pArr[0]; // pivot���� pArr[start]; �� ��� �迭�� 0��° ���
	//	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ ���� PIVOT Value:: %d  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n", pivot);
	//	printf("<<<<<<<<<<<<<<<<<<<<<< left: %d, right: %d >>>>>>>>>>>>>>>>>>>>>>>>>\n", left, right);
	//	if (left >= right && pivot > right) { // left �� right�� ���� ����
	//		printf("\n*************** Pivot�� Right�� ��ġ�� ���� �ٲߴϴ� !!***************\n");
	//		swap(&pArr[0], &pArr[right]);
	//		for (int q = 0; q < arrSize; q++) {
	//			printf("(((%d)))  ", pArr[q]);
	//		}//
	//		Sleep(2000);
	//		printf("\n\n\n\n\n\n\n=========================== �� ���� ��� ȣ�� START ===========================\n");
	//		quick(pArr, 0, right - 1);	// ��� �Լ� ȣ��(pivot�������� ���� �迭)
	//		printf("\n\n\n\n\n\n\n=========================== �� ������ ��� ȣ�� START ===========================\n");
	//		quick(pArr, right + 1, end);		// ��� �Լ� ȣ��(pivot�������� ������ �迭)
	//		// call quick() here?
	//	}// if
	//	if (arr[left] > pivot && leftFlag != 1) {
	//		biggerThanPivotIndex = left;
	//		leftFlag = 1; // left�� -> ������ Ž���ϴٰ� pivot���� ū ���� �߰�����!
	//		printf("@left: I found it!  biggerThanPivotIndex is $[%d]$!!  ", biggerThanPivotIndex);
	//	}// if
	//	if (arr[right] < pivot && rightFlag != 1) {
	//		smallerThanPivotIndex = right;
	//		rightFlag = 1; // right�� <- ������ Ž���ϴٰ� pivot���� ���� ���� �߰�����!
	//		printf("@right: I found it!  smallerThanPivotIndex is $[%d]$!!  ", smallerThanPivotIndex);
	//	}// if
	//	if (left == right) {
	//		isCrossed = 1; // left �� right�� Ž���ϴٰ� ���� index ��ġ���� ������!
	//	}
	//	// left �� right�� ������ �ʾ����� ...left-> ����������Ʈ  <- right...
	//	if (isCrossed != 1 && leftFlag == 1 && rightFlag == 1) { // pivot���� ū ���� ���� �� �� ��θ� ã������
	//		printf("\nsmallerThanPivotIndex is $$&& %d &&$$!!  biggerThanPivotIndex is $$&& %d &&$$!!   ", smallerThanPivotIndex, biggerThanPivotIndex);
	//		printf("\n|||||||||||||||||*************** pivot���� ū ���� ���� ���� ���� ��ġ�� �ٲߴϴ� !!***************|||||||||||||||||\n");
	//		swap(&pArr[smallerThanPivotIndex], &pArr[biggerThanPivotIndex]); // �� ��Ҹ� swap(�ڸ���ü)
	//		leftFlag = 0;	// flag �ʱ�ȭ
	//		rightFlag = 0;	// flag �ʱ�ȭ
	//		left++;  // left Ŀ���� ���������� �� ĭ �̵�
	//		right--; // right Ŀ���� �������� �� ĭ �̵�
	//		continue;
	//	}// if
	//	
	//	if (leftFlag != 1) left++;		// left�� pivot���� ū ���� �߰����� �������� left�� Ŀ���� ���������� �� ĭ �̵�
	//	if (rightFlag != 1) right--;	// right�� pivot���� ���� ���� �߰����� �������� right�� Ŀ���� �������� �� ĭ �̵�
	//	//printf("left: <%d>, right: <%d>\n", left, right); // left�� right ���� Ŀ�� ��ġ ���
	//	printf("\n�ߡߡߡߡ� for�� ������ ���� pArr �������ͽ�: ");
	//	for (int k = 0; k < arrSize; k++) {
	//		printf("(%d) ", pArr[k]);
	//		if (k == arrSize - 1) printf("\n\n");
	//	}// for
	//}// for

	//printf("\n���������� �Լ� ������ ���� pArr �������ͽ�: ");
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