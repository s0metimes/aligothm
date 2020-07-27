#include<stdio.h>

#define MAXN 15
#define MAXT 5

int valueOfT(int T[MAXN+1], int P[MAXN+1], int i, int j) {
    if(T[i] == j-i+1)
        return P[i];
    else
        return 0;
}

int main(int argc, char **argv) {
    int N, T[MAXN+1], P[MAXN+1], i, j, biggest, tmp, dp[MAXN+1];
    
    scanf("%d", &N);
    
    for(i = 1; i <= N; i++) {
        scanf("%d %d", &T[i], &P[i]);
    }

    for(i = 1; i <= N; i++) {
        if(i == 1)
            dp[i] = valueOfT(T, P, 1, 1);
        else if(i <= 5) {
            biggest = valueOfT(T,P,1,i);
            for(j = 1; j < i; j++) {
                tmp = dp[j] + valueOfT(T,P,j+1,i);
                if(biggest < tmp)
                    biggest = tmp;
            }
            dp[i] = biggest;
        }
        else {
            biggest = dp[i-5] + valueOfT(T,P,i-4,i);
            for(j = i-4; j < i; j++) {
                tmp = dp[j] + valueOfT(T,P,j+1,i);
                if(biggest < tmp)
                    biggest = tmp;
            }
            dp[i] = biggest;
        }
    }

    printf("%d\n", dp[N]);    

    return 0;
}