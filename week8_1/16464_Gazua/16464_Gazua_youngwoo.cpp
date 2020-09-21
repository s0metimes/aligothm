#include <stdio.h>

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    while(N--) {
        int K, i;
        scanf("%d", &K);
        for(i = 2; i <= K/2; i++) {// 카드의 갯수
            int aver = K/i;
            if(i % 2 == 0) {
                int aver2 = aver*2 + 1;
                int nop = i/2;
                if(nop <= aver - 1 && nop < K + 1 - aver && nop * aver2 == K) {
                    printf("Gazua\n");
                    break;
                }
            } else {
                int aver2 = aver*2;
                int nop = i/2;
                if(nop <= aver - 1 && nop < K - aver && nop * aver2 == K - aver) {
                    printf("Gazua\n");
                    break;
                }
            }
        }
        if(i == K/2) printf("GoHanGang\n");
    }
    return 0;
}


// int main(int argc, char const *argv[])
// {
//     int N;
//     scanf("%d", &N);
//     while(N--) {
//         int K, i;
//         scanf("%d", &K);
//         for(i = 2; i <= K/2; i++) {// 카드의 갯수
//             if(i%2 == 0) {
//                 // K % i == 0이라면,
//                 // 카드의 평균이 K/i가 된다. 하지만, 카드 갯수는 짝수개이므로,
//                 // 연속된 카드들의 합은 홀수가 되어야 한다.
//                 if(K%i == 0) continue; 
//                 else {
//                     printf("카드 갯수 : %d 평균 : %d\n", i, K/i);
//                     printf("Gazua\n");
//                 }
//             } else {
//                 // 카드 갯수가 홀수라면, 나누어 떨어져야한다. 

//                 if(K%i == 0) {
//                     printf("카드 갯수 : %d 평균 : %d\n", i, K/i);
//                     printf("Gazua\n");
//                 } else continue;
//                 }
//         }
//         if(i == K/2) printf("GoHanGang\n");
//     }
//     return 0;
// }
