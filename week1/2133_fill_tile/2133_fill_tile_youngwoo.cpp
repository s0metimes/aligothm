#include <stdio.h>

int main()
{
	int DP[31] = { 0 };
	int n, i, j;

    scanf("%d", n);

	DP[0] = 1;
	DP[2] = 3;
    for (i = 4; i <= n; i++)
    {
        DP[i] = DP[i - 2] * 3; // 2x3 도형을 가장 오른쪽에 두는 경우, 2x3 도형이 3개이기 때문에 *3을 해준다
        for (j = 4; j <= i; j += 2)
        {
            DP[i] += DP[i - j] * 2; // n=4부터는 새로운 도형이 추가된다. 하지만 n이 4,6,8,10...일때 도형의 모양이 모두 다르기 때문에 각각 dp[i]에 더해준다.
        }
    }
	printf("%d\n", DP[n]);
	return 0;
}



// #include <stdio.h>
// #define MAX 1000

// long long int dp[MAX+1];

// int main(int argc, char const *argv[])
// {
//     int n, i;

//     scanf("%d", &n);

//     if(n%2 == 1) {
//         printf("0\n");
//         return 0;
//     }

//     dp[2] = 3;
//     dp[4] = 9;
//     for(i = 4; i <= n; i+=2) 
//         dp[i] = dp[i-2]*3 + dp[i-4]*2;
//     printf("%lld\n", dp[n]%10007);
//     return 0;
// }
