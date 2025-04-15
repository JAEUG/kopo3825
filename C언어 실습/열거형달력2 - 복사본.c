#include <stdio.h>
#pragma warning (disable: 4996)
#define TRUE 1
enum month {jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
char months[][20] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "OCT", "NOV", "DEC"};
enum day {sun, mon, tue, wed, thu, fri, sat};
void printCal(int year, int month);
void printCalHeader(int year, int month);
void printCalBody(int year, int month);
int getStartDay(int year, int month);
int getTotalDays(int year, int month);
int getDaysOfMonth(int year, int month);
int isLeapYear(int year);


void main() {
	while (TRUE) {
		int year;
		int month;
		printf("year를 입력하세요> ");
		scanf("%d", &year);
		printf("month를 입력하세요> ");
		scanf("%d", &month);
		printCal(year, month);
	}
}// main

void printCal(int year, int month) {
	printCalHeader(year, month);
	printCalBody(year, month);
}// printCal()

void printCalHeader(int year, int month) {
	printf("%d%02d\n", year, month);
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
	printf("\n스타트데이: %d\n", startDay);

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
	printf("\n----------------------\n");
}// printCalBody()

int getStartDay(int year, int month) {
	int initStartDay = 3; // 2025년 1월의 시작은 수요일
	int totalDays = getTotalDays(year, month);
	int finalStartDay = (totalDays + initStartDay) % 7;

	return finalStartDay;
}// getStartDay()

int getTotalDays(int year, int month) {
	int total = 0;
	// 입력년도 이전까지의 모든 날의 합(ex: 입력년도 2027년 then, 2025년 1월 1일부터 2026년 12월 31일까지)
	for (int i = 2025; i < year; i++) {
		if (isLeapYear(i) == TRUE) { // 윤년일때는 1년이 366일
			total += 366;
		} else {
			total += 365;
		}
	}
	
	// 입력년도는 입력달 이전까지 계산(ex: 입력 2027년 2월 then 1월분만 계산)
	for (int i = 1; i < month; i++) {
		total = total + getDaysOfMonth(year, i);
	}

	return total;
}// getTotalDays()

int getDaysOfMonth(int year, int month) {
	int daysOfMonth = 0;
	// 1, 3, 5, 7, 8, 10, 12 월의 경우 31일까지 있다.
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) daysOfMonth = 31;
	// 4, 6, 9, 11 월의 경우 30일까지 있다.
	if (month == 4 || month == 6 || month == 9 || month == 11) daysOfMonth = 30;
	// 2월인 경우 윤년이면 29일, 평년이면 28일까지 있다.
	if (month == 2) {
		if (isLeapYear(year) == TRUE) {
			daysOfMonth = 29;
		} else {
			daysOfMonth = 28;
		}
	}
	
	return daysOfMonth;
}// getDaysOfMonth()

int isLeapYear(int year) {
	if (year % 4 == 0) { // 윤년일때 1을 return
		return 1;
	} else {
		return 0;
	}
}// isLeapYear()
