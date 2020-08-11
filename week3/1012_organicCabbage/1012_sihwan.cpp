#include<stdio.h>
#include<stack>
#include<utility>

using namespace std;

#define MAX 50

int visited[MAX][MAX], field[MAX][MAX];

stack<pair<int, int> > s;

bool isMovable(int n, int m, int N, int M) {
    if(n < 0 || n >= N || m < 0 || m >= M || visited[n][m] || !field[n][m])
        return false;
    else
        return true;
}

void dfs(int N, int M) {
    int n, m;
    pair<int, int> top;
    while(!s.empty()) {
        top = s.top();
        n = top.first;
        m = top.second;
        visited[n][m] = 1;
        s.pop();
        
        if(isMovable(n-1,m,N,M))
            s.push(make_pair(n-1,m));
        if(isMovable(n,m-1,N,M))
            s.push(make_pair(n,m-1));
        if(isMovable(n+1,m,N,M))
            s.push(make_pair(n+1,m));
        if(isMovable(n,m+1,N,M))
            s.push(make_pair(n,m+1));
    }
}

int main(int argc, char **argv) {
    int T, M, N, K;
    int t, m, n, k, x, y, count;
    scanf("%d", &T);
    
    for(t = 0; t < T; t++) {
        for (n = 0; n < N; n++) {
            for (m = 0; m < M; m++) {
                field[n][m] = 0;
                visited[n][m] = 0;
            }
        }

        scanf("%d %d %d", &M, &N, &K);

        for(k = 0; k < K; k++) {
            scanf("%d %d", &x, &y);
            field[y][x] = 1;
        }

        count = 0;
        for (n = 0; n < N; n++) {
            for (m = 0; m < M; m++) {
                if (!visited[n][m] && field[n][m]) {
                    s.push(make_pair(n, m));
                    dfs(N, M);
                    count++;
                }
            }
        }
        printf("%d\n", count);
    }

    return 0;
}
