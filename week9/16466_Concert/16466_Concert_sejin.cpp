#include<iostream>
#include<climits>
#include<queue>
#include<set>
using namespace std;
priority_queue<int,vector<int>, less<int>> pq;
set<int> s;

int main(){
    int N; scanf("%d", &N);
    //팔린 디켓을 입력 받는다.
    for(int i =0; i < N; i++){
        int temp; scanf("%d", &temp);
        s.insert(temp);
    }
    // 1부터 s에 포함된건지 검사하면서 안된거 출력하고 끝
    for(int  i = 1; i<=INT_MAX; i++){
        if(s.insert(i).second){
            printf("%d", i);
            return 0;
        }
            
    }
    return 0;
}