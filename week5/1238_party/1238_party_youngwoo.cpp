#include <stdio.h>
#include <vector>
#include <queue>
#include <climits>

#define MAXV 1010
#define INF INT_MAX

using namespace std;
int dist[MAXV+1][MAXV+1];
vector<pair<int,int> > edges[MAXV];
priority_queue<pair<int,int> > pq;

void Dijkstra(int start) {
    //pq 초기화 
    pq.push({0, start});
    dist[start][start] = 0;
    
    while(!pq.empty()) {
        pair<int, int> now = pq.top();
        pq.pop();
        for(auto e : edges[now.second]) {
            if(dist[start][e.first] == INF || dist[start][e.first] > -now.first + e.second ) {
                dist[start][e.first] = -now.first + e.second;
                pq.push({-dist[start][e.first], e.first});
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int N, M, X;
    int u, v, w;
    scanf("%d %d %d", &N, &M, &X);

    for(int i = 1; i <= N; i++) 
        for(int j = 1; j <= N; j++) 
            dist[i][j] = INF;

    for(int n = 0; n < M; n++) {
        scanf("%d %d %d", &u, &v, &w);
        edges[u].push_back({v, w});
    }
    
    for(int i = 1; i <= N; i++)
        Dijkstra(i);

    int maxV = 0;
    for(int i = 1; i <= N; i++) {
        int temp = dist[i][X] + dist[X][i]; 
        if (temp > maxV) maxV = temp;
    }

    printf("%d\n", maxV);
    return 0;
}


// #include <stdio.h>
// #include <vector>
// #include <queue>
// #include <climits>

// #define WEIGHT first
// #define TO second
// #define MAXV 1010
// #define INF INT_MAX

// using namespace std;
// int dist[MAXV+1][MAXV+1];
// vector<pair<int,int> > edges[MAXV];
// priority_queue<pair<int,int> > pq;
// bool check[MAXV+1][MAXV+1];


// void Dijkstra(int start) {
//     //pq 초기화 
//     pq.push({0, start});
//     dist[start][start] = 0;
    
//     while(!pq.empty()) {
//         pair<int, int> now = pq.top();
//         pq.pop();
//         for(auto e : edges[now.second]) {
//             if(dist[start][e.first] == INF || dist[start][e.first] > -now.first + e.second ) {
//                 dist[start][e.first] = -now.first + e.second;
//                 pq.push({-dist[start][e.first], e.first});
//             }
//         }
//     }
    
// }

// void backTracking(int start ,int depth, int X, int temp) {
//     if(depth == X && dist[start][X] > temp) {
//         dist[start][X] = temp; 
//         return;
//     }
    
//     for(auto e : edges[depth]) {
//         if(!check[start][e.first] && dist[start][e.first] > temp + e.second) {
//             dist[start][e.first] = temp + e.second;
//             backTracking(start, e.first, X, temp + e.second);
//         }
//     }
// }

// int main(int argc, char const *argv[])
// {
//     int N, M, X;
//     int u, v, w;
//     scanf("%d %d %d", &N, &M, &X);

//     for(int i = 1; i <= N; i++) 
//         for(int j = 1; j <= N; j++) 
//             dist[i][j] = INF;

//     for(int n = 0; n < M; n++) {
//         scanf("%d %d %d", &u, &v, &w);
//         edges[u].push_back({v, w});
//     }
//     int maxV = 0;
//     Dijkstra(X);

//     for(int i = 1; i <= N; i++) {
//         backTracking(i, i, X, 0);
//         int temp = dist[i][X] + dist[X][i]; 
//         if (temp > maxV) maxV = temp;
//     }

//     printf("%d\n", maxV);
//     return 0;
// }