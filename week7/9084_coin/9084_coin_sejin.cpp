#include <bits/stdc++.h>
using namespace std;

int T,N, M;
int dp[21][100001];
int coinList[21];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>T;
    while(T--){
        cin >> N;
        for(int i = 1; i<= N; i++)
            cin >>coinList[i];
        cin>>M;     
        for(int i=1;i<=N;i++){
            for(int j= 1; j <=M; j++){
                if(j%coinList[i] == 0)// 자기 자신으로 충족되는 경우. 
                    dp[i][j]++;
                for(int k = 0; j - coinList[i]*k > 0; k++){
                    dp[i][j]+= dp[i-1][j-coinList[i]*k];  //d[3][22] = d[2][15]+ d[2][8]+ d[2][1] + 자기자신 ㄴㄴ
                }
                
            }
        }
        cout<<dp[N][M]<<'\n';
        for(int i = 1; i<= N; i++ )
            for(int j = 1; j <=M; j++)
                dp[i][j] = 0;
    }

    return 0;
}