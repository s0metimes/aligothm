#include<iostream>
// #include<stack>
#include<bits/stdc++.h>
using namespace std;

stack<pair<int,int>> s;
int ans;

void doHw(){//�ѽð����� ������
    

    if(s.top().second==1){//�ѽð� �������� ��������
        ans += s.top().first;
        s.pop();
    }else{
        s.top().second--;//�ƴϸ� �ѽð� ����
    }
}
int main(){

    int N; scanf("%d",&N);
    int h,A,T;
    while(N--){
        scanf("%d", &h);
        if(h == 0){
            if(s.empty())
                continue;
            else{
                doHw();
            }
        }else{//���� �߰��ϰ� ��������
            scanf("%d %d",&A,&T);
            s.push(make_pair(A,T));
            doHw();
        }
    }
    
    printf("%d", ans);
    return 0;
}