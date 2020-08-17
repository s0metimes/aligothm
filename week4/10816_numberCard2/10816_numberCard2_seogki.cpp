#include<algorithm>
#include<iostream>
using namespace std;
int N, M, TMP;
int A[500001];

// int binarySearch(int n){
//     int st = 0;
//     int end = N - 1;
//     while( st <= end){
//         int mid = (st + end) / 2 ;
//         if (n == A[mid]){ // 찾음
//             return mid;
//         }
//         else if(n < A[mid])
//             end = mid - 1;
//         else 
//             st = mid + 1;
//     } 
//     return -1; //못찾음..
// }

int main(){
    scanf("%d", &N);
    for(int i = 0 ; i< N;i++)
        scanf("%d", &A[i]);
    sort(A, A+N); // 정렬

    scanf("%d",&M);
    for(int i = 0;  i < M;i++){
        scanf("%d",&TMP);
        int low = lower_bound(A, A + N, TMP) - A + 1;
        int high = lower_bound(A, A + N, TMP + 1) - A + 1;
        printf("%d\n", high - low);
    }
}