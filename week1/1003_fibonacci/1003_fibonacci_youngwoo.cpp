#include <stdio.h>

#define MAX 40

int dp[MAX+1][2];

void fibo(int n);

int main(int argc, char const *argv[])
{
    int time, n, i;

    scanf("%d", &time);

    for(i = 0; i < time; i++) {
        scanf("%d", &n);
        fibo(n);
        printf("%d %d\n", dp[n][0], dp[n][1]);
    }
    return 0;
}

void fibo(int n) {
    dp[0][1] = dp[1][0] = 0;
    dp[0][0] = dp[1][1] = 1;
    for(int i = 2; i<= n; i++) {
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1];
    }  
}