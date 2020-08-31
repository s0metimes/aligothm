#include <iostream>
#include <queue>
using namespace std;
#define MAX 100001
#define pii pair<int, int>
#define edge pair<int, pii>

priority_queue<edge, vector<edge>, greater<edge>> pq;
int N, M, A, B, C, sum;
int P[MAX];

int FIND(int node) {
    if (node == P[node])
        return node;
    return P[node] = FIND(P[node]);
}

void UNION(int x, int y, int z) {
	x = FIND(x);
	y = FIND(y);
	if (x == y)return;
	P[x] = y;
	sum += z;
	N--;
}

int main() {
    scanf("%d%d", &N, &M);
	for (int i = 0; i <= N; i++) {
		P[i] = i;
	}
	int a, b, c;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		pq.push({ c,{ a,b } });
	}
	while (!pq.empty()) {
		if (N == 2) break;
		int a = pq.top().second.first;
		int b = pq.top().second.second;
		int w = pq.top().first;
		UNION(a, b, w);
		pq.pop();
	}
	printf("%d\n", sum);
}