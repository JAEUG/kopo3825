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
int calcDday(int year, int month, int day); // 현재날짜 ~ 입력날짜 까지의 d-day 계산, d-day = (20250101 ~ 입력날짜) - (20250101 ~ 현재날짜)
void getCurrentDate(); // time을 이용 현재 년,월,일을 얻어내어 cYear, cMonth, cDay에 할당

void main() {
	while (TRUE) {
		int year, month, input;
		printf("\n● year와 month를 입력하세요(year 입력 후 space 입력 후 month 입력)>> ");
		scanf("%d %d", &year, &month);
		printf("● d-day 계산을 위한 날짜를 입력하세요(ex: 20250301)>> ");
		scanf("%d", &input);
		printCal(year, month); // 달력 출력
		printDday(input); // d-day 출력
	}
}// main

void printCal(int year, int month) {
	printCalHeader(year, month);
	printCalBody(year, month);
}// printCal()

void printCalHeader(int year, int month) {
	printf("▼ %d년 %02d월\n", year, month);
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
	// printf("\n스타트데이: %d\n", startDay);

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

int getDaysOfMonth(int year, int month) { // enum month 반영
	int daysOfMonth = 0;
	// 1, 3, 5, 7, 8, 10, 12 월의 경우 31일까지 있다.
	if (month == jan || month == mar || month == may || month == jul || month == aug || month == oct || month == dec) daysOfMonth = 31;
	// 4, 6, 9, 11 월의 경우 30일까지 있다.
	if (month == apr || month == jun || month == sep || month == nov) daysOfMonth = 30;
	// 2월인 경우 윤년이면 29일, 평년이면 28일까지 있다.
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
	if (year % 4 == 0) { // 윤년일때 1을 return
		return 1;
	} else {
		return 0;
	}
}// isLeapYear()

void printDday(int input) {
	setYearMonthDayUsingInput(input);
	int Dday = calcDday(dYear, dMonth, dDay);
	printf("!D-day: [%d]일 남았습니다.\n", Dday);
}

void setYearMonthDayUsingInput(int input) {
	dYear = input / 10000;
	dMonth = (input % 10000) / 100;
	dDay = input % 100;
}

int calcDday(int year, int month, int day) {
	getCurrentDate();
	// getTotalDays()에서 일수 계산을 추가
	int initToDday = 0;
	int initToToday = 0;
	int realDday = 0;
	initToDday = getTotalDays(dYear, dMonth) + dDay;
	// printf("\ndYear(d-day입력의 년): %d, dMonth(d-day입력의 월): %d, dDay(d-day입력의 일): %d\n", dYear, dMonth, dDay);
	// printf("\ngetTotalDays: %d / initToDday: %d\n", getTotalDays(dYear, dMonth), initToDday);
	
	// initToToday 년 부분 계산
	for (int i = 2025; i < cYear; i++) {
		if (isLeapYear(i) == TRUE) {
			initToToday += 366;
		} else {
			initToToday += 365;
		}
	}
	// initToToday 월 부분 계산
	for (int i = 1; i < cMonth; i++) {
		initToToday += getDaysOfMonth(cYear, i);
	}
	// initToToday 일 부분 계산
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
	printf("\n오늘날짜: %d년%02d월%02d일\n", cYear, cMonth, cDay);
}// getCurrentDate()
