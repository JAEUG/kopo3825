#include <stdio.h>

typedef union {
    int intVal;
    float floatVal;
    char charVal;
} Datas;

void main() {
    Datas d;
    d.intVal = 10;
    printf("int형으로 초기화 했을때의 Datas의 값은: %d / Datas의 주소값은: %p\n", d.intVal, &d.intVal);
    
    d.floatVal = 31.23;
    printf("float형으로 초기화 했을때의 Datas의 값은: %f / Datas의 주소값은: %p\n", d.floatVal, &d.floatVal);
    
    d.charVal = 'A';
    printf("char형으로 초기화 했을때의 Datas의 값은: %c / Datas의 주소값은: %p\n", d.charVal, &d.charVal);
    
    printf("\n초기화 종료 후 데이터(int형): %d / 주소: %p\n", d.intVal, &d.intVal);
    printf("초기화 종료 후 데이터(float형): %f / 주소: %p\n", d.floatVal, &d.floatVal);
    printf("초기화 종료 후 데이터(char형): %c / 주소: %p\n", d.charVal, &d.charVal);
    // 공용체의 크기는 멤버변수 중 가장 큰 자료형의 크기에 의해 결정된다
    // 공용체 안의 멤버 변수는 모두 똑같은 주소값을 가진다
}