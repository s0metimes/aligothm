#include <stdio.h>
#include <algorithm>

#define MAXM 1000000

using namespace std;

int cons[MAXM];
int size = 0;

int getNumOfDigit(int N)
{
    int cnt = 0;
    while (N > 0)
    {
        N /= 10;
        cnt++;
    }

    return cnt;
}

int powerOf(int n)
{
    int result = 1;
    for (int i = 0; i < n; i++)
        result *= 10;

    return result;
}

void constructor(int N, int digit, int acc, int original, bool isFirst)
{
    if (digit == 0)
        return;

    if (digit == 1)
    {
        for (int i = 0; i <= 9; i++)
        {
            if (acc + i + i == N)
            {
                cons[size++] = original + i;
            }
        }
        return;
    }

    else
    {
        for (int i = 0; i <= 9; i++)
        {
            constructor(N, digit - 1, acc + i * powerOf(digit - 1) + i, original + i * powerOf(digit - 1), false);
        }
    }

    if (isFirst)
    {
        for (int i = 1; i <= 9; i++)
        {
            constructor(N, digit - 1, i * powerOf(digit - 1) + i, i * powerOf(digit - 1), false);
        }
    }
}

int main(int argc, char **argv)
{
    int N, numOfDigit;

    scanf("%d", &N);
    numOfDigit = getNumOfDigit(N);

    constructor(N, numOfDigit, 0, 0, true);

    if (size == 0)
        printf("0\n");
    else
    {
        sort(cons, cons + size);

        printf("%d\n", cons[0]);
    }

    return 0;
}