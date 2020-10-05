#include<iostream>
#include<set>
using namespace std;

bool isPossible(int K){
    //K�� 3 �̻��� Ȧ���� ��� 2a+1(a < k)�� �����̴�. �׻� ������
    if(K%2 == 1)
        return true;

    //K�� ¦���� ���. ī�� 2���� ������ 2a+1 ���̶� �ȵ�. �ּ� 3���� �̾ƾ� �մϴ�.
    for(int n = 3; n*(n+1)/2 <= K; n++){
        if(n % 2 == 0){ //¦������ ���� ���
            if((K-n/2) % n == 0)
                return true;
        }else{//Ȧ������ ���� ���
            if(K%n == 0)
                return true;
        }
    }
    return false;
}

int main(){
    //�׽�Ʈ ���̽� ��.
    int N; 
    scanf("%d",&N);

    while(N--){
        int K; scanf("%d",&K);
        printf("%s", isPossible(K) ? "Gazua\n": "GoHanGang\n");
        //���� �� �ִ� ���� ���̳ʸ� ��ġƮ���� �ٶ����ڰ� ã�´�. 
        
    }

    return 0;
}