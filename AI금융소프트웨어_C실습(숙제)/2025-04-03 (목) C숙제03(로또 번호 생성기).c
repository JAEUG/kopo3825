#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
    srand(time(NULL));
    int arrIndex = 0; // while문 조건에 이용 + arr의 인덱스 번호로 사용
    int arr[6]; // 중복제거 필터만 적용된 값들의 배열
    int True = 1; // 중복이 있으면 1
    int False = 0; // 중복이 없으면 0
    int joongbok = 999; // 중복검사 결과 확인용, 처음엔 무엇도 아닌 상태
    int arrSorted[6]; // 중복제거 + 오름차순 정렬까지 적용된 final배열
    int inspector = 999999; // 최소값 탐색용으로 대빵 큰 수 하나
    int minLoc = 0; // arr 배열에서 최소값이 탐색된 위치를 저장
    int whileNum = 0; // 2번째 while문 조건에 이용 + arrSorted의 인덱스 번호로 사용
    while(1) {
        int count = 0; // 중복을 발견하면 ++되는 카운트를 여기서 초기화!! 여기 아니면 무한루프...ㅠㅠ
        if (arrIndex >= 6) break; // arrIndex가 6이 되는순간 break!, arrIndex는 0부터 시작해서 루프 마지막마다 ++되니깐 6이 되는순간 6바퀴 순환을 마친것
        
        int num = (int)((rand() % 45) + 1); // 랜덤한 수를 만들어서 45로 나누면 반환값은 0~44까지가 되게 된다 로또는 1~45까지니깐 반환값에 +1

        for (int i = 0; i <= arrIndex; i++) {
            if (arr[i] == num) { // 중복되는 값이 있음
                count++;        // 중복되는 값이 발견되면 count++
            }
        }// for
        if (count == 0) { // count가 증가한 적이 없으면(0) 중복이 발견되지 않은거임
            joongbok = False; // joongbok(중복) 은 False(0)
        } else { // count가 증가해서 0이 아니라면 중복이 발견된거임!
            joongbok = True; // joongbok(중복) 은 True(1) 
        }// if
        printf("joongbok의 상태는: %d\n", joongbok);
        if (joongbok == False){ // 중복이 발견되지 않은(안전한 상태)라면
            arr[arrIndex] = num; // arr의 인덱스에 num(랜덤으로 생성한 수)를 넣어줌!
            arrIndex++; // 인덱스 번호 1 올리기
        } else if (joongbok == True) { // 중복이 발견되었었다면 중복을 다시 False(0)로 초기화
            joongbok = False;
            continue; // while문 시작으로 다시 go back
        }
        //sleep(1);
    }// while
    
    for (int i =0; i < 6; i++) { // 중복 제거한 로또 번호 눈으로 확인해보기
        printf("%d\n", arr[i]);
    }// for
    printf("*********************************************************\n");
    while (whileNum < 6) {
        inspector = 999999; // 요소마다 값을 비교해가며 최소값을 찾아내기 위해 비교하는 수의 값을 엄청 크게 잡아준다
        for (int i = 0; i < 6; i++) { // arr의 배열 길이만큼(모든 요소를 탐색하겠다는 소리죵)
            if (inspector > arr[i]) { // 비교하는 값(inspector)의 값이 i번째 요소의 값보다 크다면
               inspector = arr[i]; // inspector에 i번째 요소값을 넣어줍니다(이제 이것을 i를 1씩 증가시켜가면서 for문을 돌면서 반복하겠지요)
                                   // inspector에는 점점 작은 값들이 저장될겁니다 최종적으로는 최소값이 담기게 됩니다!
               minLoc = i;         // 조건을 만족할때에만 i를 저장하므로 마지막으로 조건을 만족할때의 i값(최소값의 인덱스 번호)이 minLoc에 담깁니다
            }
        }// for
        printf("arr에서 최소값이 위치해있던 곳은 몇 번째 인덱스? %d\n", minLoc);
        arrSorted[whileNum] = arr[minLoc]; // arr의 최소값들을(arr에서 최소값이 발생한 인덱스 값을 이용) arrSorted에 0번부터 5번인덱스까지 순서대로 삽입
        arr[minLoc] = 100; // 최소값이 있던 자리의 값을 임의의 값으로 변경(다음 최소값 탐색은 이번 회차에서 발생한 최소값을 제외하고 실행)         
        whileNum++; // arrSorted에 값을 한개씩 넣으려면 arrSorted에 사용되는 인덱스 값을 1씩 올려줘야겠죠
    }// while
    printf("*********************************************************\n");
    printf("$$$$$$$$$$$$ << 당신의 행운의 로또 번호는: ");
    for (int i = 0; i < (sizeof(arrSorted) / sizeof(int)); i++) { // 우리의 로또 번호가 잘 정렬되었는지 찍어볼까요!
        printf("( %d ) ", arrSorted[i]);
    }//
    printf(">> $$$$$$$$$$$$");
    
}//
