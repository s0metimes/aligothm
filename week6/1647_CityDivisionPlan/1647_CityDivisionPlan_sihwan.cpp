#include<stdio.h>
#include <queue>
#include <utility>

#define MAX 100000
#define Pii pair<int, int>

using namespace std;

int parents[MAX];
priority_queue<pair<int, Pii> > pq; // weight, (from, to)
int totalWeight;
int lastWeight;

int find(int a) {
    if(a == parents[a]) return a;
    else return parents[a] = find(parents[a]);
}

void unionWith(int from, int to) {
    parents[find(from)] = find(to);
}

void makeMST() {
    while(!pq.empty()) {
        pair<int, Pii> top = pq.top();
        int weight = -top.first;
        int from = top.second.first;
        int to = top.second.second;
        pq.pop();

        if(find(from) != find(to)) {
            unionWith(from, to);
            totalWeight += weight;
            lastWeight = weight;
        }
    }
}

int main(void) {
    int N;  // 2 ~ 100,000
    int M;  // 1 ~ 1,000,000
    int A, B, C;    // C 의 범위: 1 ~ 1,000
    int i;

    scanf("%d %d", &N, &M);

    for (i = 0; i < N; i++)
        parents[i] = i;

    while(M--) {
        scanf("%d %d %d", &A, &B, &C);
        pq.push(make_pair(-C, make_pair(A-1, B-1)));
    }

    makeMST();

    printf("%d\n", totalWeight-lastWeight);

    return 0;
}