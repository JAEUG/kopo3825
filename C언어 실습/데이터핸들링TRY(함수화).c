#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996)
#pragma warning(disable: 4700)
#define TRUE 1
#define YEAR_SIZE 100
#define AGERANGE_SIZE 200
#define CRIMINALS_SIZE 100

typedef struct { // 연도, 연령대, 마약류사범수 를 멤버변수로 가지는 구조체
	char year[YEAR_SIZE];					// 연도
	char ageRange[AGERANGE_SIZE];			// 연령대
	char numberOfCriminals[CRIMINALS_SIZE];	// 마약류사범수
} drug;

void readFileAndSetDrugs(FILE *f, drug *drugs) { // 파일의 내용을 읽으면서 동시에 구조체 배열에 값을 넣어주는 함수
	char line[1024];
	int i = 0;
	while (fgets(line, sizeof(line), f)) { // 파일 내용의 끝까지 읽기
		char* content = strtok(line, ",");
		strcpy(drugs[i].year, content);

		content = strtok(NULL, ",");
		strcpy(drugs[i].ageRange, content);

		content = strtok(NULL, ",");
		strcpy(drugs[i].numberOfCriminals, content);

		printf("%s / %s / %s\n", drugs[i].year, drugs[i].ageRange, drugs[i].numberOfCriminals); // 파일안의 내용 확인

		i++;
	}
}// readFileAndSetDrugs()

void getTotalNumberOfCriminalsForEachYearAndWriteToCsv(FILE *f2, drug *drugs, int size) { // 각 년도별로 마약류사범수의 합계를 구하여 새로운 csv로 생성하는 함수
	int tot2015 = 0, tot2016 = 0, tot2017 = 0, tot2018 = 0, tot2019 = 0, tot2020 = 0, tot2021 = 0, tot2022 = 0, tot2023 = 0, tot2024 = 0;

	// numberOfCriminals의 합계를 구하기 위해 문자열을 정수로 형변환해주는 atoi()함수 사용
	for (int i = 1; i < size; i++) { // 속성(연도 etc...) 부분은 제외
		if (strcmp(drugs[i].year, "2015") == 0) {
			tot2015 += atoi(drugs[i].numberOfCriminals);
		}
		else if (strcmp(drugs[i].year, "2016") == 0) {
			tot2016 += atoi(drugs[i].numberOfCriminals);
		}
		else if (strcmp(drugs[i].year, "2017") == 0) {
			tot2017 += atoi(drugs[i].numberOfCriminals);
		}
		else if (strcmp(drugs[i].year, "2018") == 0) {
			tot2018 += atoi(drugs[i].numberOfCriminals);
		}
		else if (strcmp(drugs[i].year, "2019") == 0) {
			tot2019 += atoi(drugs[i].numberOfCriminals);
		}
		else if (strcmp(drugs[i].year, "2020") == 0) {
			tot2020 += atoi(drugs[i].numberOfCriminals);
		}
		else if (strcmp(drugs[i].year, "2021") == 0) {
			tot2021 += atoi(drugs[i].numberOfCriminals);
		}
		else if (strcmp(drugs[i].year, "2022") == 0) {
			tot2022 += atoi(drugs[i].numberOfCriminals);
		}
		else if (strcmp(drugs[i].year, "2023") == 0) {
			tot2023 += atoi(drugs[i].numberOfCriminals);
		}
		else if (strcmp(drugs[i].year, "2024") == 0) {
			tot2024 += atoi(drugs[i].numberOfCriminals);
		}
	}
	printf("\n\n2015: %d, 2016: %d, 2017: %d, 2018: %d, 2019: %d, 2020: %d, 2021: %d, 2022: %d, 2023: %d, 2024: %d\n",
		tot2015, tot2016, tot2017, tot2018, tot2019, tot2020, tot2021, tot2022, tot2023, tot2024);

	// 파일에 입력하기 위해 정수를 문자열로 형변환해주는 sprintf(문자열변수, "형식(ex: %d)", 정수변수) 함수 사용
	char tot[10][10]; // 연도별 마약사범류수 통계값을 담기위한 문자열 배열

	sprintf(tot[0], "%d", tot2015);
	sprintf(tot[1], "%d", tot2016);
	sprintf(tot[2], "%d", tot2017);
	sprintf(tot[3], "%d", tot2018);
	sprintf(tot[4], "%d", tot2019);
	sprintf(tot[5], "%d", tot2020);
	sprintf(tot[6], "%d", tot2021);
	sprintf(tot[7], "%d", tot2022);
	sprintf(tot[8], "%d", tot2023);
	sprintf(tot[9], "%d", tot2024);
	// 연도와 마약류사범수통계 2가지 데이터만을 이용하여 새로운 csv를 생성
	for (int i = 0; i < 10; i++) {
		if (i == 0) { // 맨 윗줄은 속성 부분(연도, 마약류사범총계)
			fputs("연도,", f2);
			fputs("마약사범수합계,", f2);
			fputs("\n", f2);
		}
		fputs(strcat(drugs[(i + 1) * 7].year, ","), f2); // csv의 특성에 맞춰 데이터와 데이터 사이에 , 를 넣어줌
		fputs(strcat(tot[i], ","), f2);
		fputs("\n", f2); // 입력 마지막 부분마다 줄바꿈
	}
}// getTotalNumberOfCriminalsForEachYearAndWriteToCsv()

void main() {
	drug drugs[71] = {
		{"dummy", "dummy", "dummy"} 
	};
	int drugsSize = sizeof(drugs) / sizeof(drug); // 구조체 배열의 크기
	FILE *f = fopen("2015~2024연도별연령별마약류사범동향(검찰발).csv", "r");
	if (f == NULL) {
		printf("failed to load file");
		return;
	}
	readFileAndSetDrugs(f, drugs);

	FILE *f2 = fopen("2015~2024 연도별 마약류사범통계.csv", "w");
	getTotalNumberOfCriminalsForEachYearAndWriteToCsv(f2, drugs, drugsSize);

	fclose(f);
	fclose(f2);
}// main