#include <stdio.h>
#include <queue>
#include <algorithm>

#define MAX 1000000
#define WEIGHT first 
#define NODE second

using namespace std;

// parent[0] 를 와우도로 설정할 것
// 강의동은 parent[1] ~ parent[MAX]까지로 설정 
int parent[MAX+1];  
typedef pair< int, pair< int, int> > Edge;
priority_queue< Edge, vector<Edge>, greater<Edge> > edge;

void initialize(int N = MAX) {
    parent[0] = 0;    // 와우도는 0번째 node로 설정한다. 
    // 각 강의동은 루트가 각자의 왼쪽으로 설정한다. 
    // T번째 강의동은 parent[T] = T-1을 root로 갖는다.
    for(int t = 1; t <= N; t++) {   
        if(t == 1) parent[t] = N;
        else parent[t] = t-1;
    }
}

int FIND(int node) {
    if(node == parent[node]) return node;
    else return parent[node] = FIND(parent[node]);
}

void UNION(int node_a, int node_b) {
    // FIND() 가 아닌 parent() 로 접근해도 무방하다. 
    // 메인에서 FIND를 이미 했기때문에 parent가 갱신되어있다. 
    int root_a = FIND(node_a);
    int root_b = FIND(node_b);
    parent[root_a] = root_b;
}

void makeMST(long long int* minimumRequire) {
    while(!edge.empty()) {
        Edge e = edge.top();
        edge.pop();
        if(FIND(e.NODE.first) != FIND(e.NODE.second)) {
            UNION(e.NODE.first, e.NODE.second);
            // 우선, 가지고 있는 돌의 갯수와 상관없이
            // 필요한 돌의 갯수를 반환하도록 minimumRequire 값을 수정해준다.
            // makeMST함수가 끝나고 난후, 필요한 돌의 갯수와 보유하고 있는 돌의 갯수를 비교하면 된다.
            *minimumRequire += e.WEIGHT;
        }
    }
}

int main(int argc, char const *argv[])
{
    // 강의동의 시작은 1번째, 끝은 N번째
    // N : 강의동 갯수 (3 ≤ N ≤ 1,000,000)
    // M : 공사구간의 수 (0 ≤ M ≤ N)
    // K : 건덕이가 가진 돌의 수 (0 ≤ K ≤ 5,000,000,000) : long long int 사용 
    int N, M;
    long long int K, minimumRequire; 

    scanf("%d %d %lld", &N, &M, &K);

    // 원형이므로 각 강의동의 루트를 자신의 왼쪽이라고 생각하자.
    // 추후, 공사중인 도로를 입력받으면서 parent를 수정할 계획
    initialize(N);

    // St : 와우도부터 t번째 강의동까지 필요한 돌의 갯수 
    // 따라서 0번과 T번사이의 도로가 된다. Edge { St , { 0 , T } }
    // 1 ≤ t ≤ N인 모든 정수 T에 대해 1 ≤ St ≤ 1,000,000
    int St;
    for(int t = 1; t <= N; t++) {
        scanf("%d", &St);
        edge.push(make_pair( St, make_pair(0, t) ));
    }

    // 1 ≤ i, j ≤ N
    // i, j 는 공사중이여서 끊어진 도로에 연결된 강의동 
    // i, j 는 이웃한 강의동이다.
    // i, j 의 대소관계는 주어진 조건이 없으므로, 고려해줘야한다. 
    for(int cut = 0; cut < M; cut++) {
        int i, j, minV, maxV;
        scanf("%d %d", &i, &j);
        // i, j 중 큰 값의 루트를 왼쪽에서 자기 자신으로 변경한다.
        maxV = max(i, j);
        // 일반적으로 왼쪽 강의동이 본 강의동보다 값이 1 작다.
        // 하지만, 1번과 N번 강의동사이의 도로같은 경우는 예외처리가 필요하다. 
        if(maxV == N && min(i, j) == 1) parent[1] = 1;
        else parent[maxV] = maxV;    
    }
    
    // 위의 반복문이 끝난 후에는 각 도로가 공사중으로 끊어짐을 반영한다.
    // 각 강의동의 루트가 변경되었으므로, 여러개의 집합으로 나뉘어져있다.
    // 기본 MST 문제들은 모든 node가 각자의 인덱스 값을 갖도록 한다. 즉, 모든 node가 각자의 집합이다.
    // 이렇게 한개의 node부터 모든 node를 포함하는 집합을 만들기 위해 makeMST()과정을 거치지만,
    // 이번 문제는 어느정도 집합을 구성시켜놓은 후, 나뉘어진 집합들을 하나의 집합으로 만드는 문제이다.
    if(M != 0) makeMST(&minimumRequire);

    // N0 가 나오는경우는 , 애초에 돌의 갯수와 무관하게 MST가 안만들어지거나, 
    // 또는 가지고 있는 돌보다 필요한 돌이 더 많은 경우이다.
    // 그런데, 돌은 충분하나 MST가 안만들어지는 경우가 있을까?
    // 와우도와 모든 강의동이랑 연결가능한 도로가 있기 때문에 MST가 안만들어지는 경우는 없다. 
    // printf("minimum : %lld\n", minimumRequire);
    if(K >= minimumRequire) printf("YES\n");
    else printf("NO\n");

    return 0;
}