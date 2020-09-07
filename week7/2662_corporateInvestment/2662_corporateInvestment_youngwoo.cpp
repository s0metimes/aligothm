#include <stdio.h>
#include <vector>
#include <algorithm>
#define N_MAX 300
#define M_MAX 20

using namespace std;

// com : 회사
// in : 투자한 시간
// profit[com][in] : 이익
int cost[N_MAX+1];
int profit[M_MAX+1][M_MAX+1]; 
// dp[com][have][in] in : 0 이면 최대이익, in >= 1이면 해당 in 회사에 투자한 금액 

// dp[com][in] : 자금이 in만큼 있는 상황에서 com 회사를 고려했을 때 최댓값
int dp[M_MAX+1][N_MAX+1][N_MAX+1]; // dp[com][have][in] 

int main(int argc, char const *argv[])
{
    /* code */
    // N : 투자 금액 (1 ≤ N ≤ 300) 
    // M : 기업 수 (1 ≤ M ≤ 20)
    int N, M;

    scanf("%d %d", &N, &M);

    for(int in = 1; in <= N; in++) {
        scanf("%d", &cost[in]);
        for(int com = 1; com <= M; com++) {
            scanf("%d", &profit[com][in]);            
        }
    }
    for(int com = 0; com <= M; com++) {   // dp[com+1]을 구하기 위한 값
        for(int have = 1; have <= N; have++) { // 현재 보유한 금액
            for(int in = 0; in <= have; in++) { // com+1 회사에 투자할 금액(인덱스)
                
                if(dp[com+1][have][0] < dp[com][have-in][0] + profit[com+1][in]) {
                    dp[com+1][have][com+1] = cost[in];
                    for(int div = 1; div <= com; div++) 
                        dp[com+1][have][div] = dp[com][have-in][div];
                    dp[com+1][have][0] = dp[com][have-in][0] + profit[com+1][in];
                }
            }
        }
    }

    printf("%d\n", dp[M][N][0]);

    for(int i = 1; i <= M; i++)
        printf("%d ", dp[M][N][i]);
    printf("\n");

    return 0;
}
