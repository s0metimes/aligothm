#include <stdio.h>
#include <string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define MAX 10001

int DP[MAX];
int N, C;
double M1, P1;

int main() {
    while (true) {
        memset(DP, 0, sizeof(DP));
        scanf("%d %lf", &N, &M1);

        int M = (int)(M1 * 100 + 0.5);
        if (N == 0 && M == 0)
            break;
        for (int i = 1; i <= N; i++) {
            scanf("%d %lf", &C, &P1);
            int P = (int)(P1 * 100 + 0.5);
            for (int j = P; j <= M; j++)
                DP[j] = max(DP[j], DP[j - P] + C);
        }
        printf("%d\n", DP[M]);
    }
}