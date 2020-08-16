#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX 1000000

using namespace std;

int num[MAX+1];
vector<int> dp;
int N;

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    int len = 0;

    for(int i = 0; i < N; i++) {
        scanf("%d", &num[i]);
        if(i == 0 || num[i] > dp.back()) {
            dp.push_back(num[i]);
        } else {
            int idx = lower_bound(dp.begin(), dp.end(), num[i]) - dp.begin();
            dp[idx] = num[i];
        }
    }

    printf("%lu\n", dp.size());
    return 0;
}


// // O(n^2) 1,0000,0000,0000 번 연산이므로, 시간초과. 따라서 다른 방법을 생각해야한다.
// #include <stdio.h>
// #include <algorithm>
// #define MAX 1000000
// int N;
// int dp[MAX]; //dp[i] i번째 num을 시작으로, 만들수 있는 최대 길이 
// int num[MAX];

// int main(int argc, char const *argv[])
// {
//     scanf("%d", &N);

//     for(int i = 0; i < N; i++)
//         scanf("%d", &num[i]);

//     dp[N-1] = 1;
//     for(int r_i = N-2; r_i >= 0; r_i--) {
//         for(int c_i = r_i+1; c_i < N; c_i++) 
//             if(num[r_i] < num[c_i] && dp[r_i] < dp[c_i]) 
//                 dp[r_i] = dp[c_i];
//         dp[r_i]++;
//     }

//     printf("%d", *std::max_element(dp, dp+N));
//     return 0;
// }

