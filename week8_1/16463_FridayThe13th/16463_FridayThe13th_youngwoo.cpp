#include <stdio.h>

int yunYear = 2016;
int daysInMonthArr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int days[7] = {0,1,2,3,4,5,6}; // <일, 월, 화, 수, 목, 금, 토>

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
    // printf("year : 2019 month : 9\n");
    while(year <= targetYear) {
        int daysInMonth;
        if(month == 2) daysInMonth = isYun(year) ? daysInMonthArr[month-1]+1 : daysInMonthArr[month-1];
        else daysInMonth = daysInMonthArr[month-1];

        day = (day + (daysInMonth) % 7) % 7;
        if(month == 12) {year++; month = 1;} // 내년으로 바뀌는 경우
        else month++;

        if(year > targetYear) break;

        if(day == 5) {
            // printf("year : %d month : %d\n", year, month);
            cnt++;
        }
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

