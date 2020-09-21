#include<iostream>
#include<math.h>
using namespace std;
//업, 다운, 직접타이핑이 있음

int getTermOnUpDown(float from, float to){
    // 안되는 경우는 없다. 주파수 범위를 벗어나면 반대쪽 경계로 설정되니까.
    int caseUp, caseDown;
    if(from == to)
        return 0;
    // 
    else if(from > to){ //145.6 -> 146, 144 -> 146
        //up
        caseUp = to -from
        //down
    }else if(from < to){

    }
}
int getMinclick(float from, float to){
    if(abs(from-to)>)
    return 0;
}
int main(){
    int cntAB = 0, cntKeypad=0, cntUp =0, cntDown=0;
    int T; scanf("%d", &T);
    while(T--){
        float targetFreq,Afreq,Bfreq; char c;
        scanf("%f %f %c %f", &Afreq, &Bfreq, &c,&targetFreq);
        //A나 B 주파수에서 적절히 변경하여 타겟 주파수까지 증가시켜야 한다.
        //각 채널별로 비교해보자. 
        //1. 각 채널별 차이를 구한다.
        //한 채널을 구했을 경우, 그 채널 안에서 up, down,  세팅중(6번) 하나를 선택한다.
        int caseA,caseB;
        //채널별 차이가 같은 경우 현재 설정 채널이용

        // 현재 설정 채널
        if(Afreq == Bfreq){
            
        }
        else if(abs(targetFreq - Afreq) < abs(targetFreq - Bfreq)){
            
        }else if()

    }
    
    return 0;
}