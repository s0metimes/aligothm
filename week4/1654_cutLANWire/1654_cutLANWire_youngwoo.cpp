#include <stdio.h>
#define MAX_K 10000
#define MAX_N 1000000
#define MAX_LENGTH 2147483647 // 2^31 - 1

long long int LAN[MAX_K];
int main(int argc, char const *argv[])
{
    int N, K, i, temp = 0;

    scanf("%d %d", &K, &N);

    for(i = 0; i < K; i++) 
        scanf("%lld", &LAN[i]);

    long long int left, right, mid;
    left = 0;
    right = MAX_LENGTH;
    while(left <= right) {
        temp = 0;
        mid = (left + right)/2;
        for(i = 0; i < K; i++)
            temp += LAN[i]/mid;
        if(temp < N) right = mid - 1;
        else if(temp >= N) left = mid + 1; 
    }
    printf("%lld\n", right);
    return 0;
}

// #include <stdio.h>
// #define MAX_K 10000
// #define MAX_N 1000000
// #define MAX_LENGTH 2147483647 // 2^31 

// long long int LAN[MAX_K];
// int main(int argc, char const *argv[])
// {
//     int N, K, i, temp = 0;

//     scanf("%d %d", &K, &N);

//     for(i = 0; i < K; i++) 
//         scanf("%lld", &LAN[i]);

//     long long int left, right, mid;
//     left = 0;
//     right = MAX_LENGTH;
//     while(left <= right) {
//         temp = 0;
//         mid = (left + right)/2;
//         // printf("%lld cm로 나누고자 한다.\n", mid);
//         for(i = 0; i < K; i++)
//             temp += LAN[i]/mid;
//         // printf("=>주어진 LAN선으로는 %d 의 조각을 만들 수 있다.\n", temp);
//         // printf("left : %lld mid : %lld right : %lld\n", left, mid, right);
//         if(temp < N) {
//             // printf("우리가 만들고자하는 %d보다 적게 만들어지므로, %lld 보다 더 작은 길이로 나눠야 한다.\n", N, mid);
//             right = mid - 1;
//         }
//         else if(temp >= N) {
//             // printf("우리가 만들고자하는 %d 이상으로 만들어지므로, %lld 보다 좀더 큰 길이를 시도해 보자.\n", N, mid);
//             left = mid + 1; 
//         }
//         // printf("\n");
//     }
//     // printf("left : %lld mid : %lld right : %lld\n", left, mid, right);
//     printf("%d\n", right);
//     return 0;
// }