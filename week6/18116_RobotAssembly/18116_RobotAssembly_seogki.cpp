#include <cstdio>
#include <string.h>
#define MAX 1000001

int N, A, B, C;
char TMP;
int P[MAX];
int count[MAX];

int FIND(int node){
    if (node == P[node])
        return node;
    return P[node] = FIND(P[node]);
}

void UNION(int a, int b){
    int root_a = FIND(a), root_b = FIND(b);
    if (root_a != root_b){
        P[root_b] = root_a;
        count[root_a] += count[root_b];
    }
}

int main(){
    scanf("%d ", &N);

    // parent, count 배열 초기화
    for (int i = 1; i < MAX; i++){
        P[i] = i;
        count[i] = 1;
    }

    for (int i = 0; i < N; i++){
        TMP = getchar();
        if (TMP == 'I'){
            scanf(" %d %d", &A, &B);
            UNION(A, B);
        }
        else if (TMP == 'Q'){
            int CNT = 0;
            scanf(" %d", &C);

            printf("%d\n", count[FIND(C)]);
        }
        getchar();
    }
}