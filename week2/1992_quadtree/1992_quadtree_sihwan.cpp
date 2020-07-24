#include<stdio.h>

#define MAX 64

void compress(int arr[MAX][MAX], int i, int j, int x, int y) {
    int n, m, halfx, halfy;
    bool canBeCompressed;
    
    if(i > x && j > y) {
        printf("sth wrong\n");
        return;
    }

    canBeCompressed = true;
    for(n = i; n < x; n++) {
        for(m = j; m < y; m++) {
            if(arr[n][m] != arr[i][j])
                canBeCompressed = false;
        }
    }
    
    if(canBeCompressed)
        printf("%d", arr[i][j]);
    else {
        halfx = (i+x)/2;
        halfy = (j+y)/2;
        printf("(");
        compress(arr, i, j, halfx, halfy);
        compress(arr, i, halfy, halfx, y);
        compress(arr, halfx, j, x, halfy);
        compress(arr, halfx, halfy, x, y);
        printf(")");
    }
    
} 

void clear(void) {    
  while ( getchar() != '\n' );
}

int main(int argc, char **argv) {
    int i, j, N, arr[MAX][MAX];
    
    scanf("%d", &N);
    clear();

    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }

    compress(arr, 0, 0, N, N);
    printf("\n");

    return 0;
}