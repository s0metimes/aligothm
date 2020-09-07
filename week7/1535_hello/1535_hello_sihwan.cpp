#include<stdio.h>

#define MAXN 20
#define MAXHP 100

int dp[MAXN+1][MAXHP+1];
int pleasure[MAXN+1];
int hpLost[MAXN+1];

int max(int a, int b) {
    return a > b ? a : b;
}

int knapsack(int N) {
    int i, j;
    for(i = 0; i < N; i++) {
        for(j = 1; j <= MAXHP; j++) {
            if(j >= hpLost[i+1])
                dp[i+1][j] = max(dp[i][j], dp[i][j-hpLost[i+1]] + pleasure[i+1]);
            else
                dp[i+1][j] = dp[i][j];
        }
    }

    return dp[N][MAXHP-1];
}

int main(void) {
    int N;  // 사람 수, 1~20
    int i, j;
    
    scanf("%d", &N);
    for(i = 1; i <= N; i++) scanf("%d", &hpLost[i]);
    for(i = 1; i <= N; i++) scanf("%d", &pleasure[i]);
    
    printf("%d\n", knapsack(N));

    return 0;
}