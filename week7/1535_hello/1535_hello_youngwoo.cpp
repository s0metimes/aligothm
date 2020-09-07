#include <stdio.h>
#include <algorithm>
#define MAXN 20
#define MAXHP 100

using namespace std;

int hp[MAXN+1];
int pl[MAXHP+1];
int dp[MAXN+1][MAXHP+1];

int main(int argc, char const *argv[])
{
    int N, i;
    scanf("%d", &N);

    for(i = 1; i <= N; i++) scanf("%d",&hp[i]);

    for(i = 1; i <= N; i++) scanf("%d",&pl[i]);

    for(int k = 0; k < N; k++)     // k : k번째 사람을 의미 
        for(int h = 1; h <= MAXHP; h++)   // h : 가지고 있는 체력 
            dp[k+1][h] = (h > hp[k+1]) ? max(dp[k][h], dp[k][h - hp[k+1]] + pl[k+1]) : dp[k][h]; 

    printf("%d\n",dp[N][1]);
    printf("%d\n", dp[N][MAXHP]);
    return 0;
}