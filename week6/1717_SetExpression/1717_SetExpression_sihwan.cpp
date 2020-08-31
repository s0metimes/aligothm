#include<stdio.h>

#define MAXN 1000000

int parents[MAXN+1];

int find(int a) {
    if(a == parents[a]) return a;
    else return parents[a] = find(parents[a]);
}

void unionWith(int a, int b) {
    parents[find(a)] = find(b);
}

int main(void) {
    int n;  // 원소 수, 1 ~ 1,000,000
    int m;  // 연산 수, 1 ~ 100,000
    int op, a, b;
    int i;
    
    // input n, m
    scanf("%d %d", &n, &m);
    
    // initialize set heights and parents
    for(i = 0; i <= n; i++) parents[i] = i;
    
    // operations
    while(m--) {
        scanf("%d %d %d", &op, &a, &b);
        
        if(op == 0) unionWith(a, b);
        else printf("%s\n", find(a) == find(b) ? "YES":"NO");
    }

    return 0;
}