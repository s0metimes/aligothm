#include<iostream>
#include<queue>
using namespace std;

long long acc =0;
long long apple[20001];
long long N;
queue<long long> Q;

long long sum(long long *apple, int time){
    long long ans = 0;
    for(int i = 1; i <= 2*N; i++){
        ans += apple[i];
    }
    return ans * time;
}

void update(long long *apple){
    for(int i = 1; i <= N; i++){
        apple[i];
    }R
}

int main(){
    scanf("%d",&N);
    if(N == 1){
        cout << 2 << '\n';
        cout << 1 <<' '<<2;
        return 0;
    }
    //사과가 나올 순서를 구합니다.
    for(int i = 1; i<= 2*N; i++){
        apple[i] = i;
        if(i < N){
            Q.push(2*N-(2+i));
        }else if (i == N){
            Q.push(2*N-2);
        }else if(i == N+1){
            Q.push(2*N-1);
        }else if(i < 2*N){
            Q.push(2*N-i);
        }else{
            Q.push(2*N);
        }
    }

    cout<<'\n';

    acc = 0;

    //시간마다 사과를 하나씩 꺼냅니다. 
    while(!Q.empty()){
        acc = acc + sum(apple,2*N-Q.size());//해당 시간의 부패도 합을 구합니다. 시간 == 사과 꺼낸 개수
        long long cur = Q.front(); Q.pop();//사과를 꺼내는 과정
        apple[cur] = 0;
    }
    cout << acc<< '\n';









    cout<< 2*N<<' ';
    for(int i = 1; i <= N - 2; i++)
        cout<< i <<' ';
    cout<< 2*N-1<<'\n';
    
    cout<< 2*N-2<<' ';
    
    for(int i = N-1; i <= 2*N - 4; i++)
        cout<< i<<' ';
    cout<< 2*N-3;

    
    return 0;
}