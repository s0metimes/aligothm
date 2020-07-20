#include <stdio.h>
#define MAX 2187
char stars[2187+1][2187+1];

void fractal(int px, int py, int sz);

int main(int argc, char const *argv[])
{
    int n, i, j;
    scanf("%d", &n);

    fractal(0,0,n);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(stars[i][j] == 0) printf(" ");
            else printf("%c", stars[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void fractal(int px, int py, int sz) {
    if(sz == 1) {
        stars[px][py] = '*';
        return ;
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i != 1|| j != 1) 
                fractal(px+(sz/3*i), py+(sz/3*j), sz/3);
        }
    }
}
