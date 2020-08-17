#include<stdio.h>

int counts[20000001];

int main(void) {
    int N, M, n, m, num;
    
    scanf("%d", &N);
    for(n = 0; n < N; n++) {
        scanf("%d", &num);
        counts[num+10000000]++;
    }

    scanf("%d", &M);
    for(m = 0; m < M; m++) {
        scanf("%d", &num);
        printf("%d ", counts[num+10000000]);
    }
    printf("\n");


    return 0;
}