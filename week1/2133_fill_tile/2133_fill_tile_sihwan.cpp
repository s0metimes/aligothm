#include<stdio.h>

#define MAX 30

int main(int argc, char **argv) {
    // f(n-4)+ 2 + f(n-2) + 3
    int n, N, m;
    long long int arr[MAX+1];
    
    scanf("%d", &N);
    
    for(n = 0; n <= N; n++) {
        if(n == 0)
            arr[n] = 1;
        else if(n == 2)
            arr[n] = 3;
        else if(n % 2 == 1)
            arr[n] = 0;
        else {
            arr[n] = arr[n-2] * 3;
            for(m = n-4; m >= 0; m -= 2) {
                arr[n] = arr[n] + (arr[m] * 2);
            }
        }
    }

    printf("%lld\n", arr[N]);

    return 0;
}
