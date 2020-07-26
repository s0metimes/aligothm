#include <stdio.h>
#include <algorithm>
#include <queue>

#define MAX 50

using namespace std;

int A[MAX+1];
priority_queue<int, vector<int> > B;
int minV;

int main(int argc, char const *argv[])
{
    int n, i, num;
    scanf("%d", &n);

    for(i =0; i < n; i++) 
        scanf("%d", &A[i]);

    for(i =0; i < n; i++) {
        scanf("%d", &num);
        B.push(num);
    }

    sort(A, A+n);
    
    for(i = 0; i < n; i++) {
        minV += A[i]*B.top();
        B.pop();
    }
    
    printf("%d\n", minV);
    return 0;
}

//-------------------------------------

// #include <stdio.h>
// #include <algorithm>
// #include <queue>

// #define MAX 50

// using namespace std;

// int A[MAX+1];
// int B[MAX+1];
// int minV;

// int findMax(int n);

// int main(int argc, char const *argv[])
// {
//     int n, i, num;
//     scanf("%d", &n);

//     for(i =0; i < n; i++) 
//         scanf("%d", &A[i]);

//     for(i =0; i < n; i++) {
//         scanf("%d", &num);
//         B.push(num);
//     }

//     sort(A, A+n);
    
//     for(i = 0; i < n; i++) {
//         int idx = findMax(n);
//         minV += A[i]*B[idx];
//         B[idx] = 0;
//     }
    
//     printf("%d\n", minV);
//     return 0;
// }

// int findMax(int n) {
//     int i, maxV = 0;
//     for(i = 0; i < n; i++) 
//         if(B[maxV] < B[i]) maxV = i;
//     return maxV;
// }

//-------------------------------------


// #include <stdio.h>
// #include <algorithm>
// #define MAX 50

// using namespace std;

// int A[MAX+1];
// int B[MAX+1];
// int minV;

// int main(int argc, char const *argv[])
// {
//     /* code */
//     int n, i;
//     scanf("%d", &n);

//     for(i =0; i < n; i++) 
//         scanf("%d", &A[i]);

//     for(i =0; i < n; i++) 
//         scanf("%d", &B[i]);

//     sort(A, A+n);
//     sort(B, B+n);
    
//     for(i = 0; i < n; i++) 
//         minV += A[i]*B[n-i-1];
    
//     printf("%d\n", minV);
//     return 0;
// }

// #include <stdio.h>
// #include <algorithm>
// #define MAX 50

// int A[MAX+1];
// int B[MAX+1];
// int AmB[MAX+1];
// int min;

// void perm(int* list, int i, int n);
// void swap(int* a, int* b);

// int main(int argc, char const *argv[])
// {
//     /* code */
//     int n, i;
//     scanf("%d", &n);

//     for(i =0; i < n; i++) 
//         scanf("%d", &A[i]);

//     for(i =0; i < n; i++) 
//         scanf("%d", &B[i]);
    
//     for(i = 0; i < n; i++) 
//         min += A[i]*B[i];

//     perm(A, 0, n-1);
//     printf("%d\n", min);
//     return 0;
// }

// void perm(int* list, int i, int n) {
//     int j, temp;
//     if(i == n) {
//         int sum = 0;
//         for(i = 0; i <= n; i++)
//             sum += list[i]*B[i];
//         if(min > sum) min = sum;
//     } else {
//         for(j = i; j <= n; j++) {
//             swap(&list[i], &list[j]);
//             perm(list, i+1, n);
//             swap(&list[i], &list[j]);
//         }
//     }
// }

// void swap(int* a, int* b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }