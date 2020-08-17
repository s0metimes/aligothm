#include<stdio.h>

#define MAX 1000

int A[MAX];
int dp[MAX];

int main(void) {
    int N, n, i, max;
    scanf("%d", &N);

    for(n = 0; n < N; n++)
        scanf("%d", &A[n]);

    while(n--) {
        dp[n] = 1;
        max = 0;
        for(i = n+1; i < N; i++)
            if(A[n] < A[i] && max < dp[i]) max = dp[i];
        dp[n] += max;
    }
    
    max = 0;
    for(n = 0; n < N; n++) 
        if(max < dp[n]) max = dp[n];

    printf("%d\n", max);

    return 0;
}


/*
#include<stdio.h>
#include<utility>

using namespace std;

#define Pii pair<int, int>
#define MAX 1000
 
int A[MAX];
int AA[MAX][MAX];
int sizes[MAX];
int longest[MAX];
int longestCounts[MAX];

Pii cut(int arr1[MAX], int size1, int arr2[MAX], int size2) {
    int i, j;

    for(i = 0; i < size1; i++)
        if(arr1[i] >= arr2[0]) break;
    
    i--;

    for(j = 0; j < size2; j++) 
        if(arr2[j] > arr1[size1-1]) break;

    return make_pair(i, j);
}

void append(int arr1[MAX], int *size1, int arr2[MAX], int from, int to) {
    for(int i = from; i < to; i++) {
        arr1[*size1] = arr2[i];
        *size1 = *size1 + 1;
    }
}

void printAA(int I) {
    for(int i = 0; i < I; i++) {
        printf("%d: ", i);
        for(int j = 0; j < sizes[i]; j++)
            printf("%d ", AA[i][j]);
        printf("\n");
    }
}

void printLongest(int lSize) {
    printf("longest: ");
    for(int i = 0; i < lSize; i++)
        printf("%d ", longest[i]);
    printf("\n");
}

int main(void) {
    int N,n, num, cnt, i, I, lSize, max;

    scanf("%d", &N);
    
    for(n = 0; n < N; n++)
        scanf("%d", &A[n]);

    i = 0;
    AA[i][sizes[i]++] = A[0];
    for(n = 1; n < N; n++) {        
        if(A[n] > A[n-1])
            AA[i][sizes[i]++] = A[n];
        else {
            i += 1;
            AA[i][sizes[i]++] = A[n];
        }
    }

    I = i+1;

    printAA(I);

    for(n = 0; n < I; n++) {
        lSize = 0;
        for(i = n; i < I; i++) {
            if(i == 0)
                append(longest, &lSize, AA[i], 0, sizes[i]);
            else {
                Pii p = cut(longest, lSize, AA[i], sizes[i]);

                printf("first: %d, second: %d\n", p.first, p.second);
                
                if((p.first+1) + sizes[i] >= lSize + sizes[i] - p.second) {
                    lSize = p.first+1;
                    append(longest, &lSize, AA[i], 0, sizes[i]);
                }
                else {
                    append(longest, &lSize, AA[i], p.second, sizes[i]);
                }

                rintLongest(lSize);            
                
            }
        }
        
        longestCounts[n] = lSize;
    }

    max = 0;
    for(n = 0; n < I; n++)
        if(longestCounts[n] > max) max = longestCounts[n];


    printf("%d\n", max);

    return 0;
}
*/