#include <stdio.h>
#include <vector>
using namespace std;

int cnt, N;

// 1 : left cross 2 : right cross 4: down
void bt(int depth, vector<int> visit)
{
    printf("depth is %d\n", depth);
    for (auto i : visit)
        printf("%d ", i);
    printf("\n");

    vector<int> next(N);
    if (depth == N-1)
    {
        for (int i = 0; i < N; i++)
            if (visit[i] == 0)
                cnt++;
        return;
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            next[i] = 0;           
            switch (visit[i])
            {
            case 1: // left
                if(i-1 >= 0)
                    next[i-1] += 1;
                break;
            case 2: // right
                if(i+1 <N)
                    next[i+1] += 2;
                break;
            case 3: // left right
                if(i-1 >= 0)
                    next[i-1] += 1;
                if(i+1 <N)
                    next[i+1] += 2;
                break;
            case 4: // down
                next[i] += 4;
                break;
            case 5: // left down
                if(i-1 >= 0)
                    next[i-1] += 1;
                next[i] += 4;
                break;
            case 6: // right down
                if(i+1 <N)
                    next[i+1] += 2;
                next[i] += 4;
                break;
            case 7: // all
                if(i-1 >= 0)
                    next[i-1] += 1;
                if(i+1 <N)
                    next[i+1] += 2;
                next[i] += 4;
                break;
            }
        }
        for (int i = 0; i < N; i++)
        {
            if (visit[i] == 0)
            {
                vector<int> tmp(N);
                tmp = next;
                if ((i - 1) >= 0)
                    tmp[i - 1] += 1;
                if ((i + 1) < N)
                    tmp[i + 1] += 2;
                tmp[i] += 4;
                bt(depth + 1, tmp);
            }
        }
    }
}

int main()
{
    scanf("%d", &N);
    vector<int> v(N);
    bt(0, v);
    printf("%d", cnt);
    return 0;
}

/*
#include <stdio.h>
#define MAX 15

int cnt, N;
int board[MAX];

void bt(int depth)
{
    if(depth == N)
        cnt++;
    for()
}

int main()
{
    scanf("%d", &N);
    bt(0);
    printf("%d", cnt);
    return 0;
}
*/

/*
#include <stdio.h>
#include <vector>
using namespace std;

int cnt, N;

// 1 : left cross 2 : right cross 4: down
void bt(int depth, vector<int> visit)
{
    printf("depth is %d\n", depth);
    for (auto i : visit)
        printf("%d ", i);
    printf("\n");

    vector<int> next(N);
    if (depth == N - 1)
    {
        for (int i = 0; i < N; i++)
            if (visit[i] == 0)
                cnt++;
        return;
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            switch (visit[i])
            {
            case 1: // left
                if(i-1 > 0)
                    next[i-1] += 1;
                break;
            case 2: // right
                if(i+1 <N)
                    next[i+1] +=2;
                break;
            case 3: // left right
                if(i-1 > 0)
                    next[i-1] += 1;
                if(i+1 <N)
                    next[i+1] += 2;
                break;
            case 4: // down
                next[i] += 4;
                break;
            case 5: // left down
                if(i-1 > 0)
                    next[i-1] += 1;
                next[i] += 4;
                break;
            case 6: // right down
                if(i+1 <N)
                    next[i+1] += 2;
                next[i] += 4;
                break;
            case 7: // all
                if(i-1 > 0)
                    next[i-1] += 1;
                if(i+1 <N)
                    next[i+1] += 2;
                next[i] += 4;
                break;
            }
        }
        for (int i = 0; i < N; i++)
        {
            if (visit[i] == 0)
            {
                vector<int> tmp(N);
                tmp = next;
                if (i - 1>0)
                    tmp[i - 1] += 1;
                if (i + 1<N)
                    tmp[i + 1] = 2;
                tmp[i] = 4;
                bt(depth + 1, tmp);
            }
        }
    }
}

int main()
{
    scanf("%d", &N);
    vector<int> v(N);
    bt(0, v);
    printf("%d", cnt);
    return 0;
}
*/