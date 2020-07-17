#include <stdio.h>

#define MAX 90

int f[MAX+3];

int fibo(int n);
// int fibo2(int n);

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    printf("%d\n", fibo(n));
    return 0;
}

// 누적
int fibo(int n) {
    if(n == 0) return 0;
    else if(n == 1) return 1;

    int i;
    f[1] = 1;
    for(i = 1; i < n; i++) {
        f[i+1] += f[i];
        f[i+2] += f[i];
    }
    return f[n];
}

/*
// recursive function
int fibo2(int n) {
    if(n == 0) return 0;
    else if(n == 1) return 1;
    else return fibo2(n-1) + fibo2(n-2);
}
*/