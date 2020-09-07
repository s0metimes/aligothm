#include <stdio.h>
#define INF 987654321
#define MAX 10001
#define min(a, b) ((a) > (b)) ? (b) : (a)

int N, K;
int DP[MAX];
int COIN[101];

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++)
        scanf("%d", &COIN[i]);
    DP[0] = 0;
    for (int i = 1; i < MAX; i++)
        DP[i] = INF;
    for (int j = 1; j <= N; j++)
        for (int i = COIN[j]; i <= K; i++)
            DP[i] = min(DP[i - COIN[j]] + 1, DP[i]);
    if (DP[K] == INF)
        printf("-1");
    else
        printf("%d\n", DP[K]);
}