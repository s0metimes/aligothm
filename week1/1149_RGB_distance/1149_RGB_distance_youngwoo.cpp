#include <stdio.h>
#define MAX 1000

int cost[MAX+1][3];

int main(int argc, char const *argv[])
{
    int n, i, j;
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        for(j = 0; j < 3; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    for(i = 1; i < n; i++) {
        for(j = 0; j < 3; j++) {
            if(j == 0) cost[i][j] += cost[i-1][1] < cost[i-1][2] ? cost[i-1][1] : cost[i-1][2]; 
            else if(j == 1) cost[i][j] += cost[i-1][0] < cost[i-1][2] ? cost[i-1][0] : cost[i-1][2];
            else if(j == 2) cost[i][j] += cost[i-1][0] < cost[i-1][1] ? cost[i-1][0] : cost[i-1][1];  
        }
    }
    int min = cost[n-1][0];
    if(cost[n-1][1] < min) min = cost[n-1][1];
    if(cost[n-1][2] < min) min = cost[n-1][2];

    printf("%d\n", min);
    return 0;
}



