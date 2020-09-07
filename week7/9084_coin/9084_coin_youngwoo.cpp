#include <stdio.h>

#define N_MAX 20
#define M_MAX 10000

int dp[M_MAX+1];
int coin[N_MAX+1];

void init() {
    dp[0] = 1;
    for(int i = 1; i < M_MAX+1; i++) dp[i] = 0;
    for(int i = 0; i < N_MAX+1; i++) coin[i] = 0;
}

int DP(int M, int N) {  // money : 만들어야 할 금액 , N : coin종류의 갯수
    for(int c = 0; c < N; c++) 
        for(int k = coin[c]; k <= M; k++)   // k : 현재 만들 금액
            dp[k] += dp[k-coin[c]];
        
    return dp[M];
}

int main(int argc, char const *argv[])
{ 
    int T, N, i, M;

    scanf("%d", &T);
    while(T--) { // T번의 test case 

        init(); // dp 와 coin 초기화 

        scanf("%d", &N);
        for(i = 0; i < N; i++) // N 개의 종류의 동전
            scanf("%d", &coin[i]); // 주어진 동전의 종류(화폐 가치)

        scanf("%d", &M);    // M : 만들어야 할 금액

        printf("%d\n", DP(M, N));
    }
    return 0;
}
