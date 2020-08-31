#include<stdio.h>
#include<utility>
#include<queue>

using namespace std;

#define MAX 1000000
#define Pii pair<int, int>
#define Edge pair<int, Pii>

int parents[MAX+1];
int stones[MAX];
int roads[MAX];
long long totalStones;
priority_queue<Edge> pq;

int find(int a) {
    if(a == parents[a]) return a;
    else return parents[a] = find(parents[a]);
}

void unionWith(int a, int b) {
    parents[find(a)] = find(b);
}

void makeMST() {
    while(!pq.empty()) {
        Edge e = pq.top();
        int from = e.second.first;
        int to = e.second.second;
        int stones = -e.first;
        pq.pop();

        if(find(from) != find(to)) {
            unionWith(from, to);
            totalStones += stones;
        }
    }
}

int main(void) {
    int N;  // 3 ~ 1,000,000
    int M;  // 0 ~ N
    int i, j;   // 1 ~ N
    long long K;    // 0 ~ 5,000,000,000
    int n, m;

    scanf("%d %d %lld", &N, &M, &K);

    for(n = 0; n < N; n++) {
        roads[n] = 1;
        parents[n] = n;
        scanf("%d", &stones[n]);
    }
    parents[N] = N;
    

    for(m = 0; m < M; m++) {
        scanf("%d %d", &i, &j);
        if(i == 1 && j == N) roads[j-1] = 0;
        else if(i == N && j == 1) roads[i-1] = 0;
        else if(i < j) roads[i-1] = 0;
        else if(j > i) roads[j-1] = 0;
    }

    for(n = 0; n < N; n++) parents[n] = n;
    parents[N] = N;
    
    for(n = 0; n < N; n++) {
        if(roads[n]) {
            if(n == N-1)
                pq.push(make_pair(0, make_pair(n, 0)));
            else
                pq.push(make_pair(0, make_pair(n, n+1)));
        }
    }

    for(n = 0; n < N; n++)
        pq.push(make_pair(-stones[n], make_pair(n, N)));
    
    makeMST();
    

    printf("%s\n", totalStones <= K || M == 0 ? "YES" : "NO");


    return 0;
}