#include<iostream>
#include<climits>
#include<queue>
#include<set>
using namespace std;
priority_queue<int,vector<int>, less<int>> pq;
set<int> s;

int main(){
    int N; scanf("%d", &N);
    //�ȸ� ������ �Է� �޴´�.
    for(int i =0; i < N; i++){
        int temp; scanf("%d", &temp);
        s.insert(temp);
    }
    // 1���� s�� ���ԵȰ��� �˻��ϸ鼭 �ȵȰ� ����ϰ� ��
    for(int  i = 1; i<=INT_MAX; i++){
        if(s.insert(i).second){
            printf("%d", i);
            return 0;
        }
            
    }
    return 0;
}