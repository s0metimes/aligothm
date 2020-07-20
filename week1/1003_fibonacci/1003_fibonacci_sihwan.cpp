#include<stdio.h>

#define MAX 40

int numOfZero[MAX+1];
int numOfOne[MAX+1];

int main(int argc, char **argv) {
    int t, T, input;
    
    for(int i = 0; i <= MAX; i++) {
        if(i == 0)
            numOfZero[i]++;
        else if(i == 1)
            numOfOne[i]++;            
        else {
                numOfZero[i] = numOfZero[i - 1] + numOfZero[i - 2];
                numOfOne[i] = numOfOne[i - 1] + numOfOne[i - 2];
        }
            
    }

    scanf("%d", &T);
    


    for(t = 0; t < T; t++) {
        scanf("%d", &input);

        printf("%d %d\n", numOfZero[input], numOfOne[input]);
    }

    return 0;
}