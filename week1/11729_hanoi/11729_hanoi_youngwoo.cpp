#include <stdio.h>

#define MAX 20

int hanoi[MAX+1];
void printHanoi(int plate, int from, int to);

int main(int argc, char const *argv[])
{
    int num;

    scanf("%d", &num);

    hanoi[1] = 1;
    hanoi[2] = 3;

    for(int i = 3; i <= num; i++) {
        hanoi[i] = hanoi[i-1]*2 + 1;
    }

    printf("%d\n", hanoi[num]);
    printHanoi(num, 1, 3);
    return 0;
}

void printHanoi(int plate, int from, int to) {
    
    if(plate == 0) return;
    printHanoi(plate - 1, from, 6-from-to);
    printf("%d %d\n",from, to);
    printHanoi(plate - 1, 6-from-to, to);
}
