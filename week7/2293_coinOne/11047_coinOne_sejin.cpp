#include <bits/stdc++.h>
using namespace std;

int A[100];
int dp1[10001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K; cin>>N;cin>>K;

    for(int i=0; i<N;i++)
        cin>>A[i];
        
    for(int t = 0; t <= K; t += A[0])
        dp1[t] = 1; // a[0] 의 배수들은 기본적으로 경우의 수 1씩 가짐
    
    //a[i]를 갱신해가면서, a[i]를 사용하는 경우의 수를 추가해 준다.

    for(int i = 1; i<N; i++){   
        for (int j = 1 ; j <= K; j++){
            if(j >= A[i])
                dp1[j] += dp1[j -A[i]];
        }
    }
    cout << dp1[K];
    return 0;
}