#include <stdio.h>
#include <algorithm>
#define N_MAX 100000 //날짜
#define M_MAX 10 //디저트
using namespace std;

int dp[M_MAX+1][N_MAX+1];   //  dp[i-th dessert][day] : day날 i-th dessert를 먹었을때 최댓값
int happy[M_MAX+1][N_MAX+1]; // happy[종류][날짜] = 만족감 
int main(int argc, char const *argv[])
{
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++)  // i  번째 디저트
        for(int j = 0; j < N; j++) // 날짜 
            scanf("%d", &happy[i][j]);

    for(int l = 0; l < M; l++) 
        dp[l][0] = happy[l][0];

    for(int day = 1; day < N; day++) {  // 2일날 부터
        for(int eat = 0; eat < M; eat++) { // 이번에 먹을거
            for(int prevE = 0; prevE < M; prevE++) { // 이전날 먹은거
                dp[eat][day] = max(dp[eat][day], dp[prevE][day-1] +  ((prevE == eat) ? happy[eat][day]/2 : happy[eat][day]));
            }
        } 
    }        
    int maxV = 0;
    for(int l = 0; l < M; l++) 
        maxV = max(maxV, dp[l][N-1]);
    printf("%d\n", maxV);
    return 0;
}