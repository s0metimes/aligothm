#include <stdio.h>
#include <math.h>
#define MAX 1000000007
int main(int argc, char const *argv[])
{
    long long h, x, sum = 0;
    
    scanf("%lld %lld", &h, &x);
    long long numOfSnow, multi = 1;
    for(int i = 1; i <= h; i++) {
        multi *= x;
        multi %= MAX;
        scanf("%lld", &numOfSnow);
        sum += numOfSnow * multi;
        sum %= MAX;
    }
    printf("%lld\n", sum);
    return 0;
}
