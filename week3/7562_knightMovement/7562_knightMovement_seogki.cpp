#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define pii pair<int, int>

bool visited[301][301];
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

bool inRange(int x, int y, int size)
{
    return ((x >= 0) && (y >= 0) && (x <= size) && (y <= size));
}

int main()
{
    int T, L;
    int curX, curY, nxtX, nxtY;
    scanf("%d", &T);
    while (T--)
    {
        memset(visited, 0, sizeof(visited));
        queue<pair<pii, int>> qu;
        scanf("%d", &L);
        scanf("%d %d %d %d", &curX, &curY, &nxtX, &nxtY);
        if (curX == nxtX && curY == nxtY)
        {
            printf("0\n");
            continue;
        }
        qu.push({{curX, curY}, 0});
        visited[curX][curY] = 1;
        while (!qu.empty())
        {
            pair<pii, int> now = qu.front();
            qu.pop();
            for (int k = 0; k < 8; k++)
            {
                int x = now.first.first + dx[k];
                int y = now.first.second + dy[k];
                if (visited[x][y] == 0 && inRange(x, y, L-1))
                {
                    qu.push({{x, y}, now.second + 1});
                    visited[x][y] = 1;
                }
                if (x == nxtX && y == nxtY)
                {
                    printf("%d\n", now.second + 1);
                    while (!qu.empty())
                        qu.pop();
                    break;
                }
            }
        }
    }
}