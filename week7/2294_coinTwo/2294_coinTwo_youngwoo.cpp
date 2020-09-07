#include <stdio.h>
#include <vector>
#include <algorithm>

#define N_MAX 110
#define K_MAX 100010
#define INF 987654321

using namespace std;

vector<int> coin;
bool chk[K_MAX+1];
int dp[K_MAX+1];
unsigned int sz;
void init(int n, int k) {
    // sort(coin.begin(), coin.end());
    for(int i = 0; i <= k; i++) dp[i] = INF;
    
    for(int c = 0; c < sz; c++) 
        for(int m = coin[c]; m <= k; m++) 
            if(m % coin[c] == 0) dp[m] = min(dp[m], m/coin[c]);
}

int main(int argc, char const *argv[])
{
    // n : 동전의 종류  (1 ≤ n ≤ 100) 
    // k : 만들어야 할 금액  (1 ≤ k ≤ 10,000)
    int n, k, i, value;
    scanf("%d %d", &n, &k);
    
    for(i = 0; i < n; i++) {
        scanf("%d", &value);
        if(!chk[value]) {
            chk[value] = true;
            coin.push_back(value);
        }
    }

    sz = coin.size();
    init(n, k);

    for(int c = 0; c < sz; c++)
        for(int m = coin[c]; m <= k; m++)
            dp[m] = min(dp[m], dp[coin[c]] + dp[m-coin[c]]);

    if(dp[k] == INF) printf("-1\n");
    else printf("%d\n", dp[k]);
    return 0;
}