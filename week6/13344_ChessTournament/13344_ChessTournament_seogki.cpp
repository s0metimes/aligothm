#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 50001
#define pii pair<int, int>

queue<pii> qu;
vector<int> map[MAX];
int chk[MAX];
int N, M, K, L;
int P[MAX];
char sign;

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

bool checkPossible(int here) {
    if (chk[here]) {
        if (chk[here] == -1) {
            return true;
        }
        return false;
    }

    chk[here] = -1;
    for (int there : map[here]) {
        if (checkPossible(there)) {
            return true;
        }
    }
    chk[here] = 1;

    return false;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)  // parent 배열 초기화
        P[i] = i;
    for (int i = 0; i < M; i++) {
        scanf("%d %c %d", &K, &sign, &L);
        if (sign == '=')
            UNION(K, L);
        else
            qu.push({K, L});
    }

    while (!qu.empty()) {
        pii now = qu.front();
        qu.pop();
        int u = FIND(now.first);
        int v = FIND(now.second);
        map[u].push_back(v);
    }

    for (int i = 0; i <= N; ++i) {
        if (checkPossible(i)) {
            printf("inconsistent\n");
            return 0;
        }
    }
    printf("consistent\n");
}