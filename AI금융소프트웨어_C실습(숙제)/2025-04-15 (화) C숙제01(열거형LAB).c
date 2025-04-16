#include <stdio.h>
typedef enum {
    SEDAN = 1,
    SUV,
    TRUCK,
    VAN
} Cars;

void main() {
    int userChoice;
    printf("번호를 고르세요: ");
    int stored = scanf("%d", &userChoice);
    // scanf가 값을 저장하지 못하면(유저가 다른 자료형의 데이터를 입력) 재입력 받음
    while (stored != 1) {
        printf("입력값을 인식하지 못하였습니다.\n");
        while(getchar() != '\n'); // 버퍼 비워주기
        printf("번호를 고르세요: ");
        stored = scanf("%d", &userChoice);
    }
    
    Cars c;
    switch (userChoice) {
        case 1:
            c = SEDAN;
            if (c == userChoice) {
                printf("%d번 차량은 SEDAN입니다.", c);
            }
            break;
        case 2:
            c = SUV;
            if (c == userChoice) {
                printf("%d번 차량은 SUV입니다.", c);
            }
            break;
        case 3:
            c = TRUCK;
            if (c == userChoice) {
                printf("%d번 차량은 TRUCK입니다.", c);
            }
            break;
        case 4:
            c = VAN;
            if (c == userChoice) {
                printf("%d번 차량은 VAN입니다.", c);
            }
            break;            
        default:
            printf("지원되지 않는 번호입니다.");
            break;
    }// switch
    
}// main
