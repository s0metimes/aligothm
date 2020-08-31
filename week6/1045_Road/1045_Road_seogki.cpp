#include <iostream>
#include <queue>
using namespace std;

#define MAX 51
#define pii pair<int, int>

int P[MAX];
int N, M;
char R;
queue<pii> q;

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
    getchar();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            R = getchar();
            if (R == 'Y' && i < j) {
                q.push({})
            }
        }
        getchar();
    }
}