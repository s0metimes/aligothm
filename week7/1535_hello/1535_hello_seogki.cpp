#include <stdio.h>
#include <string.h>
#define MAX 21
#define max(a, b) ((a) > (b)) ? (a) : (b)

int N;
int L[MAX], J[MAX];
int DP[101][MAX];  // DP[capacity][idx] = max(DP[capacity][idx+1],DP[capacity−item[idx]][idx+1])

int solve(int h, int here) {
    if (here == N)
        return 0;
    int &ans = DP[h][here];
    if (ans != -1)
        return ans;

    ans = solve(h, here + 1);
    if (h - L[here] > 0)
        ans = max(ans, solve(h - L[here], here + 1) + J[here]);
    return ans;
}

int main() {
    memset(DP, -1, sizeof(DP));
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &L[i]);
    for (int i = 0; i < N; i++)
        scanf("%d", &J[i]);
    printf("%d\n", solve(100, 0));
}
