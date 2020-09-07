#include<stdio.h>

#define MAXN 20
#define MAXM 10000

int coins[MAXN], dp[MAXM+1];

int main(void) {
    int T;  // 1~10
    int N;  // 1~20, 금액은 1~10,000, 오름차순으로 줌.
    int M;  // 1~10,000
    int i, j;

    scanf("%d", &T);
    
    while(T--) {
        scanf("%d", &N);
        for(i = 0; i < N; i++) scanf("%d", &coins[i]);
        scanf("%d", &M);

        for(i = 0; i <= M; i++) dp[i] = 0;
        
        dp[0] = 1;
        for(i = 0; i < N; i++)
            for(j = coins[i]; j <= M; j++)
                dp[j] += dp[j-coins[i]];

        printf("%d\n", dp[M]);
    }
    return 0;
}   