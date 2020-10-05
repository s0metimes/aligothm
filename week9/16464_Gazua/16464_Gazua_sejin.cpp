#include<iostream>
#include<set>
using namespace std;

bool isPossible(int K){
    //K가 3 이상의 홀수일 경우 2a+1(a < k)의 형태이다. 항상 존재함
    if(K%2 == 1)
        return true;

    //K가 짝수인 경우. 카드 2개를 뽑으면 2a+1 꼴이라 안됨. 최소 3개는 뽑아야 합니다.
    for(int n = 3; n*(n+1)/2 <= K; n++){
        if(n % 2 == 0){ //짝수개를 뽑은 경우
            if((K-n/2) % n == 0)
                return true;
        }else{//홀수개를 뽑은 경우
            if(K%n == 0)
                return true;
        }
    }
    return false;
}

int main(){
    //테스트 케이스 수.
    int N; 
    scanf("%d",&N);

    while(N--){
        int K; scanf("%d",&K);
        printf("%s", isPossible(K) ? "Gazua\n": "GoHanGang\n");
        //나올 수 있는 값을 바이너리 서치트리에 다때려박고 찾는다. 
        
    }

    return 0;
}