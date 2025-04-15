#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0
#define MAX_STUDENT 1000
#define NAME_SIZE 100
#define GENDER_SIZE 10
#define HOBBY_SIZE 100
#define ETC_SIZE 100
typedef struct student {
    char name[NAME_SIZE];
    int age;
    char gender[GENDER_SIZE];

    union {
        char hobby[HOBBY_SIZE];
        char etc[ETC_SIZE];
    };
    char choice[20];
} Student;

void makeInitData(Student* std) { // default 학생 3명분 데이터 생성
    strcpy(std[0].name, "hong");
    std[0].age = 30;
    strcpy(std[0].gender, "M");
    strcpy(std[0].hobby, "soccer");
    strcpy(std[0].choice, "hobby: ");

    strcpy(std[1].name, "kim");
    std[1].age = 25;
    strcpy(std[1].gender, "M");
    strcpy(std[1].hobby, "music");
    strcpy(std[1].choice, "hobby: ");

    strcpy(std[2].name, "park");
    std[2].age = 20;
    strcpy(std[2].gender, "F");
    strcpy(std[2].hobby, "movie");
    strcpy(std[2].choice, "hobby: ");
}// makeInitData

void printInitData(Student* std) { // default 학생 3명분 데이터 출력
    printf("\n======================저장된 학생 데이터입니다=======================\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s / %d / %s / %s%s\n", i + 1, std[i].name, std[i].age, std[i].gender, std[i].choice, std[i].hobby);
    }
    printf("\n=====================================================================\n");
}// printInitData

void inputSudentInfo(Student* std, int* pI, int* pIsSuccess) { // 학생 정보를 입력 받아 저장하는 함수
    int isNameNumber = FALSE; // 이름 입력에 정수가 포함되었는지 판단
    int x = 0; // nameTmp 배열 index로 사용
    printf("\n이름을 입력하세요: ");
    char nameTmp[100];
    scanf("%s", nameTmp);
    while (nameTmp[x] != '\0') { // 캐릭터배열 문자열을 검사하고 싶을때: while(캐릭터배열[i] != '\0') i는 ++; why? 캐릭터 배열에는 마지막 요소로 '\0'이 들어감 
        if (isdigit(nameTmp[x])) isNameNumber = TRUE; // isdigit() 함수: 인자가 숫자이면 1반환
        x++;
    }

    if (isNameNumber == TRUE) {
        printf("@SYSTEM: 이름에 숫자를 입력하실 수 없습니다.\n");
        return;
    } else {
        strcpy(std[*pI].name, nameTmp);
    }// if		

    printf("나이를 입력하세요: ");
    int ageTmp;
    int dummy = scanf("%d", &ageTmp);
    while (dummy != 1) {
        printf("@SYSTEM: 나이 입력에 실패했습니다.\n");
        while (getchar() != '\n'); // 버퍼에 담긴 문자열 데이터를 앞에서부터 개행문자('\n')를 만날때까지 뽑아낸다(버퍼 비워주기)
        printf("나이를 입력하세요: ");
        dummy = scanf("%d", &ageTmp);
    }// while

    if (ageTmp <= 0 || ageTmp > 120) {
        printf("@SYSTEM: 올바르지 않은 나이 입력입니다.\n");
        return;
    }
    else {
        std[*pI].age = ageTmp;
    }// if

    printf("성별을 입력하세요(남자면: M, 여자면: F): ");
    char genderTmp[10];
    scanf("%s", genderTmp);
    if (strcmp(genderTmp, "M") == 0 || strcmp(genderTmp, "F") == 0) { // strcmp(인자1, 인자2): 인자1과 인자2의 값이 같을때만 0을 반환
        strcpy(std[*pI].gender, genderTmp);
    } else {
        printf("성별은 M 혹은 F만 입력하실 수 있습니다.\n");
        return;
    }// if

    x = 0;
    int isHobbyNumber = FALSE;
    printf("취미를 입력하세요(해당 학생에 대한 기타사항을 기록하시려면 !etc를 입력하세요): ");
    char hobbyTmp[100];
    scanf("%s", hobbyTmp);
    while (hobbyTmp[x] != '\0') {
        if (isdigit(hobbyTmp[x])) isHobbyNumber = TRUE;
        x++;
    }// while
    int isEtcActive = FALSE;
    if (strcmp(hobbyTmp, "!etc") == 0) {
        isHobbyNumber = FALSE;
        isEtcActive = TRUE;
        char etcTmp[100];
        printf("기타사항을 입력하세요: ");
        scanf("%s", etcTmp);
        strcpy(std[*pI].etc, etcTmp);
        strcpy(std[*pI].choice, "etc: ");
    }

    if (isHobbyNumber == TRUE) {
        printf("@SYSTEM: 취미에 숫자를 입력하실 수 없습니다.\n");
        return;
    } else {
        if (isEtcActive == FALSE) {
            strcpy(std[*pI].choice, "hobby: ");
            strcpy(std[*pI].hobby, hobbyTmp);
        }
    }// if

    *pIsSuccess = TRUE; // 데이터 저장 성공
    *pI += 1; // i 값 +1
}// inputSudentInfo

void printAccumulatedStudentInfo(Student* std, int start, int end) {
    printf("\n======================저장된 학생 데이터입니다=======================\n");
    for (int i = start; i < end; i++) {
        if (strcmp(std[i].choice, "hobby: ") == 0) {
            printf("%d. %s / %d / %s / %s%s\n", i + 1, std[i].name, std[i].age, std[i].gender, std[i].choice, std[i].hobby);
        } else if (strcmp(std[i].choice, "etc: ") == 0) {
            printf("%d. %s / %d / %s / %s%s\n", i + 1, std[i].name, std[i].age, std[i].gender, std[i].choice, std[i].etc);
        }
    }// for
    printf("\n=====================================================================\n");
}// printAccumulatedStudentInfo

void main() {
    int i = 3;
    Student students[MAX_STUDENT];
    makeInitData(students);
    printInitData(students);

    while (TRUE) {
        int isSuccess = FALSE;
        inputSudentInfo(students, &i, &isSuccess);
        if (isSuccess == TRUE) printAccumulatedStudentInfo(students, 0, i);
    }// while
}// main
