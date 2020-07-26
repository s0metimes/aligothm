#include <stdio.h>
#define MAX 5
#define p(n,i,j) n*i+j

int A[MAX+1][MAX+1];

int A2N[60][(MAX+1)*(MAX+1)];
int res[MAX+1][MAX+1];
int two[60];
int cnt;

void multiple(int idx, int N);
void square(int N, long long int B);
void RadixNotation(long long int B);

int main(int argc, char const *argv[])
{
    int i, j, k; // for loop
    int N;
    long long int lli;
    long long int B;

    scanf("%d %lld", &N, &B);

    for(i = 0; i < N; i++) 
        for(j = 0; j < N; j++) 
            scanf("%d", &A[i][j]);

    for(int i = 0; i < N; i++) 
        for(int j = 0; j < N; j++) 
            A2N[0][p(N,i,j)] = A[i][j];

    for(i = 0;  i < N; i++)
        res[i][i] = 1;

    RadixNotation(B);

    for(i = 0;  i < cnt; i++) {
        square(N,i);
        if(two[i] == 1)
            multiple(i, N);
    }

    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) 
            printf("%d ", res[i][j]);
        printf("\n");
    }
    
    return 0;
}

void multiple(int idx, int N) {
    int i, j, k;
    int temp[MAX+1][MAX+1];

    for(i = 0; i < N ; i++) {
        for(j = 0; j < N; j++) {
            int sum = 0;
            for(k = 0; k < N; k++) 
                sum += res[i][k] * A2N[idx][p(N,k,j)];
            temp[i][j] = sum % 1000;
        }
    }

    for(i = 0; i < N; i++) 
        for(j = 0; j < N; j++) 
           res[i][j] = temp[i][j];

}

void square(int N, long long int B) {
    int i, j, k;
    int temp[MAX+1][MAX+1];

    for(i = 0; i < N ; i++) {
        for(j = 0; j < N; j++) {
            int sum = 0;
            for(k = 0; k < N; k++) 
                sum += A2N[B][p(N,i,k)] * A2N[B][p(N,k,j)];
            temp[i][j] = sum % 1000;
        }
    }

    for(i = 0; i < N; i++) 
        for(j = 0; j < N; j++) 
            A2N[B+1][p(N,i,j)] = temp[i][j];
}

void RadixNotation(long long int B) {
    int idx = 0;
    while(B != 0) {
        two[idx++] = B % 2;
        B /= 2; 
    }
    cnt = idx;
}

// #include <stdio.h>
// #define MAX 5

// int A[MAX+1][MAX+1];

// int AN[MAX+1][MAX+1];

// void square(int N, long long int B);

// int main(int argc, char const *argv[])
// {
//     int i, j, k; // for loop
//     int N;
//     long long int lli;
//     long long int B;

//     scanf("%d %lld", &N, &B);

//     for(i = 0; i < N; i++) 
//         for(j = 0; j < N; j++) 
//             scanf("%d", &A[i][j]);

//     for(int i = 0; i < N; i++) 
//         for(int j = 0; j < N; j++) 
//             AN[i][j] = A[i][j];

//     for(lli = 2; lli <= B; lli++) 
//         square(N, lli);

//     for(i = 0; i < N; i++) {
//         for(j = 0; j < N; j++) 
//             printf("%d ", AN[i][j]);
//         printf("\n");
//     }
    
//     return 0;
// }

// void square(int N, long long int B) {
//     int i, j, k;
//     int temp[MAX+1][MAX+1];

//     for(i = 0; i < N ; i++) {
//         for(j = 0; j < N; j++) {
//             int sum = 0;
//             for(k = 0; k < N; k++) 
//                 sum += AN[i][k] * A[k][j];
//             temp[i][j] = sum % 1000;
//         }
//     }

//     for(i = 0; i < N; i++) 
//         for(j = 0; j < N; j++) 
//             AN[i][j] = temp[i][j];
// }

// #include <stdio.h>
// #define MAX 5

// int A[MAX+1][MAX+1];

// int AN[MAX+1][MAX+1];

// void square(int N, long long int B);

// int main(int argc, char const *argv[])
// {
//     int i, j, k; // for loop
//     int N;
//     long long int B;

//     scanf("%d %lld", &N, &B);
//     for(i = 0; i < N; i++) 
//         for(j = 0; j < N; j++) 
//             scanf("%d", &A[i][j]);

//     square(N, B);

//     for(i = 0; i < N; i++) {
//         for(j = 0; j < N; j++) 
//             printf("%d ", AN[i][j]);
//         printf("\n");
//     }
    
//     return 0;
// }

// void square(int N, long long int B) {
//     printf("void square(%d, %lld) called\n", N, B);
//     if(B == 1) {    
//         for(int i = 0; i < N; i++) 
//             for(int j = 0; j < N; j++) 
//                 AN[i][j] = A[i][j];
//         return;
//     }

//     square(N, B-1);
//     printf("void square(%d, %lld) recalled\n", N, B);
//     int i, j, k;
//     int temp[MAX+1][MAX+1];

//     for(i = 0; i < N; i++) {
//         for(j = 0; j < N; j++) 
//             printf("%5d ", AN[i][j]);
//         printf("\t");
//         for(j = 0; j < N; j++) 
//             printf("%5d ", A[i][j]);

//         printf("\n");
//     }

//     for(i = 0; i < N ; i++) {
//         for(j = 0; j < N; j++) {
//             int sum = 0;
//             for(k = 0; k < N; k++) {
//                 sum += AN[i][k] * A[k][j];
//                 printf("AN[%d][%d] * A[%d[%d] = %d * %d = %d\n", i, k, k, i, AN[i][k],A[k][j], AN[i][k] * A[k][j]);
//             }
//             printf("sum : %d\n", sum);
//             temp[i][j] = sum % 1000;
//             printf("temp[%d][%d] : %d\n", i, j, temp[i][j]);
//         }
//     }
//     printf("\n");

//     for(i = 0; i < N; i++) 
//         for(j = 0; j < N; j++) 
//             AN[i][j] = temp[i][j];
// }