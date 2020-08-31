#include <stdio.h>
#include <queue>
#include <algorithm>
#define MAX 100000

using namespace std;
typedef pair< int, int > Pii;
priority_queue< Pii > edges;
int parent[MAX];
int numOfGivenEdge = 0;
int maxV = 0;

int FIND(int node) {
    if(node == parent[node]) return node;
    else return parent[node] = FIND(parent[node]);
}

void UNION(int a, int b) {
    int root_a = FIND(a);
    int root_b = FIND(b);
    parent[root_b] = root_a;
}

void init(int N = MAX) {
    for(int i = 1; i <= N; i++) parent[i] = i;
    numOfGivenEdge = 0;
    maxV = 0;
}

bool makeMST() {
    int needs = 0;
    while(!edges.empty()) {
        Pii e =  edges.top(); edges.pop();
        if(FIND(e.first) != FIND(e.second)) {
            UNION(e.first, e.second);
            needs++;
        }
    }
    if(needs == numOfGivenEdge) return true;
    else return false;
}

void printResult(bool isTree, int k) {
    printf("Case %d is ", k);
    if(!isTree) printf("not ");
    printf("a tree.\n");
}

int main(int argc, char const *argv[])
{
    int u = 1, v = 1, k = 1;

    init();

    while(!(u < 0 && v < 0)) {
        scanf("%d %d", &u, &v);
        if(u == 0 && v == 0){
            printResult(makeMST(), k++);
            init(maxV);
        } else {
            numOfGivenEdge++;
            maxV = max(maxV, max(u, v)); 
            edges.push(make_pair(u, v));
        }
    }
    return 0;
}