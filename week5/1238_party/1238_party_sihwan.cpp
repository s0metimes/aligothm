#include <stdio.h>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>

#define MAXN 1000
#define MAXM 10000
#define INF 987654321

using namespace std;

vector<pair<int, int> > weights[MAXN];
priority_queue<pair<int, int> > pq;
int dist[MAXN];
int totalDist[MAXN];

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

void dijkstra(int k)
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
    int N; // 마을의 개수
    int M; // 도로의 개수
    int X; // 파티 장소
    int s, e, t, i, j, max;

    scanf("%d %d %d", &N, &M, &X);

    for (i = 0; i < M; i++)
    {
        scanf("%d %d %d", &s, &e, &t);
        weights[s-1].push_back(make_pair(e-1, t));
    }

    for(i = 0; i < N; i++) {
        // X 까지 가는 최단 거리
        // initialize
        j = N; while (j--) dist[j] = INF;
        dist[i] = 0;
        dijkstra(i);
        totalDist[i] += dist[X-1];
        // X 에서 돌아오는 최단 거리
        // initialize
        j = N; while (j--) dist[j] = INF;
        dist[X-1] = 0;
        dijkstra(X-1);
        totalDist[i] += dist[i];
    }

    max = 0;
    for(i = 0; i < N; i++)
        if(max < totalDist[i]) max = totalDist[i];

    printf("%d\n", max);   

    return 0;
}