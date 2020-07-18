#include<stdio.h>

int bino[1001][1001];

int main(){
    int N,K;
    scanf("%d%d\n",&N,&K);
    bino[1][1] = 1;
    for(int i = 2; i <= N;i++)
        for(int j = 1; j< i+1; j++)
            bino[i][j] = (bino[i-1][j-1] + bino[i-1][j]) %10007;
    printf("%d\n",bino[N][K]);
    return 0;
}