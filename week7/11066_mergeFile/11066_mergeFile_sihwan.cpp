#include<stdio.h>
#include<queue>

using namespace std;

#define MAX 500
#define MAXSIZE 10000

int dp[MAX+1][MAX+1];
int sizes[MAX+1];

int min(int a, int b) {
    return a > b? b : a;
}

int main(void) {
    int T;  // 테스트케이스
    int K;  // 장의 수, 3~500
    int fileSize;
    int i, j, k, interval;

    scanf("%d", &T);

    while(T--) {
        scanf("%d", &K);
        for(i = 0; i < K; i++) {
            scanf("%d", &fileSize);
            sizes[i+1] = fileSize + sizes[i];
        } 

        for(interval = 1; interval <= K; interval++) {
            for(i = 1; i+interval <= K; i++) {
                j = i+interval;
                dp[i][j] = MAXSIZE*MAXSIZE;
                for(k = i; k <= j; k++) {
                    dp[i][j] = min(dp[i][k] + dp[k+1][j], dp[i][j]);
                }

                dp[i][j] += sizes[j]-sizes[i-1];
            }
        }
        
        printf("%d\n", dp[1][K]);
    }

    return 0;
}