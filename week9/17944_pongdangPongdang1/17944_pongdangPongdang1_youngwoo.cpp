#include <stdio.h>

int main(int argc, char const *argv[])
{
    int N, T;
    
    scanf("%d %d", &N, &T);
    int mod = T % (2*((2*N)-1));
    if(mod == 0) mod = 2;
    else if(mod > 2*N) mod = 4*N - mod;
    printf("%d\n", mod);
    return 0;
}
