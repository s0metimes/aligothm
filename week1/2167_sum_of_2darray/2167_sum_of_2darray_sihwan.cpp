#include<stdio.h>

#define LEN 300

int main(int argc, char **argv) {
    int n, N, m, M, arr[LEN][LEN], k, K, i, j, x, y, sum;
    
    scanf("%d %d", &N, &M);
    
    for(n = 0; n < N; n++) {
        for(m = 0; m < M; m++) {
            scanf("%d", &arr[n][m]);
        }
    }

    scanf("%d", &K);

    for(k = 0; k < K; k++) {
        scanf("%d %d %d %d", &i, &j, &x, &y);
        
        i--; j--; x--; y--;

        sum = 0;
        for(n = i; n <= x; n++) {
            for(m = j; m <= y; m++) {
                sum += arr[n][m];
            }
        }

        printf("%d\n", sum);
    }

    return 0;
}