#include <stdio.h>
#define MAX 1000010

int parent[MAX];

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

int main(int argc, char const *argv[])
{
    int n, m;   // (1≤n≤1,000,000), (1≤m≤100,000)
    scanf("%d %d", &n, &m);

    initialize(n);

    int func, a, b; // // a와 b는 n 이하의 자연수 또는 0이며 같을 수도 있다
    while(m--) {
        scanf("%d %d %d", &func, &a, &b);
        
        switch (func)
        {
        case 0: //UNION
            UNION(a, b);    
            break;
        case 1: //check disjoint
            if(isDisjoint(a, b)) printf("NO\n");
            else printf("YES\n");
            break; 
        }
    }
    return 0;
}