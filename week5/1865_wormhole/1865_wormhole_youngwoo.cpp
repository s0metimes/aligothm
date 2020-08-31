// #include <stdio.h>
// #include <vector>
// #include <algorithm>

// // 각 변수 범위를 나타냄
// #define MAX_TC 5
// #define MAX_N 500
// #define MAX_M 2500
// #define MAX_W 200
// #define MAX_T 10000

// #define from 0
// #define to 1
// #define weight 2
// #define INF 987654321

// using namespace std;

// vector< vector< int > > edges;
// vector< int > dist(MAX_N, INF); 

// int temp = -1;
// char str[4] = "INF";

// int main(int argc, char const *argv[])
// {
//     int TC; // test case
//     scanf("%d", &TC);
//     while(TC--) {
//         int N, M, W;    // 지점 수, 도로의 개수, 웜홀의 개수
//         scanf("%d %d %d", &N, &M, &W);

//         printf("\nN:%d M:%d W:%d\n", N, M, W);
//         for(int i = 0; i < M; i++) {    // 도로 입력
//             int S, E, T;    // 연결된 정점 둘, 이동 소요시간 
//             scanf("%d %d %d", &S, &E, &T);
//             printf("도로 S:%d E:%d T:%d\n", S, E, T);
//             // 도로는 양방향인데, 두개를 넣어야하는것인가
//             // 아니면 하나만 넣고 연결된 정점 두개를 체크한다. 
//             // 일단 두개를 넣고 체크해보자 
//             edges.push_back({S,E,T});
//             edges.push_back({E,S,T});
//         }

//         for(int i = 0; i < W; i++) {    // 웜홀 입력 
//             int S, E, T;    // 시작 지점, 도착 지점, 이동 소요시간 
//             scanf("%d %d %d", &S, &E, &T);
//             printf("웜홀 S:%d E:%d T:%d\n", S, E, -T);
//             // 웜홀 또한 도로라고 생각하되, 입력받은 T에 -를 붙여서 넣어준다. 
//             edges.push_back({S,E,-T});
//         }
        
//         sort(edges.begin(), edges.end());

//         for(auto e : edges) 
//             printf("from: %d to: %d weight: %d\n", e[from], e[to], e[weight]);

//         // dist 배열 초기화 
//         for(auto d : dist) 
//             d = INF;
//         dist[1] = 0;

//         for(int i = 1; i <= N-1; i++) {
//             printf("\n%d 갱신 시도\n", i);
//             for(auto e : edges) {
//                 printf("e.from : %d e.to : %d e.weight : %d\n", e[from], e[to], e[weight]);
//                 if(dist[e[to]] > dist[e[from]] + e[weight]) {
//                     // /* //갱신되는 경우 출력하는 부분 
//                     if(dist[e[to]] == INF) printf("dist[%d] 가 %s 에서 %d로 갱신 되었습니다.\n", e[to], str, dist[e[from]] + e[weight]);
//                     else printf("dist[%d] 가 %d 에서 %d로 갱신 되었습니다.\n", e[to], dist[e[to]], dist[e[from]] + e[weight]);
//                     //*/
//                     dist[e[to]] = dist[e[from]] + e[weight];
//                 }
//                 // dist 배열 출력하는 부분 
//                 printf("갱신후 인덱스 |");
//                 for(int j = 1; j <= N; j++) {
//                     printf("%5d", j);
//                 }
//                 printf("\n");
//                 printf("갱신후 누적값 |");
//                 for(int j = 1; j <= N; j++) {
//                     if(dist[j] == INF) printf("%5s", str);
//                     else printf("%5d", dist[j]);
//                 }
//                 printf("\n");
//                 //*/
//             }
//         }

//         // printf("\n음수 사이클이 있는지 한번더 갱신시도해보면서 체크\n");
//         bool hasMinusCycle = false; // 한번 더 전체적으로 갱신시도했을때 갱신 되는 값이 있다면, 음수 사이클이 존재한다는 의미 
//         for(auto e : edges) {
//             // printf("e.from : %d e.to : %d e.weight : %d\n", e[from], e[to], e[weight]);
//             if(dist[e[to]] > dist[e[from]] + e[weight]) {
//                 ///* //갱신되는 경우 출력하는 부분 
//                 if(dist[e[to]] == INF) printf("dist[%d] 가 %s 에서 %d로 갱신 되었습니다.\n", e[to], str, dist[e[from]] + e[weight]);
//                 else printf("dist[%d] 가 %d 에서 %d로 갱신 되었습니다.\n", e[to], dist[e[to]], dist[e[from]] + e[weight]);
//                 //*/
//                 dist[e[to]] = dist[e[from]] + e[weight];
//                 hasMinusCycle = true;   // 갱신됐으므로, hasMinusCycle 을 true로 변경 
//                 printf("갱신됐습니다!! 음수사이클 존재!\n");
//                 break;  //  이미 갱신된 것을 확인했으므로, 더이상 갱신시도할 필요 없음 
//             }
//             ///* dist 배열 출력하는 부분 
//             printf("갱신후 인덱스 |");
//             for(int j = 1; j <= N; j++) {
//                 printf("%5d", j);
//             }
//             printf("\n");
//             printf("갱신후 누적값 |");
//             for(int j = 1; j <= N; j++) {
//                 if(dist[j] == INF) printf("%5s", str);
//                 else printf("%5d", dist[j]);
//             }
//             printf("\n");
//             //*/
//         }

//         if(hasMinusCycle) printf("YES\n");
//         else printf("NO\n");

//         // edges 배열 초기화 
//         edges.clear();
//     }
//     return 0;
// }

#include <stdio.h>
#include <vector>
#include <algorithm>

#define MAX_N 500

#define FROM 0
#define TO 1
#define WEIGHT 2
#define INF 987654321

using namespace std;

vector< pair< int, pair< int, int> > > edges;
vector< int > dist(MAX_N, INF); 

bool Bellman_Ford(int N) {
    for(int i = 0; i < N-1; i++) {
        
        for(auto e : edges) {
            int to = e.second.first;
            int from = e.first;
            int weight = e.second.second;

            if(dist[to] > dist[from] + weight) 
                dist[to] = dist[from] + weight;
        }
    }
    
    for(auto e : edges) {
        int to = e.second.first;
        int from = e.first;
        int weight = e.second.second;

        if(dist[to] > dist[from] + weight)
            return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int TC;
    scanf("%d", &TC);
    while(TC--) {
        int N, M, W;
        scanf("%d %d %d", &N, &M, &W);

        edges.clear();
        
        for(int i = 0; i < M; i++) {
            int S, E, T;
            scanf("%d %d %d", &S, &E, &T);

            edges.push_back({S,{E,T}});
            edges.push_back({E,{S,T}});
        }

        for(int i = 0; i < W; i++) {
            int S, E, T;
            scanf("%d %d %d", &S, &E, &T);
            edges.push_back({S,{E,-T}});
        }

        sort(edges.begin(), edges.end());

        dist[1] = 0;
        for(int i = 2; i <= N; i++) dist[i] = INF;

        bool hasMinusCycle = Bellman_Ford(N);

        if(hasMinusCycle) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}