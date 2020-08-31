#include<stdio.h>

#define MAX 1000000

int parents[MAX];
int size[MAX];

int find(int a) {
    if(a == parents[a]) return a;
    else return parents[a] = find(parents[a]);
}

void unionWith(int a, int b) {
    int root1 = find(a);
    int root2 = find(b);
    parents[root1] = root2;
    if(root1 != root2)
        size[root1] = size[root2] = size[root1] + size[root2];
}

int main(void) {
    int N;  // 1 ~ 1,000,000
    char op;
    int a, b;    // a,b : 1 ~ 1,000,000
    int c;   // c : 1 ~ 1,000,000
    int i;

    for(i = 0; i < MAX; i++) {
        parents[i] = i;
        size[i] = 1;
    }

    scanf("%d\n", &N);

    while(N--) {
        scanf(" %c ", &op);
        if(op == 'I') {
            scanf("%d %d", &a, &b);
            unionWith(a-1, b-1);
        }
        else {
            scanf("%d", &c);
            printf("%d\n", size[find(c-1)]);
        }
    }

    return 0;
}