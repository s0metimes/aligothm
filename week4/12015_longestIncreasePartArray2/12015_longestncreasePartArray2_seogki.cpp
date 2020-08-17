#include <algorithm>
#include <iostream>
using namespace std;

int cnt = 1;
int num;
int N;
int DP[1000001]; // DP 정의 : N 번째까지에서 가장 긴 증가하는 수열의 길이

int main()
{
    scanf("%d", &N);
    scanf("%d", &DP[cnt]);

    for (int i = 2; i <= N; i++)
    {
        scanf("%d", &num);
        if (DP[cnt] < num)
            DP[++cnt] = num;
        else
        {
            auto p = lower_bound(DP + 1, DP + cnt, num);
            *p = num;
        }
    }

    printf("%d\n", cnt);
}
