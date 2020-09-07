#include <stdio.h>
#define MAX 10

int price[MAX];

int main(int argc, char const *argv[])
{
    // N : 동전의 종류  (1 ≤ N ≤ 10) 
    // K : 만들어야 할 금액  (1 ≤ K ≤ 100,000,000)
    int N, K, i;
    scanf("%d %d", &N, &K);
    
    for(i = 0; i < N; i++) 
        scanf("%d", &price[i]);

    int result = 0;

    for(i = N-1; i >= 0; i--) {
        result += K/price[i];
        K %= price[i];
    }

    printf("%d\n", result);
    return 0;
}