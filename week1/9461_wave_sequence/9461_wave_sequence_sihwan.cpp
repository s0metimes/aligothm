#include<stdio.h>

#define MAX 100

int main(int argc, char **argv) {
    int t, T, n, N;
    long long int P[MAX+1];

    scanf("%d", &T);

    for (n = 0; n <= MAX; n++)
    {
        if (n >= 0 && n <= 3)
            P[n] = 1;
        else if (n == 4 || n == 5)
            P[n] = 2;
        else
            P[n] = P[n - 1] + P[n - 5];
    }

    for(t = 0; t < T; t++) {
        scanf("%d", &N);
        printf("%lld\n", P[N]);
    }

    return 0;
}