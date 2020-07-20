#include <stdio.h>
#define MAX 1000

long long int dp[MAX+1];

int main(int argc, char const *argv[])
{
    int n, i;

    scanf("%d", &n);

    for(i = 0; i <= 2; i++) 
        dp[i] = i;

    for(i = 3; i <= n; i++) 
        dp[i] = (dp[i-1]+ dp[i-2])%10007;
    printf("%lld\n", dp[n]);
    return 0;
}
