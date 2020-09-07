#include<stdio.h>
#include<vector>
#include<utility>
#include<queue>

using namespace std;

#define INF 987654321
#define MAX 500
#define Pii pair<int, int>

int isPossibleRoad[MAX][MAX];
int dist[MAX];
vector<Pii> roads[MAX]; // from, to, length
priority_queue<pair<int, Pii> > pq;     // dist, from, to
queue<int> q;
vector<Pii> roadHistory;

void initializeDist(int N) {
    int n = N;
    while(n--) dist[n] = INF;
}

void initializeRoads(int N) {
    for(int i = 0; i < N; i++)
        roads[i].clear();
}

void initializePossibleRoads(int N) {
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            isPossibleRoad[i][j] = 1;
}

void backtracking(int S, int D, int N)
{
    q.push(D);
    while(!q.empty()) {
        int e = q.front();
        q.pop();
        if(e == S) continue;
        
        for(int i = roadHistory.size()-1; i >= 0; i--)
            if(roadHistory[i].second == e) {
                q.push(roadHistory[i].first);
                isPossibleRoad[roadHistory[i].first][roadHistory[i].second] = 0;
            }
    }
    roadHistory.clear();
}

void dijkstra(int S, int D, int N) {
    initializeDist(N);
    pq.push(make_pair(0, make_pair(S, S)));
    
    while(!pq.empty()) {
        int newDist = -pq.top().first;
        int from = pq.top().second.first;
        int to = pq.top().second.second;
        pq.pop();
        
        if(dist[to] < newDist) continue;
        else if(dist[to] == newDist) {
            roadHistory.push_back(make_pair(from, to));
            continue;
        }

        roadHistory.push_back(make_pair(from, to));
        dist[to] = newDist;
        for(auto e: roads[to]) {
            int next = e.first;
            newDist = e.second + dist[to];
            
            if(dist[next] > newDist && isPossibleRoad[to][next])
                pq.push(make_pair(-newDist, make_pair(to, next)));
        }
    }
    backtracking(S, D, N);
}

int main(void) {
    int N;  // 노드의 개수, 1~500
    int M;  // 도로의 개수
    int S, D;   // 시작, 끝
    int U, V, P;    // 출발지점, 도차지점, 도로의 길이
    int i, j;
    int shortestPath;
    
    while(true) {
        scanf("%d %d", &N, &M);
        if(N == 0 && M == 0) break;
        scanf("%d %d", &S, &D);

        initializeRoads(N);
        initializePossibleRoads(N);

        while(M--) {
            scanf("%d %d %d", &U, &V, &P);
            roads[U].push_back(make_pair(V, P));
        }

        dijkstra(S, D, N);
        shortestPath = dist[D];
        for(i = 0; i < N; i++) {
            dijkstra(S, D, N);
            if(shortestPath < dist[D]) break;
        }
        if(dist[D] == INF)
            printf("-1\n");
        else
            printf("%d\n", dist[D]);
    }

    return 0;
}