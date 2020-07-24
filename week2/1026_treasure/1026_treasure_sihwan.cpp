#include<stdio.h>

#define MAXN 50

void swap(int *arr, int i1, int i2) {
    int tmp = arr[i1];
    arr[i1] = arr[i2];
    arr[i2] = tmp;
}

int main(int argc, char **argv) {
    int N, A[MAXN], B[MAXN], i, j, newA[MAXN], orderedB[MAXN], bIndexInOrder[MAXN], size, isViewed, S;

    scanf("%d", &N);
    
    for(i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    for(i = 0; i < N; i++) {
        scanf("%d", &B[i]);
    }

    for(i = 0; i < N; i++) {
        orderedB[i] = B[i];
    }

    for(i = 0; i < N; i++) {
        bIndexInOrder[i] = i;
    }
    
    for(i = 0; i < N; i++) {
        for(j = 0; j < i; j++) {
            if(orderedB[i] < orderedB[j]) {
                swap(orderedB, i, j);
                swap(bIndexInOrder, i, j);
            }
        }
    }

    for(i = 0; i < N; i++) {
        for(j = 0; j < i; j++) {
            if(A[i] > A[j]) {
                swap(A, i, j);
            }
        }
    }

    j = 0;
    for(i = 0; i < N; i++) {
        newA[bIndexInOrder[j++]] = A[i];
    }

    S = 0;
    for(i = 0; i < N; i++) {
        S += newA[i] * B[i];
    }

    printf("%d\n", S);

    return 0;
}