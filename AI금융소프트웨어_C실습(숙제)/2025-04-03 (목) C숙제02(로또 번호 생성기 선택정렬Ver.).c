#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// 1. 배열에 값 삽입시 중복 방지
// 2. 배열 요소 오름차순 정렬(선택정렬)
void main() {
    srand(time(NULL));      // 현재시간(초)를 seed로 하여 rand()의 랜덤생성시퀀스를 설정해준다(현재시간은 계속 흘러가니깐 rand()의 랜덤세트가 계속 변하게 됨)
    int arr[6];             // 로또번호 담을 배열
    int arrSize = 6;        // 로또 번호는 6개
    int repeatCount = 0;    // 배열에서 중복 발생시 이 값을 ++하여 중복 여부 판단에 사용할 수 있다
    int isRepeatTrue = 0;   // repeatCount가 0이냐 아니냐 여부에 따라 이 값을 0(False), 1(True)로 설정하여 중복 여부 최종적으로 판단
    /////////////////////////  
    int min;    // 선택정렬에 이용할 외부변수                                
    int minLoc; // 배열에서 min값이 최종적으로 발견된 위치(index)
    
    for (int i = 0; i < arrSize;) { // 조건 만족될때까지 무한루프, while(1)과 유사하다
        repeatCount = 0;    // 중복여부 판단에 차질이 없도록 루프마다 이 값을 초기화
        isRepeatTrue = 0;   // 중복여부 판단에 차질이 없도록 루프마다 이 값을 초기화
        int randNum = (int)((rand() % 45) + 1); // 랜덤 숫자 생성(1 ~ 45 사이의 값)
        
        for (int j = 0; j < arrSize; j++) {
            if (randNum == arr[j]) { // 생성된 랜덤 숫자와 배열의 전체 요소들을 비교하다가 배열에서 랜덤 숫자와 비슷한 값이 발견되었을때
                repeatCount++;       // 중복 카운트를 +1
            }// if
        }// for
        
        if (repeatCount == 0) { // 중복 카운트가 증가하지 않았으면(0), 최종 중복 판단 = 중복 없음!
            isRepeatTrue = 0;
        } else {                // 중복 카운트가 증가했으면(!= 0), 최종 중복 판단 = 중복 있음!
            isRepeatTrue = 1;
        }// if
        
        if (isRepeatTrue == 0) {        // 최종 중복 판단이 중복 없음! 일때에만
            arr[i] = randNum;           // 배열에 랜덤 숫자를 삽입!
            i++; // 조건 만족시 +1      // 다음 인덱스로 이동!
        } else if (isRepeatTrue == 1) { // 중복 있음! 상태면 루프의 처음으로 돌아가서 랜덤 숫자 생성부터 재 시작!!
            continue;
        }// if
        
    }// for
    printf("1) 중복제거:     ");
    for (int i = 0; i < arrSize; i++) {
        printf("[%d] ", arr[i]);
    }
    printf("\n");
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    for (int i = 0; i < arrSize; i++) { // i번째 index부터 배열의 끝 index까지
        min = arr[i];   // 현재 검사중인 index(i)값이 배열 내 최소값일 경우를 고려: default min값은 배열의 i번째 인덱스 값
        minLoc = i;     // 현재 검사중인 index(i)값이 배열 내 최소값일 경우를 고려: default 최소값 발생 위치는 i번째 인덱스
        for (int j = i; j < arrSize; j++) { // 선택정렬의 특징: 최소값을 발견하여 정렬하고 나면 그 최소값은 탐색대상에서 제외한다 1순회: 0~n번인덱스, 2순회: 1~n번인덱스, 3순회: 2~n번인덱스...
            if (min > arr[j]) { // i번 인덱스의 값을 그 뒤의 요소 값들과 비교했을때 요소 값이 i번 인덱스 값보다 작다면(potential 최소값)
                min = arr[j];   // min에 그 potential 최소값을 대입해둔다
                minLoc = j;     // potential 최소값이 발견된 j인덱스의 위치를 기록해둔다
            }
        }// for
        arr[minLoc] = arr[i];   // 최소값이 발견된 위치에 i번째 인덱스의 값을 넣어주고
        arr[i] = min;           // i번째 인덱스에는 발견된 최소값을 넣어준다 (i번째 인덱스와 <-> 최소값이 있던 자리 를 자리 바꿈)             
    }// for
    printf("2) 오름차순 정렬: ");
    for (int i = 0; i < arrSize; i++) {
        printf("[%d] ", arr[i]);
    }
    
}// main
