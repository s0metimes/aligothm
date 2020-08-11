#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 5000
#define mod 1000000
int DP[MAX + 5] = {1,1,};
int N;

int main()
{
    string MAP;
    cin >> MAP;
    int len = MAP.length();

    for (int i = 2; i <= len; i++)
    {
        if (MAP[i - 1] > '0')
            DP[i] = DP[i - 1] % mod;

        int dif = (MAP[i - 2] - '0') * 10 + MAP[i - 1] - '0';

        if (9 < dif && dif < 27)
            DP[i] = (DP[i] + DP[i - 2]) % mod;
    }
    if(MAP[0] == '0')
        printf("0\n");
    else 
        printf("%d\n", DP[len]);
    return 0;
}