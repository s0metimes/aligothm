#include<stdio.h>

#define MAX 11

int allcases[MAX+1];

int main(int argc, char **argv) {
    int t, T, i, input;
    
    for(i = 0; i <= MAX; i++) {
        if(i == 0)
            allcases[i] = 0;
        else if(i == 1)
            allcases[i] = 1;
        else if(i == 2)
            allcases[i] = 2;
        else if(i == 3)
            allcases[i] = 4;
        else
            allcases[i] = allcases[i-1] + allcases[i-2] + allcases[i-3];
    }

    scanf("%d", &T);

    for(t = 0; t < T; t++) {
        scanf("%d", &input);
        printf("%d\n", allcases[input]);
    }
    return 0;
}