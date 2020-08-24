#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define pii pair<int, int>
#define INF 987654321
#define MAX 100001

int N, M, A, B;
long long int W;
vector<pii> MAP[MAX];
priority_queue<pii, vector<pii>, greater<pii>> pq;
long long int dist[MAX];
bool point[MAX];

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N - 1; i++)
        scanf("%d", &point[i]);
    point[N - 1] = 0;
 
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &A, &B, &W);
        if (point[A] == 0 && point[B] == 0)
        {
            MAP[A].push_back({B, W});
            MAP[B].push_back({A, W});
        }
    }
    for (int i = 1; i < N; i++)
        dist[i] = INF;

    pq.push({0, 0});

    while (!pq.empty())
    {
        int now = pq.top().second;
        int nowdist = pq.top().first;
        pq.pop();
        for (pii next : MAP[now])
        {
            if (dist[next.first] >= nowdist + next.second)
            {
                dist[next.first] = nowdist + next.second;
                pq.push({dist[next.first], next.first});
            }
        }
    }
    
    for (int i = 0; i < N; i++)
        printf("%lld ", dist[i]);
    printf("\n");

    if (dist[N - 1] == INF)
        printf("-1\n");
    else
        printf("%lld\n", dist[N - 1]);
}