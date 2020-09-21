#include <stdio.h>
#include <math.h>
#define MAX 1000

int fix(int num) {
    if(num == 100) return num;

    int one = num%10;
    int ten = num/10; 
    if(one == 0 || one == 6 || one == 9) one = 9;
    
    if(num < 10) return one;

    if(ten == 0 || ten == 6 || ten == 9) ten = 9;
    return ten*10 + one;
}

int main(int argc, char const *argv[])
{
    int N, i, sum = 0;
    scanf("%d", &N);
    for(i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        sum += fix(num);
    }

    printf("%d\n", (int)round(sum/(float)N));
    
    return 0;
}