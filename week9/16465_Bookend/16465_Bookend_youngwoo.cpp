#include <stdio.h>

int main(int argc, char const *argv[])
{
    // n : 책의 개수 정수 n (1 ≤ n ≤ 100) 
    // m : 책장의 너비 정수 m (1 ≤ m ≤ 300) 
    // l : 북엔드의 바닥 면의 길이 정수 l (1 ≤ l ≤ 300)
    // xi : 각 책의 너비인 정수 (1 ≤ xi ≤ 3)가 왼쪽 책부터 차례대로 n개 주어진다.
    int n, m, l; 
    int sum = 0, xi;
    scanf("%d %d %d", &n, &m, &l);
    for(int i = 0; i < n; i++) {
        scanf("%d", &xi);
        sum += xi;
    }
    
    // 책들이 너무 많아서 책장에 안들어가는 경우
    if(sum > m) printf("-1\n");
    // 책장과 책들의 총합이 같다면 북앤드가 필요 없다
    else if(sum == m) printf("0\n");
    // 책장의 너비가 책들의 총합보다 크다면
    // 북앤드가 너무커서 책장에 안들어가는 경우
    else if(l > m) printf("-1\n");
    // 책들의 총합이 북앤드보다 큰 경우라면, 표현가능하다.
    else if(sum >= l) printf("1\n");
    // 하지만, 작은 경우 북앤드를 반대로 두는 경우가 가능한지
    // 체크해야한다.
    // 이경우, 북앤드 길이 + 책의 총합이 m보다 작거나 같은지 체크해야한다.
    else if(sum + l <= m) printf("1\n");
    // 이 모든 경우가 아니라면 표현 불가능하다.
    else printf("1\n");
    return 0;
}