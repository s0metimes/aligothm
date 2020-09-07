#include<stdio.h>

#define MAXN 100
#define MAXVALUE 100000

int coins[MAXN];
int dp[MAXVALUE+1];

int main(void) {
    int n;  // 1~100
    int k;  // 1~10,000
    int i, j;
    
    scanf("%d %d", &n, &k);

    for(i = 0; i < n; i++) scanf("%d", &coins[i]);
    
    dp[0] = 1;
    for(i = 0; i < n; i++) {
        for(j = coins[i]; j <= k; j++)
            dp[j] += dp[j-coins[i]];
    }

    printf("%d\n", dp[k]);

    return 0;
}