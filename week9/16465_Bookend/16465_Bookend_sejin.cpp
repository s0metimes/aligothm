#include<iostream>
using namespace std;

int width[301];
int N, M, L;// N: 책의 개수, M : 책장의 너비, L: 북엔드의 바닥면 길이
int A;

int main(int argc, char const *argv[])
{
    cin >> N >> M >> L;
    for(int i = 1; i <= N; i++){
        cin>> width[i];
        A += width[i];
    }

    //책 총 너비가 A라고 가정할 때
    // A == M 이면 답은 0이다.
    //A < M 이면 북엔드를 써야하고
    // A > M이면 불가능이라 -1이다.
    
    if(A == M)
        cout<< 0;
    else if(A > M)
        cout << -1;
    else{  // A < 책장너비
        //사실 책이 몇개든, 하나면 고정할 수 있을 것인데, 북엔드 바닥면 길이가 관건이다.
        // 1. A >= L 인 경우 하나만 있으면 된다. 
        // 2. A < L 인 경우, 책을 제외한 나머지 공간(M-A)에 백엔드를 세울 수 있으면 된다.
        // M-A >= L이면 된다!!
        //나머진 -1개일듯
        if(A >= L){
            cout << 1;
        }else if((M-A) >= L){
            cout << 1;
        }else{
            cout << -1;
        }
    }

    return 0;
}
