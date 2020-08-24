#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 987654321
#define MAX 1001
#define pii pair<int, int>

int N, M, X;
int A, B, W, ans;

vector<pii> MAP[MAX];

vector<int> dijkstra(int st, int v)
{
    vector<int> dist(v, INF);
    dist[st] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, st});
    while (!pq.empty())
    {
        int w = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if (dist[cur] < w)
            continue;
        for (int i = 0; i < MAP[cur].size(); i++)
        {
            int next = MAP[cur][i].first;
            int nextD = w + MAP[cur][i].second;
            if (dist[next] > nextD)
            {
                dist[next] = nextD;
                pq.push({nextD, next});
            }
        }
    }
    return dist;
}

int main()
{
    scanf("%d %d %d", &N, &M, &X);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &A, &B, &W);
        MAP[A].push_back({B, W});
    }

    for (int i = 1; i <= N; i++)
    {
        vector<int> toX = dijkstra(i, N + 1);
        vector<int> toHome = dijkstra(X, N + 1);

        if (toX[X] + toHome[i] >= INF || toX[X] + toHome[i] < 0)
            continue;
        ans = max(ans, toX[X] + toHome[i]);
    }
    printf("%d\n", ans);
}