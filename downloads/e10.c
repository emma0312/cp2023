#include <stdio.h>

int main() {
    int i; 
    printf("input an integer: ");
    scanf("%d", &i);

    if (i < 100) {
        printf("i < 100\n");
    } else {
        if ((i >= 100) && (i < 200)) {
            printf("i >= 100 and i < 200\n");
        } else {
            printf("i >= 200\n");
        }
    }

    return 0;
}