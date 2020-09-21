#include<iostream>
using namespace std;

int main(){
    int N,T; scanf("%d %d", &N,&T);
    // 1 2 3 4 2N 2N-1 ..1
    // T에 대하여,
    //T(a) = cnt[a] (a가 2n이하)
    //T(a) = cnt(2N-c) (a가 2n+c)
    //Ta(a) = cnt(c) (a = 2n+c 이고 a가 4n이상..)// 이건 모듈러로 처리. %4n
    //T(a)  1 ~ N 그대로
    // 2N까지는 잘 했어. 
    // T(2N+1) () 
    while(T >= 4*N) T = T -4*N+2;

    if(T <=2*N)
        printf("%d", T);
    else // 돌아올 때 !: 2*n + C 라고 생각하면,, 2*n - C로 바꿔야 한다. 이게 4n-1개까지만 가능. 4n부터는 다시증가. 
        printf("%d", 4*N-T);

    return 0;
}

