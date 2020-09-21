#include<iostream>
using namespace std;

bool isLeapYer(int year){
    if(year%400 == 0)
        return true;
    else if(year%4 == 0 && year % 100 !=0)
        return true;
    return false;
}
int getDays(int month){
    //1, 3, 5, 7,8,10,12 
    if(month == 1 || month==3||month==5 ||month==7||month==8||month==10||month==12)
        return 31;
    else if(month ==2)
        return 28;
    else
        return 30;
}
int main(){
    int N; scanf("%d", &N);
    //3�� 13�� �ݿ��Ϻ��� �Ѵ޾� ���ؼ� 7�� ����������� 13���� ���ǿ���
    int day = 0; // 2�� 15��
    int ans = 0;

    for(int i = 2019; i<=N; i++){
        for(int j = 1; j <=12; j++){
            if(i == 2019 && j== 1) j = 9;
            if(day%7 ==0)
                ans+=1;   
            
            if(j ==2){
                if(isLeapYer(i))
                    day+=29;
                day+=28;
            }else{
                day+=getDays(j);
            }
        }
    }
    printf("%d", ans);
    
    return 0;
}