#include <stdio.h>
#include <stack> 
#include<utility>
#include<algorithm>

using namespace std;

#define MAX 100

int visited[MAX][MAX], paper[MAX][MAX], territorySizes[MAX], size;
stack<pair<int, int> > s;

bool isMovable(int m, int n, int M, int N) {
    if (n < 0 || n >= N || m < 0 || m >= M)
        return false;
    else if (paper[m][n] == 1 || visited[m][n] == 1)
        return false;
    else
        return true;
}

void printArr(int arr[MAX][MAX], int M, int N) {
    for(int m = 0; m < M; m++) {
        for(int n = 0; n < N; n++) {
            printf("%d ", arr[m][n]);
        }
        printf("\n");
    }
}


// Searching 방식 자체를 잘못짠거같은데..??
int dfs(int M, int N)
{
    pair<int, int> top;
    int count = 1, m, n;
    while (!s.empty())
    {
        top = s.top();
        m = top.first;
        n = top.second;
        if(visited[m][n])
            count--;
        visited[m][n] = 1;
        s.pop();

        if(isMovable(m-1, n, M, N)) {
            s.push(make_pair(m-1,n));
            count++;
        }
        if(isMovable(m, n-1, M, N)) {
            s.push(make_pair(m,n-1));
            count++;
        }
        if(isMovable(m+1, n, M, N)) {
            s.push(make_pair(m+1,n));
            count++;
        }
        if(isMovable(m, n+1, M, N)) {
            s.push(make_pair(m,n+1));
            count++;
        }
    }

    return count;
}

int main(int argc, char **argv)
{
    // inputs
    int M, N, K, x1, y1, x2, y2;
    // usage
    int m, n, k, i;

    scanf("%d %d %d", &M, &N, &K);

    for (k = 0; k < K; k++)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
        for(m = y1; m < y2; m++) {
            for (n = x1; n < x2; n++) {
                paper[m][n] = 1;
            }
        }
    }

    size = 0;
    for(m = 0; m < M; m++) {
        for(n = 0; n < N; n++) {
            if(!visited[m][n] && !paper[m][n]) {
                s.push(make_pair(m,n));
                territorySizes[size++] = dfs(M, N);
            }
        }
    }

    sort(territorySizes, territorySizes + size);
    printf("%d\n", size);
    for(i = 0; i < size; i++) {
        printf("%d ", territorySizes[i]);
    }
    printf("\n");

    return 0;
}
