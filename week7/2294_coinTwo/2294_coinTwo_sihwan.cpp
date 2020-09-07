#include<stdio.h>

#define MAXN 100
#define MAXVALUE 10000

int cnt;
int coins[MAXN];
int dp[MAXVALUE+1];

int min(int a, int b) {
    return a > b ? b : a;
}

int main(void) {
    int n, k;
    int i, j;

    scanf("%d %d", &n, &k);
    for(i = 0; i < n; i++) scanf("%d", &coins[i]);
    for(i = 0; i <= k; i++) dp[i] = MAXVALUE+1;

    for(i = 0; i <= k; i++) {
        for(j = 0; j < n; j++) { 
            if(i == coins[j]) dp[i] = 1;
            else if(i > coins[j]) dp[i] = min(dp[i], dp[i-coins[j]]+1);
        }
    }

    printf("%d\n", dp[k] == MAXVALUE+1? -1 : dp[k]);

    return 0;
}