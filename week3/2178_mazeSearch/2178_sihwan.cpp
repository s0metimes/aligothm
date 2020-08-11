#include<stdio.h>
#include<stack>
#include<utility>

using namespace std;

#define MAXNM 100

int maze[MAXNM][MAXNM], visited[MAXNM][MAXNM];

stack<pair<int, int> > s;
stack<pair<int, int> > tmps;

bool isMovable(int n, int m, int N, int M) {
    if(n < 0 || n >= N || m < 0 || m >= M)
        return false;
    else if (maze[n][m] != 1 || visited[n][m] == 1)
        return false;
    else
        return true;
}

int bfs(int N, int M) {
    int length, direction[2][4], i, n, m;
    pair<int, int> top;

    direction[0][0] = 1; direction[0][1] = -1;
    direction[0][2] = 0; direction[0][3] = 0;
    direction[1][0] = 0; direction[1][1] = 0;
    direction[1][2] = 1; direction[1][3] = -1;

    s.push(make_pair(0, 0));
    length = 1;
    
    while(!visited[N-1][M-1]) {
        while(!s.empty()) {
            tmps.push(s.top());
            s.pop();
        }
        
        while(!tmps.empty()) {
            top = tmps.top();
            for(i = 0; i < 4; i++) {
                n = top.first + direction[0][i];
                m = top.second + direction[1][i]; 
                if (isMovable(n, m, N, M)) {
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

int main(int argc, char **argv) {
    int N, M, n, m, length;

    scanf("%d %d", &N, &M);

    for(n = 0; n < N; n++) {
        for(m = 0; m < M; m++) {
            scanf("%1d", &maze[n][m]);
        }
    }

    length = bfs(N, M);

    printf("%d\n", length);    

    return 0;
}
