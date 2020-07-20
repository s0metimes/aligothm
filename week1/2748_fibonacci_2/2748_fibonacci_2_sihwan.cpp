#include<stdio.h>

#define MAX 90

int main(int argc, char **argv) {
    int i, n;
    long long int fibonacci[MAX+1];
    
    scanf("%d", &n);

    for(i = 0; i <= n; i++) {
        if(i == 0)
            fibonacci[i] = 0;
        else if(i == 1)
            fibonacci[i] = 1;
        else
            fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }

    printf("%lld\n", fibonacci[n]);

    return 0;
}