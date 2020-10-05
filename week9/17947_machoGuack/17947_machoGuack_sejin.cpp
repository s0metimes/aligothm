#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int N,M,K;
vector<int> card; //40�� ����Ʈ: 400ų�ι���Ʈ : 0.4�ް�����Ʈ.

int main(){
    cin>> N>> M >> K;
    //���߿� ���������� ����Ҳ��� �̸� ����
    for(int i = 1; i <= 4*N; i++){
        card.push_back(i);
    }

    for(int i =0; i < M ; i++){
        int a,b;
        cin>>a>>b;
        card[a-1] = -1;
        card[b-1] = -1;
    }
    int myA,myB;
    cin>>myA>> myB;
    card[myA-1] = -1; card[myB-1]= -1;
    myA %= K; myB %= K;
    int myScore = abs(myA-myB);

    //��Ʈ�ؼ� -1ó���� �κ��� ���ش�.
    sort(card.begin(), card.end(),less<int>());
    card.erase(card.begin(),card.begin()+2*M+2);
    //�� ���ϴµ� �ʿ��� ���� ����� �ٽ� ��Ʈ�Ѵ�.
    for(int i = 0; i < card.size(); i++){
        card[i] = card[i]%K;
    }
    sort(card.begin(), card.end(),greater<int>());
    //���� ī���� ����: 4M - 2M -2 == 2M -2

    int left = 0, right = 1;
    int ans = 0;
    //ī�� ������ ������ Ȯ���Ѵ�.
    while(right < card.size()){
        if(card[left] - card[right] >myScore ){
            ans++;
            left++;
            right++;
        }else{
            right++;
        }
    }
    cout << ans;
    return 0;
}