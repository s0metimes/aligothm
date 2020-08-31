#include <iostream>
using namespace std;

#define MAX 1000001

int N, M, X, Y;
int chk[MAX];

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &X, &Y);
        chk[X]++;
        chk[Y]--;
    }
    int sum = 0, ans = N;
    for (int i = 1; i < N; i++) {
        sum += chk[i];
        if (sum)
            ans--;
    }
    printf("%d\n", ans);
}
