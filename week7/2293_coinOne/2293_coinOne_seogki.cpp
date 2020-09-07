#include <stdio.h>

int DP[10001];
int COIN[101];
int N, K;

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++)
        scanf("%d", &COIN[i]);
    DP[0] = 1;
    for (int j = 1; j <= N; j++)
        for (int i = COIN[j]; i <= K; i++)
            DP[i] += DP[i - COIN[j]];
    printf("%d\n", DP[K]);
    return 0;
}