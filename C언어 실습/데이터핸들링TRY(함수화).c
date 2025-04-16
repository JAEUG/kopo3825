#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996)
#pragma warning(disable: 4700)
#define TRUE 1
#define YEAR_SIZE 100
#define AGERANGE_SIZE 200
#define CRIMINALS_SIZE 100

typedef struct { // ����, ���ɴ�, ���������� �� ��������� ������ ����ü
	char year[YEAR_SIZE];					// ����
	char ageRange[AGERANGE_SIZE];			// ���ɴ�
	char numberOfCriminals[CRIMINALS_SIZE];	// ����������
} drug;

void readFileAndSetDrugs(FILE *f, drug *drugs) { // ������ ������ �����鼭 ���ÿ� ����ü �迭�� ���� �־��ִ� �Լ�
	char line[1024];
	int i = 0;
	while (fgets(line, sizeof(line), f)) { // ���� ������ ������ �б�
		char* content = strtok(line, ",");
		strcpy(drugs[i].year, content);

		content = strtok(NULL, ",");
		strcpy(drugs[i].ageRange, content);

		content = strtok(NULL, ",");
		strcpy(drugs[i].numberOfCriminals, content);

		printf("%s / %s / %s\n", drugs[i].year, drugs[i].ageRange, drugs[i].numberOfCriminals); // ���Ͼ��� ���� Ȯ��

		i++;
	}
}// readFileAndSetDrugs()

void getTotalNumberOfCriminalsForEachYearAndWriteToCsv(FILE *f2, drug *drugs, int size) { // �� �⵵���� ������������ �հ踦 ���Ͽ� ���ο� csv�� �����ϴ� �Լ�
	int tot2015 = 0, tot2016 = 0, tot2017 = 0, tot2018 = 0, tot2019 = 0, tot2020 = 0, tot2021 = 0, tot2022 = 0, tot2023 = 0, tot2024 = 0;

	// numberOfCriminals�� �հ踦 ���ϱ� ���� ���ڿ��� ������ ����ȯ���ִ� atoi()�Լ� ���
	for (int i = 1; i < size; i++) { // �Ӽ�(���� etc...) �κ��� ����
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

	// ���Ͽ� �Է��ϱ� ���� ������ ���ڿ��� ����ȯ���ִ� sprintf(���ڿ�����, "����(ex: %d)", ��������) �Լ� ���
	char tot[10][10]; // ������ ���������� ��谪�� ������� ���ڿ� �迭

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
	// ������ ������������� 2���� �����͸��� �̿��Ͽ� ���ο� csv�� ����
	for (int i = 0; i < 10; i++) {
		if (i == 0) { // �� ������ �Ӽ� �κ�(����, ���������Ѱ�)
			fputs("����,", f2);
			fputs("���������հ�,", f2);
			fputs("\n", f2);
		}
		fputs(strcat(drugs[(i + 1) * 7].year, ","), f2); // csv�� Ư���� ���� �����Ϳ� ������ ���̿� , �� �־���
		fputs(strcat(tot[i], ","), f2);
		fputs("\n", f2); // �Է� ������ �κи��� �ٹٲ�
	}
}// getTotalNumberOfCriminalsForEachYearAndWriteToCsv()

void main() {
	drug drugs[71] = {
		{"dummy", "dummy", "dummy"} 
	};
	int drugsSize = sizeof(drugs) / sizeof(drug); // ����ü �迭�� ũ��
	FILE *f = fopen("2015~2024���������ɺ�������������(������).csv", "r");
	if (f == NULL) {
		printf("failed to load file");
		return;
	}
	readFileAndSetDrugs(f, drugs);

	FILE *f2 = fopen("2015~2024 ������ �����������.csv", "w");
	getTotalNumberOfCriminalsForEachYearAndWriteToCsv(f2, drugs, drugsSize);

	fclose(f);
	fclose(f2);
}// main