#include <stdio.h>

void main() {
	double temp;
	int outfitRecomm = 0;
	printf("현재 온도가 몇 도인가요? ");
	scanf_s("%lf", &temp);

	if (temp >= 30) {
		outfitRecomm = 1;
	} else if (temp >= 25) {
		outfitRecomm = 2;
	} else if (temp >= 15) {
		outfitRecomm = 3;
	} else if (temp >= 5) {
		outfitRecomm = 4;
	} else if (temp >= 0) {
		outfitRecomm = 5;
	} else {
		outfitRecomm = 6;
	}// if

	switch (outfitRecomm) {
		case 1:
			printf("너무 더워요! 반팔과 반바지를 입으세요.");
			break;
		case 2:
			printf("따뜻한 날씨입니다! 가벼운 옷을 입으세요.");
			break;
		case 3:
			printf("선선한 날씨입니다! 가벼운 겉옷을 챙기세요.");
			break;
		case 4:
			printf("조금 쌀쌀합니다! 따뜻한 옷을 입으세요.");
			break;
		case 5:
			printf("매우 춥습니다! 두꺼운 외투를 꼭 입으세요.");
			break;
		case 6:
			printf("한파 경고! 패딩과 장갑, 모자를 착용하세요.");
			break;
		default:
			printf("INTERNAL SYSTEM ERROR OCCURED");
			break;
	}// switch

}// main