#include <iostream>
#include <algorithm>
using namespace std;

#define INF 987654321
#define MAX 101

int V, E;
int MAP[MAX][MAX];
int from, to, W;

void floydWarshall()
{
    for (int i = 1; i <= V; i++)
        for (int j = 1; j <= V; j++)
            for (int k = 1; k <= V; k++)
                if (MAP[j][i] != INF && MAP[i][k] != INF)
                    MAP[j][k] = min(MAP[j][k], MAP[j][i] + MAP[i][k]);
}

int main()
{
    scanf("%d %d", &V, &E);
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            MAP[i][j] = INF;
        }
    }
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &from, &to, &W);
        if (MAP[from][to] > W)
            MAP[from][to] = W;
    }
    floydWarshall();
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            if (i == j || MAP[i][j] == INF)
                printf("0 ");
            else
                printf("%d", MAP[i][j])
        }
        printf("\n");
    }
    return 0;
}
