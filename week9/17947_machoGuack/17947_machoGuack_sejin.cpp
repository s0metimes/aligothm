#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int N,M,K;
vector<int> card; //40만 바이트: 400킬로바이트 : 0.4메가바이트.

int main(){
    cin>> N>> M >> K;
    //나중에 나머지끼리 계산할꺼라서 미리 나눔
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

    //소트해서 -1처리된 부분을 없앤다.
    sort(card.begin(), card.end(),less<int>());
    card.erase(card.begin(),card.begin()+2*M+2);
    //답 구하는데 필요한 값만 남기고 다시 소트한다.
    for(int i = 0; i < card.size(); i++){
        card[i] = card[i]%K;
    }
    sort(card.begin(), card.end(),greater<int>());
    //남은 카드의 개수: 4M - 2M -2 == 2M -2

    int left = 0, right = 1;
    int ans = 0;
    //카드 사이의 간격을 확인한다.
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