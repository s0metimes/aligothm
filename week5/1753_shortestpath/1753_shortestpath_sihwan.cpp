#include <stdio.h>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>

#define MAXV 20000
#define MAXE 300000
#define INF 987654321

using namespace std;

vector<pair<int, int>> weights[MAXV];
int dist[MAXV];
priority_queue<pair<int, int>> pq;

void pushAdjs(int k, int path)
{
    //printf(">>>>> pushed \n");
    for (int i = 0; i < weights[k].size(); i++)
    {
        int to = weights[k][i].first;
        int weight = weights[k][i].second;

        if (dist[to] > path + weight)
        {
            dist[to] = path + weight;
            pq.push(make_pair(-dist[to], to));
        }
        //printf("from: %d, to: %d, weight: %d\n", v+1, i+1, weights[v][i]);
    }
}

void dijkstra(int k, int V)
{
    // int i = 1;

    // 집어 넣음
    pushAdjs(k, 0);

    while (!pq.empty())
    {
        //printf("-------step%d-------\n", i++);
        int to = pq.top().second;
        int path = -pq.top().first;
        //printf("from: %d, to: %d, weight: %d\n", from+1, to+1, weight);

        pq.pop();
        pushAdjs(to, path);
        //printf(">>>>>> dist[to]: %d\n\n", dist[to]);
    }
}

int main(void)
{
    int V; // 정점의 개수
    int E; // 간선의 개수
    int K; // 시작점
    int u, v, w, i;

    scanf("%d %d", &V, &E);
    scanf("%d", &K);

    i = V;
    while (i--)
        dist[i] = INF;
    dist[K - 1] = 0;

    for (i = 0; i < E; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        weights[u - 1].push_back(make_pair(v - 1, w));
    }

    dijkstra(K - 1, V);

    for (i = 0; i < V; i++)
    {
        if (dist[i] == INF)
            printf("INF\n");
        else
            printf("%d\n", dist[i]);
    }

    return 0;
}