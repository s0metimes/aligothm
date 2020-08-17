#include<stdio.h>
#define MAX 14
int queens[MAX], cnt, n, N;

bool isPlacable(int level, int placed) {
    for(n = 0; n < level; n++)
        if(queens[n] == placed || n-level == queens[n]-placed || n-level == placed-queens[n])
            return false;
    return true;
} 

void placeQueen(int level) {
    if(level == N) { cnt++; return; }

    for(int i = 0; i < N; i++)
        if(isPlacable(level, i)) {
            queens[level] = i;
            placeQueen(level+1);
        }
}

int main(void) {
    scanf("%d", &N);
    placeQueen(0);
    printf("%d\n", cnt);
    return 0;
}
