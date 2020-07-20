#include<stdio.h>

#define MAX 1000

int main(int argc, char **argv) {
    int n;
    long long int arr[MAX+1];

    scanf("%d", &n);
    
    for(int i = 0; i <= n; i++) {
        if(i == 0)
            arr[i] = 0;
        else if(i == 1)
            arr[i] = 1;
        else if(i == 2)
            arr[i] = 2;
        else
            arr[i] = (arr[i-1] + arr[i-2]) %10007;
    }

    printf("%lld\n", arr[n]);
    
    return 0;
}