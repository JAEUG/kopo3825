#include <stdio.h>
#include <time.h>
#pragma warning (disable: 4996)
#define TRUE 1

enum month {jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
enum day {sun, mon, tue, wed, thu, fri, sat};
int dYear, dMonth, dDay;
int cYear, cMonth, cDay;
void printCal(int year, int month);
void printCalHeader(int year, int month);
void printCalBody(int year, int month);
int getStartDay(int year, int month);
int getTotalDays(int year, int month);
int getDaysOfMonth(int year, int month);
int isLeapYear(int year);
void printDday(int input);
void setYearMonthDayUsingInput(int input);
int calcDday(int year, int month, int day); // ���糯¥ ~ �Է³�¥ ������ d-day ���, d-day = (20250101 ~ �Է³�¥) - (20250101 ~ ���糯¥)
void getCurrentDate(); // time�� �̿� ���� ��,��,���� ���� cYear, cMonth, cDay�� �Ҵ�

void main() {
	while (TRUE) {
		int year, month, input;
		printf("\n�� year�� month�� �Է��ϼ���(year �Է� �� space �Է� �� month �Է�)>> ");
		scanf("%d %d", &year, &month);
		printf("�� d-day ����� ���� ��¥�� �Է��ϼ���(ex: 20250301)>> ");
		scanf("%d", &input);
		printCal(year, month); // �޷� ���
		printDday(input); // d-day ���
	}
}// main

void printCal(int year, int month) {
	printCalHeader(year, month);
	printCalBody(year, month);
}// printCal()

void printCalHeader(int year, int month) {
	printf("�� %d�� %02d��\n", year, month);
	printf("======================\n");
	enum days ed;
	char cd[7] = { 's', 'm', 't', 'w', 't', 'f', 's' };
	for (ed = sun; ed <= sat; ed++) {
		printf("%3c", cd[ed]);
	}
	printf("\n----------------------\n");
}// printCalHeader()

void printCalBody(int year, int month) {
	int startDay = getStartDay(year, month);
	// printf("\n��ŸƮ����: %d\n", startDay);

	for (int i = 0; i < startDay; i++) {
		printf("   ");
	}
	int daysofMonth = getDaysOfMonth(year, month);

	for (int i = 1; i <= daysofMonth; i++) {
		printf("%3d", i);
		startDay++;
		if (startDay >= 7) {
			startDay = 0;
			printf("\n");
		}
	}
	printf("----------------------\n");
}// printCalBody()

int getStartDay(int year, int month) {
	int initStartDay = 3; // 2025�� 1���� ������ ������
	int totalDays = getTotalDays(year, month);
	int finalStartDay = (totalDays + initStartDay) % 7;

	return finalStartDay;
}// getStartDay()

int getTotalDays(int year, int month) {
	int total = 0;
	// �Է³⵵ ���������� ��� ���� ��(ex: �Է³⵵ 2027�� then, 2025�� 1�� 1�Ϻ��� 2026�� 12�� 31�ϱ���)
	for (int i = 2025; i < year; i++) {
		if (isLeapYear(i) == TRUE) { // �����϶��� 1���� 366��
			total += 366;
		} else {
			total += 365;
		}
	}
	
	// �Է³⵵�� �Է´� �������� ���(ex: �Է� 2027�� 2�� then 1���и� ���)
	for (int i = 1; i < month; i++) {
		total = total + getDaysOfMonth(year, i);
	}

	return total;
}// getTotalDays()

int getDaysOfMonth(int year, int month) { // enum month �ݿ�
	int daysOfMonth = 0;
	// 1, 3, 5, 7, 8, 10, 12 ���� ��� 31�ϱ��� �ִ�.
	if (month == jan || month == mar || month == may || month == jul || month == aug || month == oct || month == dec) daysOfMonth = 31;
	// 4, 6, 9, 11 ���� ��� 30�ϱ��� �ִ�.
	if (month == apr || month == jun || month == sep || month == nov) daysOfMonth = 30;
	// 2���� ��� �����̸� 29��, ����̸� 28�ϱ��� �ִ�.
	if (month == feb) {
		if (isLeapYear(year) == TRUE) {
			daysOfMonth = 29;
		} else {
			daysOfMonth = 28;
		}
	}
	
	return daysOfMonth;
}// getDaysOfMonth()

int isLeapYear(int year) {
	if (year % 4 == 0) { // �����϶� 1�� return
		return 1;
	} else {
		return 0;
	}
}// isLeapYear()

void printDday(int input) {
	setYearMonthDayUsingInput(input);
	int Dday = calcDday(dYear, dMonth, dDay);
	printf("!D-day: [%d]�� ���ҽ��ϴ�.\n", Dday);
}

void setYearMonthDayUsingInput(int input) {
	dYear = input / 10000;
	dMonth = (input % 10000) / 100;
	dDay = input % 100;
}

int calcDday(int year, int month, int day) {
	getCurrentDate();
	// getTotalDays()���� �ϼ� ����� �߰�
	int initToDday = 0;
	int initToToday = 0;
	int realDday = 0;
	initToDday = getTotalDays(dYear, dMonth) + dDay;
	// printf("\ndYear(d-day�Է��� ��): %d, dMonth(d-day�Է��� ��): %d, dDay(d-day�Է��� ��): %d\n", dYear, dMonth, dDay);
	// printf("\ngetTotalDays: %d / initToDday: %d\n", getTotalDays(dYear, dMonth), initToDday);
	
	// initToToday �� �κ� ���
	for (int i = 2025; i < cYear; i++) {
		if (isLeapYear(i) == TRUE) {
			initToToday += 366;
		} else {
			initToToday += 365;
		}
	}
	// initToToday �� �κ� ���
	for (int i = 1; i < cMonth; i++) {
		initToToday += getDaysOfMonth(cYear, i);
	}
	// initToToday �� �κ� ���
	initToToday += cDay;

	realDday = initToDday - initToToday;
	return realDday;
}

void getCurrentDate() {
	time_t t = time(NULL);
	struct tm myTm = *localtime(&t);
	cYear = myTm.tm_year + 1900;
	cMonth = myTm.tm_mon + 1;
	cDay = myTm.tm_mday;
	printf("\n���ó�¥: %d��%02d��%02d��\n", cYear, cMonth, cDay);
}// getCurrentDate()
