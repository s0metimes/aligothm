#include<stdio.h>

#define MAX 1000

int main(int argc, char **argv) {
    int n, N,dp[MAX][3], R, G, B, i, j, min, a, b;

    scanf("%d", &N);

    for(n = 0; n < N; n++) {
        scanf("%d %d %d", &R, &G, &B);
        
        if(n == 0) {
            dp[n][0] = R;
            dp[n][1] = G;
            dp[n][2] = B;
        }
        else {
            for(i = 0; i < 3; i++) {
                min = 1000001;
                for(j = 0; j < 3; j++) {
                    if (i != j && min > dp[n-1][j]) {
                        min = dp[n-1][j];
                    }
                }
                
                if(i == 0) dp[n][i] = min + R;
                if(i == 1) dp[n][i] = min + G;
                if(i == 2) dp[n][i] = min + B;
            }
        }
    }

    min = 1000001;
    for(i = 0; i < 3; i++) {
        if(min > dp[N-1][i])
            min = dp[N-1][i];
    }
    
    printf("%d\n", min);

    return 0;
}