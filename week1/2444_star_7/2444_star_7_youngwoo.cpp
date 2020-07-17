#include <stdio.h>

void printLine(int n, int raw);

int main(int argc, char const *argv[])
{
    int n, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        printLine(n, i);
    for(i = n-2; i >= 0; i--)
        printLine(n, i);
    return 0;
}

void printLine(int n, int raw) {
    for(int i = 0; i < n+raw; i++) {
        printf(i < n-raw-1 ? " " : "*");
    }
    printf("\n");
}
