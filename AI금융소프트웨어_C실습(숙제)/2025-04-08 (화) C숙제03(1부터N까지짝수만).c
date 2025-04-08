#include <stdio.h>

void main() {
    
    int n;
    scanf("%d", &n);
    int i = 1;
    
    while (i <= n) {
        if (i % 2 == 1) {
            i++;
            continue;
        }
        printf("%d ", i);
        i++;
    }// while 

}// main
