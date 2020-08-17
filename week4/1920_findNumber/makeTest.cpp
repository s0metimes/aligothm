#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void) {
    srand(time(NULL));

    printf("100000\n");
    for(int i = 0; i < 100000; i++) {
        printf("%d ", (int)((rand() % 2147483647) - (rand() % 2147483648)));
    }
    printf("\n");
    printf("100000\n");
    for (int i = 0; i < 100000; i++)
    {
        printf("%d ", (int)((rand() % 2147483647) - (rand() % 2147483648)));
    }
    printf("\n");
    return 0;
}