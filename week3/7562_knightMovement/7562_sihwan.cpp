#include <stdio.h>
#include <stack>
#include <utility>

using namespace std;

#define MAXL 300

int visited[MAXL][MAXL];

stack<pair<int, int> > s;
stack<pair<int, int> > tmps;

bool isMovable(int n, int m, int l)
{
    if (n < 0 || n >= l || m < 0 || m >= l)
        return false;
    else if (visited[n][m] == 1)
        return false;
    else
        return true;
}

int bfs(pair<int, int> start, pair<int, int> end, int l)
{
    int length, direction[2][8], i, n, m;
    pair<int, int> top;

    direction[0][0] = 1; direction[1][0] = 2;
    direction[0][1] = 2; direction[1][1] = 1;
    direction[0][2] = -1; direction[1][2] = 2;
    direction[0][3] = 2; direction[1][3] = -1;
    direction[0][4] = 1; direction[1][4] = -2;
    direction[0][5] = -2; direction[1][5] = 1;
    direction[0][6] = -1; direction[1][6] = -2;
    direction[0][7] = -2; direction[1][7] = -1;

    s.push(start);
    length = 0;
    
    if(start == end)
        return length;
    while (!visited[end.first][end.second])
    {
        while (!s.empty())
        {
            tmps.push(s.top());
            s.pop();
        }

        while (!tmps.empty())
        {
            top = tmps.top();
            for (i = 0; i < 8; i++)
            {
                n = top.first + direction[0][i];
                m = top.second + direction[1][i];
                if (isMovable(n, m, l))
                {
                    visited[n][m] = 1;
                    s.push(make_pair(n, m));
                }
            }

            tmps.pop();
        }

        length++;
    }

    return length;
}

int main(int argc, char **argv)
{
    int t, T, l, n, m, length;

    scanf("%d", &T);

    for(t = 0; t < T; t++) {
        pair<int, int> start, end;

        scanf("%d", &l);

        for(n = 0; n < l; n++) {
            for(m = 0; m < l; m++) {
                visited[n][m] = 0;
            }
        }

        while(!s.empty()) s.pop();
        while(!tmps.empty()) tmps.pop();
        
        scanf("%d %d", &n, &m);
        start = make_pair(n, m);
        scanf("%d %d", &n, &m);
        end = make_pair(n, m);

        length = bfs(start, end, l);

        printf("%d\n", length);
    }

    return 0;
}
