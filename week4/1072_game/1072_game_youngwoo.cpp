#include <stdio.h>
#define MAX 1000000000

int main(int argc, char const *argv[])
{
    long long int X, Y;

    scanf("%lld %lld", &X, &Y);

    int Z = (100*Y)/X;

    if(Z >= 99) {
        printf("-1\n");
        return 0;
    }

    int lower = 0, upper = MAX;
    int mid;
    int tempZ;
    while(lower <= upper) {
        mid = (lower+upper)/2;
        tempZ = 100*(Y+mid)/(X+mid);
        if(tempZ > Z) upper = mid-1;
        else if(tempZ <= Z) lower = mid+1;
    }
    if(lower > MAX) printf("-1\n"); // > 대신 >= 을 쓰면 틀린다. 문제의 표현이 조금 모호하다. 
    else printf("%d\n", lower);
    return 0;
}

//  출력 문 
//  printf("l : %d m : %d u : %d tempZ : %d, Z : %d\n", lower, mid, upper, tempZ, Z);