#include<stdio.h>
#include<queue>
#include<utility>

#define MAXN 1000
#define Pii pair<int, int>

using namespace std;

priority_queue<pair<int, Pii> > pq;
int types[MAXN];
int parents[MAXN];
int totalWeight;

int find(int a) {
    if(a == parents[a]) return a;
    else return parents[a] = find(parents[a]);
}

void unionWith(int a, int b) {
    parents[find(a)] = find(b);
}

void makeMST(int N) {
    while(!pq.empty()) {
        pair<int, Pii> top = pq.top();
        int from = top.second.first;
        int to = top.second.second;
        int weight = -top.first;
        pq.pop();

        if(types[from] != types[to] && find(from) != find(to)) {
            unionWith(from, to);
            totalWeight += weight;
        }
    }
}

bool isAllConnected(int N) {
    int root, i;
    for(i = 0; i < N; i++) {
        if(i == 0) root = find(i);
        else if(root != find(i)) {
            return false;
        }
    }

    return true;
}

int main(void) {
    int N;  // 2 ~ 1,000
    int M;  // 1 ~ 10,000
    int i;
    char type;
    int u, v, d;
    
    scanf("%d %d", &N, &M);
    
    for(i = 0; i < N; i++) {
        scanf(" %c ", &type);
        if(type == 'M')
            types[i] = 1;
        else if(type == 'W')
            types[i] = 0;
        
        parents[i] = i;
    }

    for(i = 0; i < M; i++) {
        scanf("%d %d %d", &u, &v, &d);
        pq.push(make_pair(-d, make_pair(u-1, v-1)));
    }
    
    makeMST(N);

    printf("%d\n", isAllConnected(N) ? totalWeight : -1);
        

    return 0;
}