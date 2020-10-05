#include <stdio.h>

int daysInMonthArr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isYun(int year) {
    if(year%400 == 0) return true;
    
    if(year%100 == 0) return false;

    if(year%4 == 0) return true;

    return false;
}

void calculate(int targetYear) {
    int day = 5; // 금요일은 5의 값을 가진다. 
    int month = 9;
    int year = 2019;
    int cnt = 1;
    while(year <= targetYear) {
        int daysInMonth; // 해당하는 달의 총 일수 
        // 2월인경우는 윤년인지 아닌지, 체크해줘야한다. 
        if(month == 2) daysInMonth = isYun(year) ? daysInMonthArr[month-1]+1 : daysInMonthArr[month-1];
        else daysInMonth = daysInMonthArr[month-1];
        // 다음달 13일의 요일은 확인해야한다.
        // 이번달 13일과 다음달 13일의 일수 차이는 이번달의 총 일수와 같다.
        day = (day + (daysInMonth) % 7) % 7;

        if(month == 12) {year++; month = 1;} // 내년으로 바뀌는 경우
        else month++; // 해가 바뀌지 않는경우는 month++
        // 해가 바뀌었을때, targetYear를 넘어선다면, cnt를 증가시키지않고 break
        // 그렇지 않다면, 다음달13일의 요일을 확인후, 금요일이면 cnt++
        if(year > targetYear) break;
        else if(day == 5) cnt++;
    }

    printf("%d\n", cnt);
}

int main(int argc, char const *argv[])
{
    int targetYear;
    scanf("%d", &targetYear);

    calculate(targetYear);
    return 0;
}