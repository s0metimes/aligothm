#include <stdio.h>
#define MAX 5000

int arr[MAX+1];
int main(int argc, char const *argv[])
{
    int n, k, i, j;
    
    scanf("%d %d", &n, &k);
    for(i = 1; i < n; i++) 
        arr[i] = i+1;
    arr[n] = 1;
    int next = 1;
    printf("<");
    if(k == 1) {
        for(i = 1; i < n; i++) {
            printf("%d, ", i);
        }
        printf("%d>\n", n);
        return 0;
    }
    for(i = 1; i <= n; i++) {
        for(j = 0; j < k -2; j++) 
            next = arr[next];
        if(i == n) printf("%d>", arr[next]);
        else printf("%d, ", arr[next]); 
        arr[next] = arr[arr[next]];
        next = arr[next];
    }
    /* code */
    return 0;
}


// #include <stdio.h>
// #define MAX 5000

// typedef struct Node{
//     int num;
//     struct Node* pt;
// } Node;

// Node arr[MAX+1];
// int result[MAX+1];
// int main(int argc, char const *argv[])
// {
    // int n, k, i, j;

    // scanf("%d %d", &n, &k);
    // for(i = 1; i <= n; i++) {
    //     if(i != n) arr[i].pt = &arr[i+1];
    //     else arr[i].pt = &arr[0];
    //     arr[i].num = i;
    // }

    // Node* start = &arr[1];
    // Node* next = &arr[1];

//     for(i = 0; i < n; i++) {
//         if(i == n - 1) {
//             result[i] = start->num;
//             break;
//         }
//         for(j = 0; j < k - 2; j++)
//             next = next->pt;    
//         result[i] = next->pt->num;
//         printf("%d ", result[i]);
//         start = next->pt->pt;
//         next->pt->pt = NULL;
//         next->pt = start;
//         next = start;
//     }               
//     printf("<");
//     for(i = 0; i < n - 1; i++) 
//         printf("%d, ", result[i]);    
//     printf("%d>\n", result[n-1]);
    
//     return 0;
// }


