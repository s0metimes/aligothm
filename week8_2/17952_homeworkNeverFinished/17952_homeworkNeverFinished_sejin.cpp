#include<iostream>
// #include<stack>
#include<bits/stdc++.h>
using namespace std;

stack<pair<int,int>> s;
int ans;

void doHw(){//한시간동안 과제함
    

    if(s.top().second==1){//한시간 남았으면 과제제출
        ans += s.top().first;
        s.pop();
    }else{
        s.top().second--;//아니면 한시간 진행
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
        }else{//과제 추가하고 과제진행
            scanf("%d %d",&A,&T);
            s.push(make_pair(A,T));
            doHw();
        }
    }
    
    printf("%d", ans);
    return 0;
}