#include<stdio.h>

#define MAXN 100
#define MAXM 100000
#define INF 987654321

int dp[MAXN][MAXN];

int min(int a, int b) {
    return a < b ? a : b;
}

void printDp(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dp[i][j] == INF ? printf("0 ") : printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
}

void floyd(int n) {
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
}

int main(void) {
    int n;  // 도시의 개수 (1~100)
    int m;  // 버스의 개수 (1~100,000)
    int depart, arrive, cost;
    int i, j;
    /*
        dp initialize
    */
    for(i = 0; i < MAXN; i++)
        for(j = 0; j < MAXN; j++)
            i == j ? dp[i][j] = 0 : dp[i][j] = INF;

    /*
        input
    */
    scanf("%d", &n);
    scanf("%d", &m);
    for(i = 0; i < m; i++) {
        scanf("%d %d %d", &depart, &arrive, &cost);
        dp[depart-1][arrive-1] = min(dp[depart-1][arrive-1], cost);
    }
    
    floyd(n);
    printDp(n);
    
    return 0;
}