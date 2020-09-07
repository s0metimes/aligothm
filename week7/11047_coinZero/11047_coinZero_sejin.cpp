#include <bits/stdc++.h>
using namespace std;

int A[11];

//K�� arr�� ���� ū ������ ������ ���� Ƚ���� �����Ѵ�.
int sol(int K, int arr[], int maxIndex){
    
    
    int temp =  K / arr[maxIndex]; // �� �� ��������
    int remainder = K %arr[maxIndex];
    if(remainder ==0)
        return temp;
    return temp + sol(remainder,arr,--maxIndex);
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K; cin>>N;cin>>K;
    int maxIndex= N;
    for(int i=1; i<=N;i++)
        cin>>A[i];
    for(int i=1; i<=N;i++){
        if(A[i] > K)
            maxIndex = i-1;
    }

    int ans = sol(K,A,maxIndex);
    cout <<ans;

    return 0;
}