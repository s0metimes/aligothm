#include <iostream>
#include <queue>
using namespace std;
#define MAX 10001
#define pii pair<int, int>
#define edge pair<int, pii>

priority_queue<edge, vector<edge>, greater<edge>> pq;
int V, E, A, B, C, res;
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
    scanf("%d %d", &V, &E);
    for (int i = 1; i <= V; i++)
        P[i] = i;
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &A, &B, &C);
        pq.push({C, {A, B}});
    }

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

    printf("%d\n", res);
}