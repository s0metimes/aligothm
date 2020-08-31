#include <stdio.h>
#define MAX_city 201
#define MAX_plan 1001

int N, M, A, B, TMP, now, past;
int P[MAX_city];
int plan[MAX_plan];

int FIND(int node) {
    if (node == P[node])
        return node;
    return P[node] = FIND(P[node]);
}

void UNION(int a, int b) {
    int root_a = FIND(a);
    int root_b = FIND(b);
    P[root_b] = root_a;
}

void pathCompression() {
    for (int i = 1; i <= N; i++)
        FIND(i);
}
void printParent() {
    for (int i = 1; i <= N; i++)
        printf("%d ", P[i]);
    printf("\n");
}

void checkPlan() {
    pathCompression();
    scanf("%d", &TMP);
    past = TMP;
    for (int i = 1; i < M; i++) {
        scanf("%d", &TMP);
        now = TMP;
        if (FIND(now) == FIND(past))
            past = now;
        else {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
}

int main() {
    scanf("%d %d", &N, &M);
    // parent 배열 초기화
    for (int i = 1; i <= N; i++)
        P[i] = i;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            scanf("%d", &TMP);  //1이면 연결, 0 이면 연결이 안된 상태 (양방향 그래프)
            if (TMP == 1)
                UNION(i, j);
        }
    if (M == 1)
        printf("YES\n");
    else
        checkPlan();
}