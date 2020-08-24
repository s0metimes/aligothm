#include<stdio.h>
#include<vector>
#include <utility>

#define MAXN 500
#define INF 987654321

using namespace std;

#define Pii pair<int, int>


int dist[MAXN];
vector<pair<int, Pii> > edges;


bool bellmanFord(int N) {
    int i, j, k;
    
    for(i = 1; i < N; i++) {
        for(auto iter = edges.begin(); iter != edges.end(); ++iter) {
            pair<int, Pii> p = (*iter);
            int from = p.first;
            int to = p.second.first;
            int weight = p.second.second;
            if(dist[from] != INF && dist[to] > dist[from] + weight)
                dist[to] = dist[from] + weight;
        }
    }
    for(auto iter = edges.begin(); iter != edges.end(); ++iter) {
        pair<int, Pii> p = (*iter);
        int from = p.first;
        int to = p.second.first;
        int weight = p.second.second;
        if(dist[from] != INF && dist[to] > dist[from] + weight)
            return false;
    }
    

    return true;
}

int main(void) {
    int TC; // 테스트케이스 개수, 1~5.
    int N;  // 지점의 수, 1~500.
    int M;  // 도로의 개수, 1~2500.
    int W;  // 웜홀의 개수, 1~200.
    int S, E, T;    // start, end, cost (0 ~ 10,000)
    int i, j;
    bool isCycle;

    scanf("%d", &TC);

    for(i = 0; i < TC; i++) {
        scanf("%d %d %d", &N, &M, &W);

        for (j = 0; j < N; j++)
            dist[j] = INF;
        dist[0] = 0;

        edges.clear();

        for(j = 0; j < M; j++) {
            scanf("%d %d %d", &S, &E, &T);
            edges.push_back(make_pair(S-1, make_pair(E-1, T)));
            edges.push_back(make_pair(E-1, make_pair(S-1, T)));
        }

        for(j = 0; j < W; j++) {
            scanf("%d %d %d", &S, &E, &T);
            edges.push_back(make_pair(S-1, make_pair(E-1, -T)));
        }

        isCycle = !(bellmanFord(N));
        
        isCycle ? printf("YES") : printf("NO");
    }

    return 0;
}