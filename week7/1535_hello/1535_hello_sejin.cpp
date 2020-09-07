#include <bits/stdc++.h>
using namespace std;

#define N_MAX 20
#define W_MAX 99

int L[N_MAX+1], J[N_MAX+1]; //���
int dp[N_MAX+1][W_MAX+1];// ��� i ���� ü�� j �� ������ �� �ִ� ��ġ.
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n;
    for(int i = 1; i <=n; i++)
        cin>>L[i];
    for(int i = 1; i <=n; i++)
        cin>>J[i];

    for(int i = 0; i < n; i++){ // i��° ���
        for(int j = 1; j <=99; j++){ //���� �ѵ�.
            if(j >= L[i+1])
                dp[i+1][j] = max(dp[i][j], dp[i][j-L[i+1]] + J[i+1]);
            else 
                dp[i+1][j] =dp[i][j];
        }
    }
    cout << dp[n][99];
  
    return 0;
}