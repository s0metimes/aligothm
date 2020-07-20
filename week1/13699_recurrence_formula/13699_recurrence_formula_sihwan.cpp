#include<stdio.h>

#define MAX 35

int main(int argc, char **argv) {
    int i, j, n;
    long long int t[MAX+1];
    
    scanf("%d", &n);

    for(i = 0; i <= n; i++) {
        if(i == 0)
            t[i] = 1;
        else {
            t[i] = 0;
            for(j = 0; j < i; j++) {
                t[i] += t[j]*t[i-j-1];
            }
        }
    }

    printf("%lld\n", t[n]);

    return 0;
}