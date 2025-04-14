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
    
    union extraInfo {
		char hobby[HOBBY_SIZE];
		char etc[ETC_SIZE];
	};
} Student;

void makeInitData(Student* std) { // default �л� 3��� ������ ����
    strcpy(std[0].name, "hong");
    std[0].age = 30;
    strcpy(std[0].gender, "M");
    strcpy(std[0].hobby, "soccer");

    strcpy(std[1].name, "kim");
    std[1].age = 25;
    strcpy(std[1].gender, "M");
    strcpy(std[1].hobby, "music");

    strcpy(std[2].name, "park");
    std[2].age = 20;
    strcpy(std[2].gender, "F");
    strcpy(std[2].hobby, "movie");
}// makeInitData

void printInitData(Student* std) { // default �л� 3��� ������ ���
    printf("\n======================����� �л� �������Դϴ�=======================\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s / %d / %s / %s\n", i + 1, std[i].name, std[i].age, std[i].gender, std[i].hobby);
    }
    printf("\n=====================================================================\n");
}// printInitData

void inputSudentInfo(Student* std, int* pI, int* pIsSuccess) { // �л� ������ �Է� �޾� �����ϴ� �Լ�
    int isNameNumber = FALSE; // �̸� �Է¿� ������ ���ԵǾ����� �Ǵ�
    int x = 0; // nameTmp �迭 index�� ���
    printf("\n�̸��� �Է��ϼ���: ");
    char nameTmp[100];
    scanf("%s", nameTmp);
    while (nameTmp[x] != '\0') { // ĳ���͹迭 ���ڿ��� �˻��ϰ� ������: while(ĳ���͹迭[i] != '\0') i�� ++; why? ĳ���� �迭���� ������ ��ҷ� '\0'�� �� 
        if (isdigit(nameTmp[x])) isNameNumber = TRUE; // isdigit() �Լ�: ���ڰ� �����̸� 1��ȯ
        x++;
    }

    if (isNameNumber == TRUE) {
        printf("@SYSTEM: �̸��� ���ڸ� �Է��Ͻ� �� �����ϴ�.\n");
        return;
    } else {
        strcpy(std[*pI].name, nameTmp);
    }// if		

    printf("���̸� �Է��ϼ���: ");
    int ageTmp;
    int dummy = scanf("%d", &ageTmp);
    while (dummy != 1) {
        printf("@SYSTEM: ���� �Է¿� �����߽��ϴ�.\n");
        while (getchar() != '\n'); // ���ۿ� ��� ���ڿ� �����͸� �տ������� ���๮��('\n')�� ���������� �̾Ƴ���(���� ����ֱ�)
        printf("���̸� �Է��ϼ���: ");
        dummy = scanf("%d", &ageTmp);
    }// while

    if (ageTmp <= 0 || ageTmp > 120) {
        printf("@SYSTEM: �ùٸ��� ���� ���� �Է��Դϴ�.\n");
        return;
    } else {
        std[*pI].age = ageTmp;
    }// if

    printf("������ �Է��ϼ���(���ڸ�: M, ���ڸ�: F): ");
    char genderTmp[10];
    scanf("%s", genderTmp);
    if (strcmp(genderTmp, "M") == 0 || strcmp(genderTmp, "F") == 0) { // strcmp(����1, ����2): ����1�� ����2�� ���� �������� 0�� ��ȯ
        strcpy(std[*pI].gender, genderTmp);
    } else {
        printf("������ M Ȥ�� F�� �Է��Ͻ� �� �ֽ��ϴ�.\n");
        return;
    }// if

    x = 0;
    int isHobbyNumber = FALSE;
    printf("��̸� �Է��ϼ���(�ش� �л��� ���� ��Ÿ������ ����Ͻ÷��� etc�� �Է��ϼ���): ");
    char hobbyTmp[100];
    scanf("%s", hobbyTmp);
    while (hobbyTmp[x] != '\0') {
        if (isdigit(hobbyTmp[x])) isHobbyNumber = TRUE;
        x++;
    }// while
    int isEtcActive = FALSE; 
    if (strcmp(hobbyTmp, "etc") == 0) {
		isHobbyNumber = FALSE;
		isEtcActive = TRUE;
		char etcTmp[100];
		printf("��Ÿ������ �Է��ϼ���: ");
		scanf("%s", etcTmp);
		strcpy(std[*pI].etc, etcTmp);
	} 

    if (isHobbyNumber == TRUE) {
        printf("@SYSTEM: ��̿� ���ڸ� �Է��Ͻ� �� �����ϴ�.\n");
        return;
    } else {
    	if (isEtcActive == FALSE) strcpy(std[*pI].hobby, hobbyTmp);
    }// if

    *pIsSuccess = TRUE; // ������ ���� ����
    *pI += 1; // i �� +1
}// inputSudentInfo

void printAccumulatedStudentInfo(Student* std, int start, int end) {
    printf("\n======================����� �л� �������Դϴ�=======================\n");
    for (int i = start; i < end; i++) {
        printf("%d. %s / %d / %s / %s\n", i + 1, std[i].name, std[i].age, std[i].gender, std[i].hobby);
    }
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
