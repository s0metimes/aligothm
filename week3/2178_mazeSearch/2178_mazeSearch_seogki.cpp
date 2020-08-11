#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
#define pii pair<int, int>
#define MAX 101

int N, M;
bool MAP[MAX][MAX];
bool chk[MAX][MAX];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
queue<pair<pii, int>> qu;

bool possibleMove(int x, int y)
{
    return (x >= 1) && (x <= N) && (y >= 1)  && (y <= M) && (MAP[x][y] == 1) && (chk[x][y] == 0);
}

int bfs()
{
    qu.push({{1, 1}, 1});
    chk[1][1] = 1;
    while (!qu.empty())
    {
        pair<pii, int> now = qu.front();
        qu.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = now.first.first + dx[i];
            int ny = now.first.second + dy[i];
            int cnt = now.second;
            if (nx == N && ny == M)
                return cnt + 1;
            if (possibleMove(nx, ny))
            {
                qu.push({{nx, ny}, cnt + 1});
                chk[nx][ny] = 1;
            }
        }
    }
    return -1;
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            scanf("%1d", &MAP[i][j]);
    printf("%d\n", bfs());
    return 0;
}