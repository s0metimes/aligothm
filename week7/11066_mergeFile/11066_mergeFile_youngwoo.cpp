#include <stdio.h>
#include <algorithm>
#define MAX 500
#define INF 987654321
using namespace std;

int dp[MAX+1][MAX+1];
int cost[MAX+1];

void init(int K) {
    for(int i = 1; i <= K; i++)
        for(int j = 1; j <= K; j++) 
            dp[i][j] = (i == j) ? 0 : INF;
}

void intervalDP(int K) {
    for(int sz = 2; sz <= K; sz++) {
        for(int front = 1; front + sz-1 <= K; front++) {
            int minV = INF;
            for(int div = 1; div < sz; div++) 
                minV = min(minV, dp[front][front+div-1] + dp[front+div][front+sz-1] + cost[front+sz-1] - cost[front-1]);
            dp[front][front+sz-1] = minV;
        }
    }
    printf("%d\n", dp[1][K]);
}

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);

    while(T--) {
        int K, i, acc = 0, value;
        scanf("%d", &K);

        init(K);

        for(i = 1; i <= K; i++) {
            scanf("%d", &value);
            acc += value;
            cost[i] = acc;
        }

        intervalDP(K);
    }
    return 0;
}