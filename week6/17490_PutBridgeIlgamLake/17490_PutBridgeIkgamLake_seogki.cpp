#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 1000001
#define pii pair<int, int>

int N, M, T, K, ;
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
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 1; i <= N; i++)  // parent 배열 초기화
        P[i] = i;
}