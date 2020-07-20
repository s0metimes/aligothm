#include <stdio.h>
#define MAX 1000

long long int dp2[MAX+1][MAX+2];

int main(int argc, char const *argv[])
{
    int n, k, i, j;
    scanf("%d %d", &n, &k);

    for(i = 0; i <= n; i++) {
        dp2[i][0] = dp2[i][i] = 1;
        for(j = 1; i > 1 && j < i; j++) 
            dp2[i][j] = (dp2[i-1][j-1] + dp2[i-1][j])%10007;
    }

    printf("%lld",dp2[n][k]);
    return 0;
}

// #include <stdio.h>
// #define MAX 501500
// long long int dp[MAX+1];
// int trans(int raw, int col);

// int main(int argc, char const *argv[])
// {
//     int n, k, i, j;
//     scanf("%d %d", &n, &k);

//     for(i = 0; i <= n; i++) {
//         dp[trans(i, 0)] = dp[trans(i+1, 0) - 1] = 1;
//         for(j = 1; i > 1 && j < i; j++) 
//             dp[trans(i, j)] = dp[trans(i-1, j-1)]%10007 + dp[trans(i-1, j)]%10007;
//     }

//     printf("%lld",dp[trans(n, k)]%10007);
//     return 0;
// }

// int trans(int raw, int col) {
//     int idx = 0;
//     for(int i = 0; i < raw; i++) 
//         idx += i+1;
//     idx+= col;
//     return idx;
// }

    // for(i = 0; i <= n; i++) {
    //     for(j = 0; j < i+1; j++) 
    //         printf("%lld ",dp[trans(i, j)]%10007);
    //     printf("\n");
    // }
