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
int profit[M_MAX+1][M_MAX+1]; // [com, in] 

// dp[com][in] : 자금이 in만큼 있는 상황에서 com 회사를 고려했을 때 최댓값
int dp[M_MAX+1][N_MAX+1][N_MAX+1]; // [com, in] 

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
            printf("현재 투자하기위해 주목하고있는 회사는 %d 이며, 현재 보유한 금액은 %d 입니다.\n", com+1, have);
            for(int in = 0; in <= have; in++) { // com+1 회사에 투자할 금액
                // com+1회사까지 고려한 상황에서 자본은 have만큼 가지고 있을때, com+1에 회사에 투자할 금액이 in인경우
                // 기존의 have-in의 자금으로 얻을 수 있는 최대 이익은 dp[com][have-in]이므로,
                // dp[com][have-in]+profit[com+1][in] 과 기존의 dp[com+1][have]를 비교해서 최댓값을 갱신해주면된다.
                // in 같은 경우, 0부터 have까지 돈다.
                if(dp[com+1][have][0] < dp[com][have-in][0] + profit[com+1][in]) {
                    printf("dp[%d][%d][0](%d) 이 dp[%d][%d][0](%d) + profit[%d][%d](%d) 보다 작으므로 갱신됩니다.\n", com+1, have,dp[com+1][have][0], com, have-in, dp[com][have-in][0], com+1, in, profit[com+1][in]);
                    printf("%d 회사에는 %d만큼 투자했습니다.\n", com+1, cost[in]);
                    dp[com+1][have][com+1] = cost[in];
                    printf("각 회사에 투자한 금액은 다음과 같습니다.\n");
                    for(int div = 1; div <= com; div++) {
                        dp[com+1][have][div] = dp[com][have-in][div];
                        printf("%2d", dp[com+1][have][div]);
                    }
                    printf("%2d\n", dp[com+1][have][com+1]);
                    dp[com+1][have][0] = dp[com][have-in][0] + profit[com+1][in];
                }
            }
            printf("%d 만큼의 자본으로 얻을 수 있는 최대 이익은 dp[%d][%d][0]에 %d로 저장되었습니다.\n", have, com+1, have, dp[com+1][have][0]);
        }
    }
        
    for(int com = 0; com <= M; com++) {
        for(int have = 1; have <= N; have++) {
            printf("%3d(", dp[com][have][0]);
            for(int i = 1; i <= com; i++)
                printf("%2d",dp[com][have][i]);
            printf(")");
        }
        printf("\n");
    }

    printf("%d\n", dp[M][N][0]);

    for(int i = 1; i <= M; i++)
        printf("%d ", dp[M][N][i]);
    printf("\n");

    return 0;
}
