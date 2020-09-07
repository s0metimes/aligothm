#include <stdio.h>
#include <algorithm>
#define N_MAX 100
#define K_MAX 10000

using namespace std;

int dp[K_MAX+1];
int coin[N_MAX+1];

int main(int argc, char const *argv[])
{
    // n : 동전 가짓수 (1 ≤ n ≤ 100) 
    // k : 만들어야 할 금액 (1 ≤ k ≤ 10,000)
    int n, k, i;
    scanf("%d %d", &n, &k);

    for(i = 0; i < n; i++) 
        scanf("%d", &coin[i]);
    
    dp[0] = 1;
    for(int c = 0; c < n; c++) 
        for(int m = coin[c]; m <= k; m++) 
            dp[m] += dp[m - coin[c]];
        
    printf("%d", dp[k]);
    return 0;
}
