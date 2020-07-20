#include<stdio.h>

#define MAXN 100
#define MAXS 20


int main(int argc, char **argv) {
    int t, T, n, N, max, maxIndex;
    char name[MAXN][MAXS];
    int sake[MAXN];

    scanf("%d", &T);

    for(t = 0; t < T; t++) {
        scanf("%d", &N);

        for(n = 0; n < N; n++) {
            scanf("%s %d", name[n], &sake[n]);
        }

        max = -1;
        maxIndex = 0;
        for(n = 0; n < N; n++) {
            if(max < sake[n]) {
                max = sake[n];
                maxIndex = n;
            }
        }

        printf("%s\n", name[maxIndex]);
    }

    return 0;
}