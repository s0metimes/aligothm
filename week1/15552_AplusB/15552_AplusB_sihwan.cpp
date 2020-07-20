#include<stdio.h>

int main(int argc, char **argv) {
    int t, T, A, B;
    
    scanf("%d", &T);

    for(t = 0; t < T; t++) {
        scanf("%d %d", &A, &B);
        printf("%d\n", A+B);
    }
    return 0;
}