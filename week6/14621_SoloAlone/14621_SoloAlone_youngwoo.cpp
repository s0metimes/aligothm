#include <stdio.h>
#include <queue>
#include <vector>
#define MAX 1010 // V(1 ≤ V ≤ 1,000)
#define WEIGHT first
#define NODE second

using namespace std;

typedef pair<int, pair< int, int > > Edge;
priority_queue<Edge, vector<Edge>, greater<Edge> > edge;
int parent[MAX]; // true이면 포함된것 
bool isManUni[MAX];
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

    char ch;
    for(int i = 1; i <= V; i++) {
        getchar();
        ch = getchar();
        if(ch == 'M') isManUni[i] = true;
        else  isManUni[i] = false;
    }

    while(E--) {
        int A, B, C; // A 정점, B 정점, C 가중치 (|C| <= 1,000,000)
        scanf("%d %d %d", &A, &B, &C);
        if(isManUni[A]^isManUni[B]) 
            edge.push(make_pair(C, make_pair(A, B)));
    }

    vector< int > weights;
    int ans = 0;
    while(!edge.empty()) {
        Edge e = edge.top();
        edge.pop();
        if(FIND(e.NODE.first) != FIND(e.NODE.second)) {
            UNION(e.NODE.first, e.NODE.second);
            ans += e.WEIGHT;

        }
    }
    int root = FIND(1);
    for(int i = 2; i <= V; i++) {
        if(FIND(i) != root) {
            ans = -1;
            break;
        }
    }

    printf("%d\n", ans);
    return 0;
}