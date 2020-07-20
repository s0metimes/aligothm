#include <stdio.h>

#define MAX 10

int f[MAX+1];


int main(int argc, char const *argv[])
{
    int time,num, i, j;
    int max = 0;
    scanf("%d", &time);

    f[0] = 0;
    f[1] = 1;
    f[2] = 2;
    f[3] = 4;
    f[4] = 7;

    for(i = 0; i < time; i++) {
        scanf("%d", &num);
        for(j = 5; j <= num; j++) 
            f[j] = f[j-1] + f[j-2] +f[j-3]; 
        printf("%d\n",f[num]);
    }
    return 0;
}
