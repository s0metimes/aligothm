#include <stdio.h>
#include <string.h>
#define MAX 10001
#define MAX_coin 21

int DP[MAX];
int COIN[MAX_coin];
int T, N, M;

int main() {
    scanf("%d", &T);
    while (T--) {
        memset(DP, 0, sizeof(DP));

        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
            scanf("%d", &COIN[i]);
        scanf("%d", &M);
        DP[0] = 1;
        for (int i = 1; i <= N; i++)
            for (int j = COIN[i]; j <= M; j++)
                DP[j] += DP[j - COIN[i]];
        printf("%d\n", DP[M]);
    }
}