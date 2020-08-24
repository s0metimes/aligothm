#include <stdio.h>
#include <vector>
#include <queue>
#include <climits>

#define MAXV 20010
#define INF 200000

using namespace std;
vector<int> dist(MAXV+1, INF);
vector<bool> check(MAXV+1, false);
vector<pair<int,int> > edges[MAXV];
priority_queue<pair<int,int> > pq;

//version1
// with check vector
void Dijkstra(int start) {
    //pq 초기화 
    pq.push({0, start});
    dist[start] = 0;
    
    while(!pq.empty()) {
        pair<int, int> now = pq.top();
        pq.pop();
        check[now.second] = true;
        for(auto e : edges[now.second]) {
            if(!check[e.first] && dist[e.first] > -now.first + e.second ) {
                dist[e.first] = -now.first + e.second;
                pq.push({-dist[e.first], e.first});
            }
        }
    }
}
//version2
// without check vector
void Dijkstra2(int start) {
    //pq 초기화 
    pq.push({0, start});
    dist[start] = 0;
    
    while(!pq.empty()) {
        pair<int, int> now = pq.top();
        pq.pop();
        for(auto e : edges[now.second]) {
            if(dist[e.first] == INF || dist[e.first] > -now.first + e.second ) {
                dist[e.first] = -now.first + e.second;
                pq.push({-dist[e.first], e.first});
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int V, E, K;
    int u, v, w;
    scanf("%d %d", &V, &E);
    scanf("%d", &K);
    for(int e = 0; e < E; e++) {
        scanf("%d %d %d", &u, &v, &w);
        edges[u].push_back({v, w});
    }
    Dijkstra(K);

    for(int v = 1; v <= V; v++) {
        if(dist[v] == INF) printf("INF\n");
        else printf("%d\n", dist[v]);
    }
    return 0;
}

// #include <stdio.h>
// #include <vector>
// #include <queue>
// #include <climits>

// #define WEIGHT first
// #define TO second
// #define MAXV 20005
// #define INF INT_MAX

// using namespace std;
// vector<int> dist(MAXV, INF);
// vector<pair<int,int> > edges[MAXV];
// priority_queue<pair<int,int> > pq;

// void Dijkstra(int start) {
//     dist[start] = 0;
//     for(auto e : edges[start]) {
//         if(dist[e.TO] == INF) {
//             pq.push({-e.WEIGHT, -e.TO});
//         }
//     }

//     while(!pq.empty()) {
//         int to, toDist;
//         toDist = -pq.top().WEIGHT;
//         to = -pq.top().TO;
//         pq.pop();
        
//         if(dist[to] != INF) {
//             if(toDist < dist[to]) 
//                 dist[to] = toDist;
//             continue;
//         }

//         dist[to] = toDist;
//         for(auto e : edges[to])
//             pq.push({ -(toDist + e.WEIGHT), -e.TO});
//     }
// }

// int main(int argc, char const *argv[])
// {
//     int V, E, K;
//     int u, v, w;
//     scanf("%d %d", &V, &E);
//     scanf("%d", &K);
//     for(int e = 0; e < E; e++) {
//         scanf("%d %d %d", &u, &v, &w);
//         edges[u].push_back({w, v});
//     }
//     Dijkstra(K);

//     for(int v = 1; v <= V; v++) {
//         if(dist[v] == INF) printf("INF\n");
//         else printf("%d\n", dist[v]);
//     }
//     return 0;
// }

// // 하나의 시작점에서 모든 정점의 최단 경로를 구하는 알고리즘 : Dijkstra
// // 음수 가중치가 존재할 경우 사용할 수 없다.

// // 출발점으로부터 가장 가까운 정점을 구한다. (인접한 것을 의미하는 것인가? ( *확인해볼것* ))
// // 그 정점까지의 최단 거리를 확정한다.
// // 최단거리가 확정된 정점과 가장 가까운 정점을 찾아 그 지점까지 최단거리를 확정한다.
// // 2를 끝날때까지 반복한다.

// #include <iostream>
// #include <vector>
// #include <queue>
// #include <climits>

// #define TO first
// #define WEIGHT second
// #define MAXV 20000
// #define INF INT_MAX
// using namespace std;

// vector<int> dist(MAXV, INF);
// vector<pair<int,int> > edges[MAXV]; // <정점번호, 정점까지의 거리>
// priority_queue<pair<int,int> > pq;  // <정점번호, 정점까지의 거리>

// void printQueue() {
//     vector<pair<int,int> > temp;
//     int cnt = 0;
//     printf("******************************\n");
//     while(!pq.empty()) {
//         int to, toDist; 
//         to = pq.top().TO;  // now는 갈곳
//         toDist = pq.top().WEIGHT;
//         pq.pop();
//         printf("%d | to : %d / weight : %d\n", cnt++, -to, -toDist);
//         temp.push_back({to, toDist});
//     }
//     printf("******************************\n");
//     for(int i = 0; i < cnt; i++) {
//         pq.push(temp[i]);
//     }
// }

// void Dijkstra(int start) {
//     // 초기화 
//     dist[start] = 0; // 자기자신으로 가는 길
//     // start에 연결되어 있는 edge들을 
//     // 전부 pq에 넣는다.
//     for(auto e : edges[start]) { 
//         if(dist[e.first] == INF) {  // 아마 자기자신을 제외하기 위해서?
//             pq.push({-e.TO, -e.WEIGHT});
//         }
//     }
//     // 현재 pq에는 start에서 갈수 있는 모든 edge가 들어가 있다.

//     while(!pq.empty()) {
//         // printQueue();

//         int to, toDist; 
//         to = -pq.top().TO;  // now는 갈곳
//         toDist = -pq.top().WEIGHT;
//         pq.pop();

//         if(dist[to] != INF){
//             if(toDist < dist[to]) {
//                 toDist = dist[to];
//                 for(auto e : edges[to]) {
//                     pq.push({ -(toDist + e.WEIGHT), -e.TO});
//                 }
//             }
//             // start에서 to 까지 거리가 INF라면
//             continue;
//         }
//         dist[to] = toDist; // start에서 to 까지의 거리를 toDist로 초기화
//         // to 에서 갈수 있는 정점들을 다시 pq에 추가
//         for(auto e : edges[to]) { 
//             if(dist[e.TO] == INF) {
//                 pq.push({ -e.TO, -(toDist + e.WEIGHT)});
//             }
//         }
//     }
// }

// int main(int argc, char const *argv[])
// {
//     int V, E, K;
//     int u, v, w;
//     cin >> V >> E;
//     cin >> K;
//     for(int e = 0; e < E; e++) {
//         cin >> u >> v >> w;
//         edges[u].push_back({v, w});
//     }
//     Dijkstra(K);

//     for(int v = 1; v <= V; v++) {
//         if(dist[v] == INF) cout << "INF\n";
//         else cout << dist[v] << "\n";
//     }
//     return 0;
// }

