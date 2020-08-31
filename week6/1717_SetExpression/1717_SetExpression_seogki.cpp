#include <stdio.h>
#define MAX 1000001
int N, M;
int C, A, B;

int P[MAX];

int FIND(int node) {
    if (node == P[node])
        return node;
    return P[node] = FIND(P[node]);
}

void UNION(int a, int b) {
    int root_a = FIND(a);
    int root_b = FIND(b);
    P[root_b] = root_a;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
        P[i] = i;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &C, &A, &B);
        if (C == 0) {
            UNION(A, B);
        } else {
            printf("%s\n", (FIND(A) == FIND(B)) ? "YES" : "NO");
        }
    }
}