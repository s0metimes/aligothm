#include<stdio.h>
#include<utility>
#include<algorithm>

using namespace std;

#define MAXN 5000
#define MAXM 10000
#define Pii pair<int, int>

int dp[MAXM+1];
Pii candies[MAXN];  // calorie, price

void unboundedKnapsack(int n, int m) {
    int i, j;
    for(i = 0; i < n; i++) {
        int calorie = candies[i].first;
        int price = candies[i].second;
        for(j = price; j <= m; j++)
            dp[j] = max(dp[j-price]+calorie, dp[j]);
    }
}

void initialize() {
    int i;
    for(i = 0; i < MAXM+1; i++) dp[i] = 0;
    for(i = 0; i < MAXN; i++) candies[i] = make_pair(0, 0);
}

int main(void) {
    int n;  // 1~5000
    int m;  // 1~10000
    float originalM;  // 0.01~100.00
    int c, p;
    float originalP;
    int i;
    
    while(true) {
        initialize();
        scanf("%d %f", &n, &originalM);
        if(n == 0) break;

        m = (int)(originalM * 100);
        for(i = 0; i < n; i++) {
            scanf("%d %f", &c, &originalP);
            p = (int)(originalP * 100);
            candies[i] = make_pair(c, p);
        }

        unboundedKnapsack(n, m);
        printf("%d\n", dp[m]);
    }

    return 0;
}