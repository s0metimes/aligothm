#include <stdio.h>

#define MAX 200
#define MAXM 1000
using namespace std;

int parent[MAX];
int course[MAXM];
int rootCourse[MAXM];

void initialize(int n);
int FIND(int node);
bool isDisjoint(int node_a, int node_b);
void UNION(int node_a, int node_b);
void printParent(int N);

int main(int argc, char const *argv[])
{
    int N, M;   // (n≤200), (m≤1000)
    scanf("%d %d", &N, &M);

    initialize(N);

    int hasBridge; // 1일경우만 연결 
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            scanf("%d", &hasBridge);
            if(hasBridge == 1) UNION(i, j);
        }
    }

    for(int i = 0; i < M; i++)
        scanf("%d", &course[i]);
    
    bool isPossible = true;
    int flag = course[0];
    for(int i = 1; i < M; i++) {
        if(isDisjoint(flag, course[i])) {
            isPossible = false;
            break;
        }
    }
    
    if(isPossible) printf("YES\n");
    else printf("NO\n");
    return 0;
}


void initialize(int n = MAX) {
    for(int i = 0; i <= n; i++) parent[i] = i;
}

int FIND(int node) {
    if(node == parent[node]) return node;
    else return parent[node] = FIND(parent[node]);
}

bool isDisjoint(int node_a, int node_b) {
    return !(FIND(node_a) == FIND(node_b)); 
}

void UNION(int node_a, int node_b) {
    if(isDisjoint(node_a, node_b)) 
        parent[parent[node_a]] = parent[node_b];
}

void printParent(int N) {
    printf("\nparent | ");
    for(int i = 1; i <= N; i++) 
        printf("%d ", parent[i]);
    printf("\n");
}

