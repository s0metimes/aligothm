#include <stdio.h>

#define MAX 35

long long int t[MAX+1];

long long int fun_t(int n);

int main(int argc, char const *argv[])
{
    int n, i;
    scanf("%d", &n);

    t[0] = 1;

    printf("%lld\n", fun_t(n));
    return 0;
}

long long int fun_t(int n) {
    if(n == 0) 
        return 1;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < n; j++) {
            t[i] += t[j]*t[i-j-1];
        }
    }
    return t[n];  
}
