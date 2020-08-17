#include<stdio.h>
#include<algorithm>

using namespace std;

#define MAX 100000

int A[MAX];

int hasNum(int num, int from, int to) {
    int half = (from+to)/2;
    if (to - from == 1) {
        //printf("from: %d, to: %d\n", from, to);
        if(A[from] == num || A[to] == num) return 1;
        else return 0;
    }
    else if(from >= to) return A[to] == num ? 1: 0;
    else if(A[from] == num || A[to] == num || A[half] == num) return 1;
    else if(A[half] > num) return hasNum(num, from, half);
    else if(A[half] < num) return hasNum(num, half, to);
    else {
        printf("This should not be called\n");
        return 0;
    }
}

int main(void) {
    int N, M, n, m, num;

    scanf("%d", &N);
    
    for(n = 0; n < N; n++) {
        scanf("%d", &A[n]);
    }

    sort(A, A+N);

    scanf("%d ", &M);
    
    for(m = 0; m < M; m++) {
        scanf("%d", &num);
        printf("%d\n", hasNum(num, 0, N-1));
    }

    return 0;
}