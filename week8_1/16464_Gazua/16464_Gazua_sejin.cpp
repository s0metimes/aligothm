#include<iostream>
#include<set>
using namespace std;
set<int> s;
int arr[1001][1001]; 

bool isPossible(int K){
    int temp =0;
    for(int i = 2; i <1001; i++){
        for(int j =2; j<1001; j++){
            int sum =0;
            for(int k = i; k<=j; k++){
                sum+= k;
            }
            s.insert(sum);
        }
    }
    
    bool ans = s.insert(K).second == false;
    s.clear();
    return ans;
}

int main(){
    int N; scanf("%d",&N);

    



    while(N--){
        int K; scanf("%d",&K);
        
        printf("%s", isPossible(K) ? "Gazua\n": "GoHanGang\n");
        
        //���� �� �ִ� ���� ���̳ʸ� ��ġƮ���� �ٶ����ڰ� ã�´�. 
        
    }

    return 0;
}