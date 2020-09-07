#include <bits/stdc++.h>
using namespace std;


int coin[100];
int dp[10001];
bool input[100001];
// int coin[3];
// int dp[16];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K; cin>>N;cin>>K;

    dp[0] =0;
    for(int i = 1; i <=K;i++)
        dp[i] = 10001;    
    for(int i = 0; i <N;){
        //중복 입력 처리

        // int temp;
        // cin >> temp;
        // if(!input[temp]){
        //     input[temp] =true;
        //     coin[i] = temp;
        //     i++;
        // }
        cin>>coin[i++];
    }
        
    
    for(int i = 0 ; i< N; i++){
        for(int j =1; j <=K; j++){
            if(j-coin[i] < 0)continue;
             dp[j] = min(dp[j], dp[j-coin[i]]+1);
        }
    }

    if(dp[K] == 10001)
        cout<< -1;
    else
        cout << dp[K];
    
    return 0;
}