#include<iostream>
using namespace std;

int main(){
    int N,T; scanf("%d %d", &N,&T);
    // 1 2 3 4 2N 2N-1 ..1
    // T�� ���Ͽ�,
    //T(a) = cnt[a] (a�� 2n����)
    //T(a) = cnt(2N-c) (a�� 2n+c)
    //Ta(a) = cnt(c) (a = 2n+c �̰� a�� 4n�̻�..)// �̰� ��ⷯ�� ó��. %4n
    //T(a)  1 ~ N �״��
    // 2N������ �� �߾�. 
    // T(2N+1) () 
    while(T >= 4*N) T = T -4*N+2;

    if(T <=2*N)
        printf("%d", T);
    else // ���ƿ� �� !: 2*n + C ��� �����ϸ�,, 2*n - C�� �ٲ�� �Ѵ�. �̰� 4n-1�������� ����. 4n���ʹ� �ٽ�����. 
        printf("%d", 4*N-T);

    return 0;
}

