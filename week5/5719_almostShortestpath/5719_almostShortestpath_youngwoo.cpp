#include <stdio.h>
#include <queue>
#include <vector>

#define MAXN 510
#define INF 987654321

using namespace std;
vector< int > dist(MAXN, INF);
vector< pair< int, int > > beforeDestination;
bool chk[MAXN];
vector< pair< int, int > > edges[MAXN]; // 정점, 가중치
priority_queue< pair< int, int > > pq; // 거리, 정점

void Dijkstra(int start) {
    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        pair< int, int > now = pq.top();
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
    int N = 1, M = 1;
    
    while(1) {
        scanf("%d %d", &N, &M);

        // 0, 0 이면 테스트케이스 끝
        if(N == 0 && M == 0)
            break;
        
        int S, D;
        int U, V, P, i;
        
        // 시작 S, 도착점 D, 경로 입력받기 
        scanf("%d %d", &S, &D);
        for(i = 0; i < M; i++) {
            scanf("%d %d %d", &U, &V, &P);
            // 도착점 D와 연결된 경로는 따로 저장 
            if(V == D) beforeDestination.push_back({U, P});
            edges[U].push_back({V, P});
        }

        if(beforeDestination.size() == 0) {
            printf("-1\n");
            continue;
        }

        // 최단경로 구하기
        // 도착점 D를 제외한 최단경로 
        Dijkstra(S);

        printf("dist\n");
        for(int i = 0; i < N; i++)
            printf("%d ", dist[i]);
        printf("\n\n");

        printf("edges\n");
        for(int i = 0; i < N; i++) {
            printf("edges[%d]\n", i);
            for(auto e : edges[i])
                printf("from %d to %d ,len : %d\n", i, e.first, e.second);
            printf("\n");
        }
        printf("\n");
        
        printf("beforeDestination\n");
        for(auto e : beforeDestination)
            printf("from %d to %d len : %d\n", e.first, D, e.second);
        printf("\n\n");

        // 가장 비슷한 최단경로 구하기 
        int almostMin = INF;
        for(auto v : beforeDestination) {
            if(almostMin > (dist[v.first] + v.second) && (dist[v.first] + v.second) != dist[D]) 
                almostMin = dist[v.first] + v.second;
            printf("almostMin : %d v.first : %d v.second : %d dist[%d] : %d dist[%d] : %d\n", almostMin, v.first, v.second, v.first, dist[v.first], D, dist[D]);    
        }

        printf("%d\n", almostMin);
        
        // 초기화 
        beforeDestination.clear();
        for(i = 0; i < N; i++) {
            dist[i] = INF;
            edges[i].clear();
            chk[i] = false;
        }
    }
}