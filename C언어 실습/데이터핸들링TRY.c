#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996)
#pragma warning(disable: 4700)
#define TRUE 1
#define YEAR_SIZE 100
#define AGERANGE_SIZE 200
#define CRIMINALS_SIZE 100


typedef struct {
	char year[YEAR_SIZE];
	char ageRange[AGERANGE_SIZE];
	char numberOfCriminals[CRIMINALS_SIZE];
} drug;

void main() {
	//drug two015[10], two016[10], two017[10], two018[10], two019[10], two020[10], two021[10], two022[10], two023[10], two024[10];
	drug drugs[71] = {
		{"dummy", "dummy", "dummy"} 
	};
	FILE *f = fopen("2015~2024���������ɺ�������������(������).csv", "r");
	if (f == NULL) {
		printf("failed to load file");
		return;
	}
	char line[1024];
	
	int i = 0;
	while (fgets(line, sizeof(line), f)) {
		char *content = strtok(line, ",");
		strcpy(drugs[i].year, content);
		//strcpy(d.year, content);

		content = strtok(NULL, ",");
		strcpy(drugs[i].ageRange, content);
		//content = strtok(NULL, ",");
		//strcpy(d.ageRange, content);
		content = strtok(NULL, ",");
		strcpy(drugs[i].numberOfCriminals, content);
		//content = strtok(NULL, ",");
		//strcpy(d.numberOfCriminals, content);
		////printf("%s\n", content);
		
		printf("%s / %s / %s\n", drugs[i].year, drugs[i].ageRange, drugs[i].numberOfCriminals);
		
		//fputs(d.year, f2);
		//fputs(d.ageRange, f2);
		//fputs(d.numberOfCriminals, f2);
		i++;
	}

	FILE* f2 = fopen("2015~2024 ������ �����������.csv", "w");
	int tot2015 = 0, tot2016 = 0, tot2017 = 0, tot2018 = 0, tot2019 = 0, tot2020 = 0, tot2021 = 0, tot2022 = 0, tot2023 = 0, tot2024 = 0;
	// int tot[10];
	// numberOfCriminals�� �հ踦 ���ϱ� ���� ���ڿ��� ������ ����ȯ���ִ� atoi()�Լ� ���
	int totTmp = 0;
	for (int i = 1; i < sizeof(drugs) / sizeof(drug); i++) { // �Ӽ�(���� etc...) �κ��� ����
		if (strcmp(drugs[i].year, "2015") == 0) {
			tot2015 += atoi(drugs[i].numberOfCriminals);
		} else if (strcmp(drugs[i].year, "2016") == 0) {
			tot2016 += atoi(drugs[i].numberOfCriminals);
		} else if (strcmp(drugs[i].year, "2017") == 0) {
			tot2017 += atoi(drugs[i].numberOfCriminals);
		} else if (strcmp(drugs[i].year, "2018") == 0) {
			tot2018 += atoi(drugs[i].numberOfCriminals);
		} else if (strcmp(drugs[i].year, "2019") == 0) {
			tot2019 += atoi(drugs[i].numberOfCriminals);
		} else if (strcmp(drugs[i].year, "2020") == 0) {
			tot2020 += atoi(drugs[i].numberOfCriminals);
		} else if (strcmp(drugs[i].year, "2021") == 0) {
			tot2021 += atoi(drugs[i].numberOfCriminals);
		} else if (strcmp(drugs[i].year, "2022") == 0) {
			tot2022 += atoi(drugs[i].numberOfCriminals);
		} else if (strcmp(drugs[i].year, "2023") == 0) {
			tot2023 += atoi(drugs[i].numberOfCriminals);
		} else if (strcmp(drugs[i].year, "2024") == 0) {
			tot2024 += atoi(drugs[i].numberOfCriminals);
		}
	}

	printf("\n\n2015: %d, 2016: %d, 2017: %d, 2018: %d, 2019: %d, 2020: %d, 2021: %d, 2022: %d, 2023: %d, 2024: %d\n",
		tot2015, tot2016, tot2017, tot2018, tot2019, tot2020, tot2021, tot2022, tot2023, tot2024);

	// ���Ͽ� �Է��ϱ� ���� ������ ���ڿ��� ����ȯ���ִ� sprintf(���ڿ�����, "����(ex: %d)", ��������) �Լ� ���
	char tot[10][10];
	//char totC2015[10] = ""; 
	//sprintf(totC2015, "%d", tot2015);
	//char totC2016[10] = "";
	//sprintf(totC2016, "%d", tot2016);
	//char totC2017[10] = "";
	//sprintf(totC2017, "%d", tot2017);
	//char totC2018[10] = "";
	//sprintf(totC2018, "%d", tot2018);
	//char totC2019[10] = "";
	//sprintf(totC2019, "%d", tot2019);
	//char totC2020[10] = "";
	//sprintf(totC2020, "%d", tot2020);
	//char totC2021[10] = "";
	//sprintf(totC2021, "%d", tot2021);
	//char totC2022[10] = "";
	//sprintf(totC2022, "%d", tot2022);
	//char totC2023[10] = "";
	//sprintf(totC2023, "%d", tot2023);
	//char totC2024[10] = "";
	//sprintf(totC2024, "%d", tot2024);
	
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
	printf("\n������� ���\n");
	for (int i = 0; i < 10; i++) {
		printf("%s  ", tot[i]);
	}

	for (int i = 0; i < 10; i++) {
		if (i == 0) { // �Ӽ� �κ�
			fputs("����,", f2);
			fputs("���������հ�,", f2);
			fputs("\n", f2);
		}
		fputs(strcat(drugs[(i + 1) * 7].year, ","), f2); // csv�� Ư���� ���� �����Ϳ� ������ ���̿� , �� �־���
		fputs(strcat(tot[i], ","), f2);
		fputs("\n", f2);
	}

	fclose(f);
	fclose(f2);
	//char c;
	//while (TRUE) {
	//	c = fgetc(f);
	//	if (c == EOF) {
	//		break;
	//	}
	//	printf("%c", c);
	//}

}// main