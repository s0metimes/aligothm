#include <stdio.h>
#include <algorithm>
using namespace std;

int N, M, tmp;
int A[100001];

void binarySearch(int n){
    int st = 0;
    int end = N - 1;
    while( st <= end){
        int mid = (st + end) / 2 ;
        if (n == A[mid]){
            printf("1\n");
            return;
        }
        else if(n < A[mid])
            end = mid - 1;
        else 
            st = mid + 1;
    } 
    printf("0\n");
}

int main()
{
    scanf("%d",&N);
    for(int i = 0 ; i < N;i++)
        scanf("%d",&A[i]);
    scanf("%d",&M);
    sort(A, A + N);
    for(int i = 0 ; i < M ; i++){
        scanf("%d",&tmp);
        binarySearch(tmp);
    }
}