#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void modArr(int arr[], int arrSize);
void main() {
    srand(time(NULL));
       
    int mainArr[6];   
    int arrSize = sizeof(mainArr) / sizeof(int);
    for (int i = 0; i < arrSize; i++) {
        mainArr[i] = (int)(rand() % 45 + 1);
        
        printf("[%d] ", mainArr[i]); // 랜덤 숫자 6개
    }
    printf("\n");
    modArr(mainArr, arrSize); // 매개변수 배열의 각 요소값에 10씩 곱하여 배열의 요소들의 값을 변경시킨다
    for (int i = 0; i < arrSize; i++) {
        printf("<%d> ", mainArr[i]);
    }
}//

void modArr(int arr[], int arrSize) {
    int *p = arr; // 포인터변수 p는 arr의 주소값(0번째 요소의 주소값)을 가진다
    
    for (int i = 0; i < arrSize; i++) {
        *p = *p * 10; // *p는 p의 주소값에 들어있는 값을 의미한다(주소값을 이용하여 해당 주소에 들어있는 값을 변경하는 기술)
        //*p = (int)(rand() % 100 + 1); // 랜덤 2배로!
        p++; // p(arr 배열의 0번째 요소의 주소값)를 1씩 증가시킬때마다 p는 arr 배열의 다음 요소의 주소를 가지게 된다
    }// for
    
}//