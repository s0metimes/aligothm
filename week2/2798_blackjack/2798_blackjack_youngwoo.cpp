#include <stdio.h>

#define MAX 100

int m[MAX+1];

int main(int argc, char const *argv[])
{
    int i, j, k; // for loop
    int N, M;
    int near = 0;
    int sum;
    scanf("%d %d", &N, &M);

    for(i = 0; i <N; i++) 
        scanf("%d", &m[i]);

    for(i = 0; i < N; i++) {
        for(j = i+1;  j < N; j++) {
            for(k = j+1; k < N; k++) {
                sum = m[i] + m[j] + m[k];
                if(sum > M) continue;
                if(sum > near) near = sum;
            }
        }
    }
    printf("%d\n", near);
    return 0;
}
