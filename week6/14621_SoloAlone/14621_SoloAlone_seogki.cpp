#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001
#define pii pair<int, int>
#define edge pair<int, pii>

priority_queue<edge, vector<edge>, greater<edge>> pq;
int P[MAX];
bool moreMan[MAX];
int N, M, u, v, d, res;
char TMP;

int FIND(int node) {
    if (node == P[node])
        return node;
    return P[node] = FIND(P[node]);
}

void UNION(int a, int b) {
    a = FIND(a);
    b = FIND(b);
    P[b] = a;
}

int main() {
    scanf("%d %d", &N, &M);
    //초기화
    for (int i = 1; i <= N; i++)
        P[i] = i;

    // 남초인지 여초인지 확인
    for (int i = 1; i <= N; i++) {
        scanf(" %c ", &TMP);
        if (TMP == 'M')
            moreMan[i] = 1;
    }
    // (남 - 여) 이거나 (여 - 남) 일떄만 추가
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &u, &v, &d);
        if (moreMan[u] ^ moreMan[v])
            pq.push({d, {u, v}});
    }
    // MST 생성
    while (!pq.empty()) {
        edge now = pq.top();
        pq.pop();
        int edge1 = now.second.first;
        int edge2 = now.second.second;
        int weight = now.first;
        if (FIND(edge1) != FIND(edge2)) {
            UNION(edge1, edge2);
            res += weight;
        }
    }
    bool connectionError = 0;
    int test = FIND(1);
    for (int i = 2; i <= N; i++) {
        if (test != FIND(i))
            connectionError = 1;
    }
    if (connectionError)
        printf("-1\n");
    else
        printf("%d\n", res);
}
