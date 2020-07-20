#include<stdio.h>

#define MAX 1000

void swap(int *arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int main(int argc, char **argv) {
    int n, N, arr[MAX], m;
    
    scanf("%d", &N);
    
    for(n = 0; n < N; n++) {
        scanf("%d", &arr[n]);
    }

    for(m = 0; m < N; m++) {
        for(n = m+1; n < N; n++) {
            if(arr[m] > arr[n])
                swap(arr, m, n);
        }
    }

    for(n = 0; n < N; n++)
        printf("%d\n", arr[n]);
    return 0;
}