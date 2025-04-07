#include <stdio.h>
// 버블정렬 실습
void main() {
    int arr[6] = {200, 500, 600, 400, 600, 100}; 
    int arrSize = sizeof(arr) / sizeof(int);
    int jEnd = arrSize - 1; // 버블정렬에서 최대 swap 검사 횟수: 배열의크기 - 1
    int swapCount = 0;
    int tmp; // swap용 임시 변수(공간)
    
    for (int i = 0; i < arrSize; i++) {
        swapCount = 0;
        for (int j = 0; j < jEnd; j++) {    // 버블정렬의 특징: 1순회 최대 swap검사 횟수 = (배열의크기 - 1), 2순회 = (배열의크기 - 2), ... 마지막순회 = 1
            if (arr[j] > arr[j + 1]) {  // j번째 값이 (j + 1)번째 값보다 크다면  
                tmp = arr[j + 1];       // tmp에 (j + 1)번째 값을 저장해두고
                arr[j + 1] = arr[j];    // (j + 1)번째에 j번 값을 넣어주고
                arr[j] = tmp;           // j번에는 tmp의 값을 넣어준다 (j <-> j+1 의 값 swap)
                swapCount++;
            } else {
                continue;
            }// if
        }// for 
        printf("#%d순회 - swapCount: %d\n", i + 1, swapCount);
        jEnd--; // 순회를 거듭할수록 swap 탐색 범위를 -1씩 감소
    }// for
    
    for (int i = 0; i < arrSize; i++) {
        printf("[%d] ", arr[i]);   
    }
}// main