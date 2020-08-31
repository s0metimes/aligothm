#include <stdio.h>
#include <queue>
#define MAX 50
#define WEIGHT first
#define NODE second

using namespace std;

int parent[MAX+1];
int result[MAX+1];
typedef pair<int, pair< int, int > > Edge; //가중치, 정점, 정점 
priority_queue<Edge, vector<Edge>, greater<Edge> > edge;
priority_queue<Edge, vector<Edge>, greater<Edge> > trash;

void initialize(int N = MAX) {
    for(int i = 1; i <= N; i++) parent[i] = i;
}

int FIND(int node_a) {
    if(node_a == parent[node_a]) return node_a;
    else return parent[node_a] = FIND(parent[node_a]);
}

void UNION(int node_a, int node_b) {
    int root_a = parent[node_a];
    int root_b = parent[node_b];
    parent[root_a] = root_b;
}

int main(int argc, char const *argv[])
{
    int N, M;
    scanf("%d %d", &N, &M);

    initialize(N);
    for(int i = 0; i < N; i++) {  // 입력 처리 
        getchar();  // 개행 처리 
        for(int j = 0; j < N; j++) {
            char ch = getchar();
            if(j > i && ch == 'Y') edge.push(make_pair(N*i+j,make_pair(i, j)));
        }
    }
        
    int cnt = 0; // 현재 집합에 포함된 도로 갯수 
    
    while(!edge.empty()) {  // MST만들기 
        Edge e = edge.top();
        edge.pop();
        if(FIND(e.NODE.first) != FIND(e.NODE.second)) {        
            UNION(e.NODE.first, e.NODE.second);
            result[e.NODE.first]++;
            result[e.NODE.second]++;
            cnt++;
        } else {
            trash.push(e);  // MST 만들면서 필요없었던 모든 Edge는 trash에 다시 저장 
        }
    }
    // MST 가 만들어 졌다면 cnt = N-1이어야한다. 
    // 연결 그래프인지 체크
    bool isAllNodesConnect = true; // 연결그래프라면 true; 
    if(cnt != N-1) isAllNodesConnect = false;

    // 모든 정점이 연결되어 있다면 M개를 채우기위해 trash에 저장한 Edge를 추가 
    while(!trash.empty()) {
        if(cnt == M)break;
        Edge e = trash.top();
        trash.pop();
        result[e.NODE.first]++;
        result[e.NODE.second]++;
        cnt++;
    }
   
    if(isAllNodesConnect && /*sibalsaeki*/cnt == M) for (int i = 0; i < N; i++) printf("%d ", result[i]); // 각 i 정점과 연결된 도로 갯수를 반환 
    else printf("-1");
    printf("\n");

    return 0;
}

// #include <stdio.h>
// #include <queue>
// #define MAX 50

// using namespace std;

// int parent[MAX+1];
// int result[MAX+1];
// typedef pair< int, int > Pii; //가중치, 정점, 정점 
// queue<Pii, vector<Pii> > edge;
// queue<Pii, vector<Pii> > trash;

// void initialize(int N = MAX) {
//     for(int i = 1; i <= N; i++) parent[i] = i;
// }

// int FIND(int node_a) {
//     if(node_a == parent[node_a]) return node_a;
//     else return parent[node_a] = FIND(parent[node_a]);
// }

// void UNION(int node_a, int node_b) {
//     int root_a = parent[node_a];
//     int root_b = parent[node_b];
//     parent[root_a] = root_b;
// }

// int main(int argc, char const *argv[])
// {
//     int N, M;
//     scanf("%d %d", &N, &M);

//     initialize(N);
//     for(int i = 0; i < N; i++) {  // 입력 처리 
//         getchar();  // 개행 처리 
//         for(int j = 0; j < N; j++) {
//             char ch = getchar();
//             if(j > i && ch == 'Y') edge.push(make_pair(i, j));
//         }
//     }
        
//     int cnt = 0; // 현재 집합에 포함된 도로 갯수 
    
//     while(!edge.empty()) {  // MST만들기 
//         Pii e = edge.front();
//         edge.pop();
//         if(FIND(e.first) != FIND(e.second)) {        
//             UNION(e.first, e.second);
//             result[e.first]++;
//             result[e.second]++;
//             cnt++;
//         } else {
//             trash.push(e);  // MST 만들면서 필요없었던 모든 Edge는 trash에 다시 저장 
//         }
//     }
    
//     // MST 가 만들어 졌다면 cnt = N-1이어야한다. 
//     // 연결 그래프인지 체크
//     bool isAllNodesConnect = true; // 연결그래프라면 true; 
//     if(cnt != N-1) isAllNodesConnect = false;

//     // 모든 정점이 연결되어 있다면 M개를 채우기위해 trash에 저장한 Edge를 추가 
//     while(!trash.empty()) {
//         if(cnt == M)break;
//         Pii e = trash.front();
//         trash.pop();
//         result[e.first]++;
//         result[e.second]++;
//         cnt++;
//     }
   
//     if(!isAllNodesConnect) printf("-1");
//     else for (int i = 0; i < N; i++) printf("%d ", result[i]); // 각 i 정점과 연결된 도로 갯수를 반환 
//     printf("\n");

//     return 0;
// }