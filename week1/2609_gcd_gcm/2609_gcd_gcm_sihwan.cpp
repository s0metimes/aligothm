#include<stdio.h>

int main(int argc, char **argv) {
    int a, b, big, small, remain, gcd, tmp;
    
    scanf("%d %d", &a, &b);
    
    big = a > b ? a : b;
    small = a > b ? b : a;
    
    gcd = small;
    remain = big % small;
    while(remain != 0) {
        tmp = remain;
        remain = gcd % remain;
        gcd = tmp;
    }

    printf("%d\n", gcd);
    printf("%d\n", a*b/gcd);

    return 0;
}