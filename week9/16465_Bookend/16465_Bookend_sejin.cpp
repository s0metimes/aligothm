#include<iostream>
using namespace std;

int width[301];
int N, M, L;// N: å�� ����, M : å���� �ʺ�, L: �Ͽ����� �ٴڸ� ����
int A;

int main(int argc, char const *argv[])
{
    cin >> N >> M >> L;
    for(int i = 1; i <= N; i++){
        cin>> width[i];
        A += width[i];
    }

    //å �� �ʺ� A��� ������ ��
    // A == M �̸� ���� 0�̴�.
    //A < M �̸� �Ͽ��带 ����ϰ�
    // A > M�̸� �Ұ����̶� -1�̴�.
    
    if(A == M)
        cout<< 0;
    else if(A > M)
        cout << -1;
    else{  // A < å��ʺ�
        //��� å�� ���, �ϳ��� ������ �� ���� ���ε�, �Ͽ��� �ٴڸ� ���̰� �����̴�.
        // 1. A >= L �� ��� �ϳ��� ������ �ȴ�. 
        // 2. A < L �� ���, å�� ������ ������ ����(M-A)�� �鿣�带 ���� �� ������ �ȴ�.
        // M-A >= L�̸� �ȴ�!!
        //������ -1���ϵ�
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
