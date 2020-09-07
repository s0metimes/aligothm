#include <stdio.h>
#include <algorithm>

#define COST_MAX 10000
#define N_MAX 5000

int dp[COST_MAX+1];
float price[N_MAX+1];
int calorie[N_MAX+1];

int ftoi(float price);
void knapsack(int N, int iBudget);

int main(int argc, char const *argv[])
{
    int N, iBudget, i; float dBudget;

    while(1) {
        scanf("%d %f", &N, &dBudget);
        iBudget = ftoi(dBudget);
        
        if(N == 0 && iBudget == 0) break;
        
        for(i = 1; i <= N; i++) 
            scanf("%d %f", &calorie[i], &price[i]);

        knapsack(N, iBudget);

        printf("%d\n", dp[iBudget]);

        for(int i = 1; i <= iBudget; i++) dp[i] = 0;
    }
    
    return 0;
}

int ftoi(float price) { return (int)(price*100); }

void knapsack(int N, int iBudget) {
    for(int k = 0; k < N; k++) 
        // k+1 번째 사탕을 넣을지 않넣을지에 따라 dp 수정
        for(int now = 1; now <= iBudget; now++)   // now : 가지고 있는 돈
            if(now >= ftoi(price[k+1])) 
                dp[now] = std::max(dp[now], dp[ now-ftoi(price[k+1]) ] + calorie[k+1]);  
}