#include <iostream>
#include <vector>
using namespace std;

#define pii pair<int, int>
#define MAX 501
#define INF 987654321
#define st 1

int T, N, M, W;
int a, b, Ti;

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d %d", &N, &M, &W);

        vector<vector<pii>> edge(N + 1);
        vector<int> dis(N + 1, INF);
        dis[st] = 0;

        for (int i = 0; i < M; i++)
        {
            scanf("%d %d %d", &a, &b, &Ti);
            edge[a].push_back({b, Ti});
            edge[b].push_back({a, Ti});
        }

        for (int i = 0; i < W; i++)
        {
            scanf("%d %d %d", &a, &b, &Ti);
            edge[a].push_back({b, (-1) * Ti});
        }

        bool hasCycle = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                int edge_size_ = edge[j].size();

                for (int k = 0; k < edge_size_; k++)
                {
                    int from = j;
                    int to = edge[j][k].first;
                    int W = edge[j][k].second;

                    if (dis[from] + W < dis[to])
                    {
                        dis[to] = dis[from] + W;
                        if (i == N)
                            hasCycle = 1;
                    }
                }
            }
        }

        printf("%s\n", (hasCycle) ? "YES" : "NO");
    }

    return 0;
}
