#include<stdio.h>

#define MAX 100000000
#define MAXN 10

int coins[MAXN];
int cnt;

int main(void) {
    int N;  // 동전의 종류, 1~10
    int K;  // 가치의 합, 1~100,000,000
    int i;

    scanf("%d %d", &N, &K);

    for(i = 0; i < N; i++) scanf("%d", &coins[i]);

    while(N--) {
        while(K > 0) {
            K -= coins[N];
            cnt++;
        }
        if(K == 0) break;
        K += coins[N];
        cnt--;
    }
    
    printf("%d\n", cnt);

    return 0;
}