#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

#define INF 987654321
#define MAX 1000
#define MAXK 100
#define Pii pair<int, int>

vector<Pii> roads[MAX];
int dist[MAX];
int visited[MAX];
priority_queue<Pii> pq; // dist, node

void initializeDist(int n) {
    for(int j = 0; j < n; j++) dist[j] = INF;
    for(int i = 0; i < n; i++) visited[i] = 0;
}

void dijkstra(int k, int n) {
    int i = 0;
    initializeDist(n);
    pq.push(make_pair(0, 0));
    while(!pq.empty()) {
        int newDist = -pq.top().first;
        int from = pq.top().second;
        pq.pop();

        if(visited[from] >= k) continue;
        dist[from] = newDist;
        visited[from]++;

        for(auto r: roads[from]) {
            int to = r.first;
            newDist = r.second + dist[from];
            if(visited[to] < k)
                pq.push(make_pair(-newDist, to));
        }
    }
}

int main(void) {
    int n;  // 도시 개수, 1~1000
    int m;  // 도로 수, 0~2,000,000
    int k;  
    int a, b, c;
    int i;

    scanf("%d %d %d", &n, &m, &k);

    while(m--) {
        scanf("%d %d %d", &a, &b, &c);
        roads[a-1].push_back(make_pair(b-1, c));
    }

    dijkstra(k, n);
    for(i = 0; i < n; i++)
        if(visited[i] < k)
            printf("-1\n");
        else
            printf("%d\n", dist[i]);


    return 0;
}