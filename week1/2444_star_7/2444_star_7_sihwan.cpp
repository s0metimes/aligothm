#include<stdio.h>

int main(int argc, char **argv) {
    int input, i, j;
    

    scanf("%d", &input);

    for (i = 0; i < input; i++)
    {
        for (j = input - 1; j > i; j--)
        {
            printf(" ");
        }

        for (j = 0; j < 2*i+1; j++)
        {
            printf("*");
        }

        printf("\n");
    }

    for (i = 0; i < input - 1; i++)
    {
        for (j = 0; j <= i; j++)
        {
            printf(" ");
        }

        for (j = 2*(input-2); j > 2*i-1; j--)
        {
            printf("*");
        }

        printf("\n");
    }
    return 0;
}