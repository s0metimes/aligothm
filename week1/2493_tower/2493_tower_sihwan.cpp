#include<stdio.h>

#define MAXN 500000
#define MAXH 100000000

int main(int argc, char **argv) {
    int n, N, towers[MAXN+1], stack[MAXN+1][2], i, j, k, cnt;

    scanf("%d", &N);

    for(n = 0; n <= N; n++) {
        if(n == 0) 
            towers[n] = 0;
        else 
            scanf("%d", &towers[n]);
    }

    i = 0;
    for(n = 1; n <= N; n++) {
        if(n == 1) {
            stack[i][0] = towers[n];
            stack[i][1] = n;
            printf("0 ");
            i++;
        }
        else {
            while(towers[n] > stack[i-1][0] && i != 0) {
                i--;
            }
            if(i != 0) {
                printf("%d ", stack[i-1][1]);
            }                
            else
                printf("0 ");
            stack[i][0] = towers[n];
            stack[i][1] = n;
            i++;
        }
    }
    printf("\n");

    return 0;
}