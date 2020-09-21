#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int getAverage(vector<int> list){
    float temp = 0;
    for(auto x : list)
        temp += x;
    temp /= list.size();
    return round(temp);
}
int main(){
    int N, temp, d1,d2;
    vector<int> list;
    scanf("%d", &N);
    for(int i = 1; i <=N; i++){
        scanf("%d", &temp);
        if(temp == 100){
            list.push_back(temp);
        }else{
            d1 = temp /10;  d2 = temp % 10;
            if(d1 == 6) d1 = 9;
            if(d2 == 0 || d2 == 6) d2 = 9;
            list.push_back(d1*10 + d2);
        }
    }
    printf("%d", getAverage(list));
}