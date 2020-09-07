#include<stdio.h>
#include<algorithm>

#define MAXN 300
#define MAXM 20

int companies[MAXM][MAXN+1];  // 특정 금액만큼 투자했을 떄 얻는 이익
int dp[MAXM][MAXN+1];   // 특정 번째 회사까지 투자했을 때 얻는 최대 이익
int tmpInvests[MAXM][MAXN+1];  // dp 값이 얼마일 때에 따라 각 기업에 투자한 금액
int invests[MAXM];     // 실제로 각 기업에 투자한 금액

void knapsack(int N, int M) {
    int i, j, k;
    for(i = 0; i < M; i++) {
        for(j = 1; j <= N; j++) {
            if(i == 0) {
                dp[i][j] = companies[i][j];
                tmpInvests[i][j] = j;
                continue;
            }

            for(k = 0; k <= j; k++) {
                int newProfit = dp[i-1][j-k] + companies[i][k];
                if(dp[i][j] < newProfit) {
                    dp[i][j] = newProfit;
                    tmpInvests[i][j] = k;
                }
            }
        }
    }
}

int main(void) {
    int N;  // 투자 금액, 1~300
    int M;  // 투자 기업, 1~20
    int i, j;
    int invest, profit;
    
    scanf("%d %d", &N, &M);
    
    for(i = 0; i < N; i++) {
        scanf("%d", &invest);
        for(j = 0; j < M; j++) {
            scanf("%d", &profit);
            companies[j][invest] = profit;
        }
    }

    knapsack(N, M);

    j = N;
    for(i = M-1; i >=0; i--) {
        invests[i] = tmpInvests[i][j];
        j -= tmpInvests[i][j];
    }

    printf("%d\n", dp[M-1][N]); 
    
    for(i = 0; i < M; i++) printf("%d ", invests[i]);
    printf("\n");

    return 0;
}   