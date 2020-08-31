#include<stdio.h>
#include<queue>
#include<utility>

#define MAX 50
#define Pii pair<int, int>

using namespace std;

int parents[MAX], roads[MAX][MAX];
queue<Pii> q;
queue<Pii> notUsed;
int totalSize, sizes[MAX];

int find(int a) {
    if(a == parents[a]) return a;
    else return parents[a] = find(parents[a]);
}

void unionWith(int from, int to) {
    parents[find(from)] = find(to);
}

void makeMST() {
    while(!q.empty()) {
        Pii top = q.front();
        int from = top.first;
        int to = top.second;
        q.pop();
        
        if(find(from) != find(to)) {
            unionWith(from, to);
            sizes[from]++;
            sizes[to]++;
            totalSize++;
        }
        else {
            notUsed.push(make_pair(from, to));
        }
    }
}

void connectRestUntil(int M) {
    while(!notUsed.empty()) {
        if(totalSize == M)
            break;
        
        Pii top = notUsed.front();
        int from = top.first;
        int to = top.second;
        notUsed.pop();
        sizes[from]++;
        sizes[to]++;
        totalSize++;
    }
}

bool isSameSet(int N) {
    int i, root = find(0);
    for(i = 1; i < N; i++) {
        if(root != find(i))
            return false;
    }

    return true;
}

int main(void) {
    int N;  // 1 ~ 50 
    int M;  // N-1 ~ 1,000
    char input[MAX];
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

    for(i = 0; i < MAX; i++) parents[i] = i;
    
    for(i = 0; i < N; i++)
        for(j = i+1; j < N; j++)
            if(roads[i][j]) q.push(make_pair(i, j));
    
    makeMST();
    connectRestUntil(M);
    
    if(isSameSet(N) && totalSize == M)
        for(i = 0; i < N; i++)
            printf("%d ", sizes[i]);
    else
        printf("-1");

    printf("\n");
    

    return 0;
}