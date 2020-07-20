#include<stdio.h>

#define MAX 1000

int main(int argc, char **argv) {
    int N, K, i, j;
    int pascal[MAX+1][MAX + 1];

    for(i = 1; i <= MAX; i++) {
        for(j = 0; j <= MAX; j++) {
            if(j == 0) {
                pascal[i][j] = 1;
            }
            else if(i == j) {
                pascal[i][j] = 1;
            }
            else {
                pascal[i][j] = ((pascal[i-1][j-1] % 10007) + (pascal[i-1][j] % 10007)) % 10007;
            }
        }
    }

    scanf("%d %d", &N, &K);

    printf("%d\n", pascal[N][K]);

    return 0;
}