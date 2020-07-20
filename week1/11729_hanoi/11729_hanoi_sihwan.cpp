#include<stdio.h>

#define MAX 20

void stepByStep(int N, int from, int spare, int to) {
    if(N == 1) {
        printf("%d %d\n", from, to);
    }
    else {
        stepByStep(N-1, from, to, spare);
        stepByStep(1, from, spare, to);
        stepByStep(N-1, spare, from, to);
    }
}

int main(int argc, char **argv) {
    int k, K, dp[MAX];
    
    scanf("%d", &K);
    
    for(k = 0; k < K; k++) {
        if(k == 0)
            dp[k] = 1;
        else
            dp[k] = 2*dp[k-1] + 1;
    }

    printf("%d\n", dp[K-1]);
    stepByStep(K, 1, 2, 3);

    return 0;
}