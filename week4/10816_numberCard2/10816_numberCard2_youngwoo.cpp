#include <stdio.h>
#define MAX 20000000

int count[MAX+1];

int main(int argc, char const *argv[])
{
    int N, M, i, card;
    
    scanf("%d", &N);
    for(i = 0; i < N; i++) { 
        scanf("%d", &card);
        count[card + MAX/2]++;
    }

    scanf("%d", &M);
    for(i = 0; i < M; i++) {
        scanf("%d", &card);
        printf("%d ", count[card + MAX/2]);
    }
    return 0;
}

// #include <stdio.h>
// #include <algorithm>
// #define MAX 500000

// using namespace std;

// int card[MAX+1];

// int binary_search(int value, int start, int end) {
//     int lowerB, upperB;
//     int mid;
//     bool flag = false;
//     while(start <= end) {
//         mid = (start+end)/2;
//         if(card[mid] < value) start = mid+1;
//         else if(card[mid] > value) end = mid-1;
//         else {
//             flag = true;
//             break;
//         }
//     } 
//     if(flag) {
//         lowerB = mid;
//         upperB = mid;
//         while(card[lowerB-1] == value) lowerB--;
//         while(card[upperB+1] == value) upperB++;
//         return upperB-lowerB+1;
//     } else {
//         return 0;
//     }    
// }

// int main(int argc, char const *argv[])
// {
//     int N, M, i, check;
//     scanf("%d", &N);
    
//     for(i = 0; i < N; i++) 
//         scanf("%d", &card[i]);

//     sort(card, card+N);

//     scanf("%d", &M);

//     for(i = 0; i < M; i++) {
//         scanf("%d", &check);
//         printf("%d\n", binary_search(check, 0, N-1));
//     }

//     return 0;
// }