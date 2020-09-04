/*

PASS 공부하고 다시 풀어볼것 

*/

#include <stdio.h>
#include <algorithm>

#define COST_MAX 10000
#define N_MAX 5000

int dp[N_MAX][COST_MAX];
double price[N_MAX];
int calorie[N_MAX];

int ftoi(double price);
void knapsack(int N, int iBudget);

int main(int argc, char const *argv[])
{
    int N, iBudget, i; double dBudget;

    while(1) {
        scanf("%d %lf", &N, &dBudget);
        iBudget = ftoi(dBudget);
        
        if(N == 0 && iBudget == 0) break;
        
        for(i = 1; i <= N; i++) 
            scanf("%d %lf", &calorie[i], &price[i]);
        
        knapsack(N, iBudget);

        printf("%d\n", dp[N][iBudget]);
    }
    
    return 0;
}

int ftoi(double price) {
    return (int)(price*100);
}

void knapsack(int N, int iBudget) {
    for(int k = 0; k < N; k++) {
        // k+1 번째 사탕을 넣을지 않넣을지에 따라 dp 수정
        for(int now = 1; now <= iBudget; now++) {  // now : 가지고 있는 돈
            // printf("now : %d, ftoi(price[k+1] : %d\n", now, ftoi(price[k+1]));
            if(now >= ftoi(price[k+1])) 
                dp[k+1][now] = std::max(dp[k][now], dp[k+1][ now-ftoi(price[k+1]) ] + calorie[k+1]);
            else
                dp[k+1][now] = dp[k][now];
        }
    }
}