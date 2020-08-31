#include<stdio.h>
#include<queue>
#include<utility>

using namespace std;

#define MAXN 50
#define Pii pair<int, int>

queue<Pii> q;
int totalSize, sizes[MAXN], roads[MAXN][MAXN], visited[MAXN][MAXN];

void clearQueue() {
    queue<Pii> empty;
    swap(q, empty);
}

void bfs(int N, int M) {
    int i;
    while(!q.empty()) {
        Pii now = q.front();
        q.pop();
        
        for(i = 0; i < N; i++)
            if(roads[now.second][i] && !visited[now.second][i]) {
                q.push(make_pair(now.second, i));
                totalSize++;
                sizes[now.second]++;
                sizes[i]++;
                visited[now.second][i] = 1;
                visited[i][now.second] = 1;
                if(totalSize == M)
                    break;
            }

        if (totalSize == M)
            break;
    }
}

int main(void) {
    int N;  // 1 ~ 50 
    int M;  // N-1 ~ 1,000
    char input[MAXN];
    int i, j, k;
    
    scanf("%d %d", &N, &M);

    for(i = 0; i < N; i++) {
        scanf("%s", input);
        
        for(j = 0; j < N; j++) {
            if(input[j] == 'Y')
                roads[i][j] = 1;
            else if(input[j] == 'N')
                roads[i][j] = 0;
        }
    }
    
    for(i = 0; i < N; i++) {
        clearQueue();
        totalSize = 0;
        for(j = 0; j < N; j++) sizes[j] = 0;
        for(j = 0; j < N; j++)
            for(k = 0; k < N; k++)
                visited[j][k] = 0;

        q.push(make_pair(-1, 0));
        bfs(N, M);
        
        if(totalSize == M)
            break;
    }

    if(totalSize != M)
        printf("-1");
    else
        for(i = 0; i < N; i++)
            printf("%d ", sizes[i]);
    printf("\n");

    return 0;
}