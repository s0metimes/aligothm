#include <stdio.h>

int MAX = -1;
int N;
int DP[1001]; // DP 정의 : N 번째까지에서 가장 긴 증가하는 수열의 길이
int MAP[1001];

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &MAP[i]);

    for (int i = 1; i <= N; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (MAP[j] < MAP[i])
            {
                DP[i] = (DP[j] + 1 < DP[i]) ? DP[i] : DP[j] + 1;
            }
        }
        MAX = (DP[i] > MAX) ? DP[i] : MAX;
    }
    printf("%d\n", MAX);
}
