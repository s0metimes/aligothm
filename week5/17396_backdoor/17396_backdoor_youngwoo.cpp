#include <stdio.h>
#include <queue>
#include <vector>

#define MAXN 100010
#define MAXM 300010
#define INF 30000100000

using namespace std;
vector< long long int > dist(MAXN, INF);
int enemyArea[MAXN];
bool chk[MAXN];
vector< pair< int, int > > edges[MAXN]; // 정점, 가중치
priority_queue< pair< long long int, int > > pq; // 거리, 정점

void Dijkstra(int start) {
    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        pair< long long int, int > now = pq.top();
        pq.pop();
        chk[now.second] = true;
        for(auto e : edges[now.second]) {
            if(!chk[e.first] && dist[e.first] > -now.first + e.second) {
                dist[e.first] = -now.first + e.second;
                pq.push({-dist[e.first], e.first});
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int N, M;
    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; i++) 
        scanf("%d", &enemyArea[i]);
    enemyArea[N-1] = 0;

    int a, b, t;
    for(int e = 0; e < M; e++) {
        scanf("%d %d %d", &a, &b, &t);
        if(enemyArea[a] == 0 && enemyArea[b] == 0) {
            edges[a].push_back({b, t});
            edges[b].push_back({a, t});
        }
    }

    Dijkstra(0);

    if(dist[N-1] == INF) printf("-1\n");
    else printf("%lld\n", dist[N-1]);
    return 0;
}