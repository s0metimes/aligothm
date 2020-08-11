#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 101
#define pii pair<int, int>

int N, M, T, K;
bool MAP[MAX][MAX];
queue<pii> qu;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
bool isRange(int x, int y);

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        memset(MAP, 0, sizeof(MAP));
        scanf("%d %d %d", &M, &N, &K);
        for (int k = 0; k < K; k++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            MAP[x][y] = 1;
        }

        int index = 0;
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (MAP[i][j] == 1)
                {
                    int cnt = 1;
                    qu.push({i, j});
                    MAP[i][j] = 1;
                    while (!qu.empty())
                    {
                        pii now = qu.front();
                        qu.pop();
                        for (int k = 0; k < 4; k++)
                        {
                            int X = now.first + dx[k];
                            int Y = now.second + dy[k];
                            if (isRange(X, Y))
                            {
                                cnt++;
                                qu.push({X, Y});
                                MAP[X][Y] = 0;
                            }
                        }
                    }
                    index++;
                }
            }
        }
        printf("%d\n", index);
    }
}

bool isRange(int x, int y)
{
    return (x >= 0 && x < M && y >= 0 && y < N && MAP[x][y] == 1);
}