#include <stdio.h>
#include <algorithm>
#define MAX 1000

using namespace std;

bool arr[MAX+1][MAX+1];
int nums[MAX+1];
int incre[MAX+1];
int dp[MAX+1];

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) 
        scanf("%d", &nums[i]);

    for(int i = 0; i < N; i++) {
        int big = 0;
        for(int j = i+1; j < N; j++) 
            if(nums[i] < nums[j]) big++;
        incre[i] = big;
    }

    for(int y = 0; y < N; y++)
        for(int x = y+1; x < N; x++) 
            if(nums[y] < nums[x]) arr[y][x] = true;

    for(int ridx = N-1; ridx >= 0; ridx--) {
        if(incre[ridx] == 0) dp[ridx] = 1;
        else {
            int max = 0;
            for(int ch = ridx+1; ch < N; ch++) 
                if(arr[ridx][ch] && dp[ch] > max) max = dp[ch];
            dp[ridx] = max+1;
        }
    }

    printf("%d", *max_element(dp, dp+N));

    return 0;
}

// #include <stdio.h>
// #include <vector>
// #define MAX 1000

// using namespace std;

// vector<int> vec;
// bool arr[MAX+1][MAX+1];
// int nums[MAX+1];
// int incre[MAX+1];
// int dp[MAX+1];
// int maxV = 0;
// int N;

// void dfs(int y, int temp) {
//     if(incre[y] == 0) {
//         if(maxV < temp) maxV = temp;
//         temp = 1;
//         return;
//     }   
//     for(int x = y; x < N; x++) 
//         if(arr[y][x] == 1) dfs(x, temp+1);
// }

// int main(int argc, char const *argv[])
// {
//     scanf("%d", &N);
//     for(int i = 0; i < N; i++) 
//         scanf("%d", &nums[i]);

//     for(int i = 0; i < N; i++) {
//         int big = 0;
//         for(int j = i+1; j < N; j++) 
//             if(nums[i] < nums[j]) big++;
//         incre[i] = big;
//     }

//     for(int y = 0; y < N; y++)
//         for(int x = y+1; x < N; x++) 
//             if(nums[y] < nums[x]) arr[y][x] = true;

//     for(int x = 0; x < N; x++) 
//         dfs(x, 1);

//     printf("%d\n", maxV);

//     for(int ridx = N-1; ridx >= 0; ridx--) {
//         if(incre[ridx] == 0) dp[ridx] = 1;
//         else {
//             int max = 0;
//             for(int ch = ridx+1; ch < N; ch++) 
//                 if(arr[ridx][ch] && dp[ch] > max) max = dp[ch];
//             dp[ridx] = max+1;
//         }
//     }
//     for(int i = 0; i < N; i++) 
//         printf("%3d", i);
//     printf("\n");
//     for(int i = 0; i < N; i++) 
//         printf("%3d", dp[i]);

//     return 0;
// }

// #include <stdio.h>
// #include <vector>
// #define MAX 1000

// using namespace std;

// vector<int> vec;
// bool arr[MAX+1][MAX+1];
// int nums[MAX+1];
// int incre[MAX+1];
// int maxV = 0;
// int N;

// void dfs(int y, int temp) {
//     if(incre[y] == 0) {
//         // vec.push_back(nums[y]);
//         if(maxV < temp) {
//             maxV = temp;
//             // printf("\n"); 
//             // printf("*********************************\n");
//             // printf("Max is Changed\n");
//             // for(int i = 0; i < vec.size(); i++)
//             //     printf("%d ", vec[i]);
//             // printf("\n"); 
//             // printf("*********************************\n");
//             // printf("\n"); 
//         }
//         // else {
//         //     printf("There is no big element after me\n");
//         //     for(int i = 0; i < vec.size(); i++)
//         //         printf("%d ", vec[i]);
//         //     printf("\n"); 
//         // }
//         temp = 1;
//         // vec.pop_back();
//         return;
//     }   
//     for(int x = y; x < N; x++) {
//         if(arr[y][x] == 1) {
//             // vec.push_back(nums[y]);
//             dfs(x, temp+1);
//             // vec.pop_back();
//         }
//     }
// }

// int main(int argc, char const *argv[])
// {
//     scanf("%d", &N);
//     for(int i = 0; i < N; i++) 
//         scanf("%d", &nums[i]);

//     for(int i = 0; i < N; i++) {
//         int big = 0;
//         for(int j = i+1; j < N; j++) 
//             if(nums[i] < nums[j]) big++;
//         incre[i] = big;
//     }

//     for(int y = 0; y < N; y++)
//         for(int x = y+1; x < N; x++) 
//             if(nums[y] < nums[x]) arr[y][x] = true;

//     // for(int y = 0; y < N; y++){
//     //     for(int x = 0; x < N; x++) { 
//     //         printf("%2d", arr[y][x] ? 1:0);
//     //     }
//     //     printf("\n");
//     // }

//     for(int x = 0; x < N; x++) 
//         dfs(x, 1);

//     printf("%d\n", maxV);
    
//     return 0;
// }

// 11
// 7 5 10 30 40 50 11 12 13 14 15