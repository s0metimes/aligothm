#include<stdio.h>

#define MAXN 100
#define MAXM 300000
#define MAXCARD 100000

int max;

void maxSum(int cards[MAXN], int N, int M, int chosen[3], int size) {
    bool pass = false;

    int sum, i, j, newSize;

    for(i = 0; i < N; i++) {
        pass = false;
        newSize = size;
        for(j = 0; j < newSize; j++) {
            if(chosen[j] == cards[i])
                pass = true;  
        }

        if(pass) {
            continue;
        }
        chosen[newSize++] = cards[i];
        if(newSize == 3) {
            sum = 0;
            for(j = 0; j < newSize; j++) {
                sum += chosen[j];
            }

            if(max <= sum && sum <= M)
                max = sum;
        }
        else
            maxSum(cards, N, M, chosen, newSize);
    }
}

int main(int argc, char **argv) {
    int n, N, M, cards[MAXN], chosen[3];
    
    scanf("%d %d", &N, &M);

    for(n = 0; n < N; n++) {
        scanf("%d", &cards[n]);
    }

    maxSum(cards, N, M, chosen, 0);

    printf("%d\n", max);

    return 0;
}