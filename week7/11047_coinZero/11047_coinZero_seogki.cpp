#include <stdio.h>
#define MAX 11

int DP[MAX];
int N, K, R;

int main(void) {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
        scanf("%d", &DP[i]);
    for (int i = N - 1; i >= 0; i--) {
        R += K / DP[i];
        K %= DP[i];
    }
    printf("%d\n", R);
}