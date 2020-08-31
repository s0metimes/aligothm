#include <stdio.h>
#include <queue>
#include <vector>
#define MAX 100010 // V(1 ≤ V ≤ 100,000)
#define WEIGHT first
#define NODE second

using namespace std;

typedef pair<int, pair< int, int > > Edge;
priority_queue<Edge, vector<Edge>, greater<Edge> > edge;
int parent[MAX]; // true이면 포함된것 

void initialize(int v = MAX) {
    for(int i = 1; i <= v; i++) parent[i] = i;
}

int FIND(int node_a) {
    if(node_a == parent[node_a]) return node_a;
    else return parent[node_a] = FIND(parent[node_a]);
}

void UNION(int node_a, int node_b) {
    int root_a = parent[node_a];
    int root_b = parent[node_b];
    parent[root_b] = root_a;
}

int main(int argc, char const *argv[])
{
    int V, E;
    scanf("%d %d", &V, &E);

    initialize(V);

    while(E--) {
        int A, B, C; // A 정점, B 정점, C 가중치 (|C| <= 1,000,000)
        scanf("%d %d %d", &A, &B, &C);
        edge.push(make_pair(C, make_pair(A, B)));
    }
    vector< int > weights;
    while(!edge.empty()) {
        Edge e = edge.top();
        printf("e : A :%d B : %d C : %d\n", e.NODE.first, e.NODE.second, e.WEIGHT);
        edge.pop();
        if(FIND(e.NODE.first) != FIND(e.NODE.second)) {
            printf("UNION e : A :%d B : %d C : %d\n", e.NODE.first, e.NODE.second, e.WEIGHT);
            UNION(e.NODE.first, e.NODE.second);
            weights.push_back(e.WEIGHT);
        }
    }
    int ans = 0;
    for(int i = 0; i < V-2; i++) 
        ans += weights[i];
    
    printf("%d\n", ans);
    return 0;
}