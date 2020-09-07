#include <bits/stdc++.h>
using namespace std;

int cal[5001];
int price[5001];
int dp[10001];
int n,m;

// int cal[2];
// int price[2];
// int dp[11];


int main()
{
    while(true){
        scanf("%d", &n);
        float temp;
        scanf("%f",&temp);
        m = int(temp*100+0.5);

        if(n == 0 && m ==0)
            return 0;
        
        for(int i = 1; i <= n; i++){
            scanf("%d", &cal[i]) ;
            float temp;
            scanf("%f",&temp);
            price[i] = int(temp*100+0.5);
        }

        for(int i =1; i<= n; i++){ 
            for(int j = 1; j<=m; j++){
                if(j-price[i] < 0)
                    continue;
                dp[j] = max(dp[j], dp[j-price[i]]+cal[i]);
            }
        }

        cout << dp[m] << '\n';
    }
   
    return 0;
}