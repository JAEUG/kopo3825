#include <stdio.h>

void main() {
    int arr[6] = {6, 5, 4, 3, 2, 1};
    int arrSize = sizeof(arr) / sizeof(int);
    int tmp;
    int j;
    for (int i = 1; i < arrSize; i++) {
        tmp = arr[i]; // 비교기준 1번 index부터
        for (j = i; j > 0 && tmp < arr[j - 1]; j--) { // 비교되는 대상은 비교기준 -1부터 0까지
            arr[j] = arr[j - 1]; // 한칸씩 뒤로
        }// for
        arr[j] = tmp; // 알맞은 위치에 비교기준 값을 삽입
    }// for
    
    for (int i = 0; i < arrSize; i++) {
        printf("[%d] ", arr[i]);
    }
}// main