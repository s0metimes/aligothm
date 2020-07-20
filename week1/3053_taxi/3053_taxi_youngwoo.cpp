#define USE_MATH_DEFINES
#include <stdio.h>
#include <cmath>

int main(int argc, char const *argv[])
{
    int r;
    scanf("%d", &r);
    printf("%f\n%f\n",r*r*M_PI, r*r*2.0);
    return 0;
}

// 6자리 까지 출력하려면 %.6f를 사용해야한다.
