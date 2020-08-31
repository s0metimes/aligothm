#include<stdio.h>
#include<queue>
#include<utility>

#define MAX 10000
#define Pii pair<int, int>

using namespace std;

int parents[MAX];
priority_queue<pair<int, Pii> > pq;   // weight, (from, to)
int totalWeight;

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
        }
    }
}

int main(void) {
    int V;  // 정점 수, 1 ~ 10,000
    int E;  // 간선 수, 1 ~ 100,000
    int A, B, C;    // C 의 범위: 1 ~ 1,000,000
    int i;

    for(i = 0; i < MAX; i++)
        parents[i] = i;
    
    scanf("%d %d", &V, &E);
    for(i = 0; i < E; i++) {
        scanf("%d %d %d", &A, &B, &C);

        pq.push(make_pair(-C, make_pair(A-1, B-1)));
    }

    makeMST();

    printf("%d\n", totalWeight);

    return 0;
}