#include <stdio.h>
// 삽입정렬
void main() {
    int arr[] = {3, 2, 9, 1, 7};
    int arrSize = sizeof(arr) / sizeof(int);
    int tmp;
    for (int i = 1; i < arrSize; i++) { // 비교 주최가 되는 값의 index로 사용, 가장 첫번째 비교 주최는 1번째 인덱스(0번째가 아님!)
        tmp = 0;
        printf("%d회차) 비교 주최: <%d>", i, arr[i]);
        for (int j = 0; j < i; j++) { // 비교 대상의 범위, 1회: index 0, 2회: index 0, index 1, ... 마지막회: index 0, index 1, ... index (배열크기 - 1)
            if (arr[i] < arr[j]) {  // 비교 주최보다 비교 대상의 값이 더 크다면
                tmp =  arr[i];      // 비교 주최의 값을 tmp에 저장하고
                arr[i] = arr[j];    // 비교 주최 위치 index에 비교 대상의 값을 넣어주고
                arr[j] = tmp;       // 비교 대상(최소값 발생)위치에 비교 주최의 값을 넣어준다
            }// if
        }// for
       
        printf(" | tmp(최소값)로 선정된 값은: <%d>  | ", tmp);
        for (int i = 0; i < arrSize; i++) {
            printf("[%d] ", arr[i]);
        }//
        if (tmp == 0) {
            printf("이번 회차에는 아무일도 일어나지 않았습니다.\n");
        } else {
            printf("\n");
        }         
    }// for
    printf("\n최종 정렬 결과: ");
    for (int i = 0; i < arrSize; i++) {
        printf("{%d} ", arr[i]);
    }//
    
}// main