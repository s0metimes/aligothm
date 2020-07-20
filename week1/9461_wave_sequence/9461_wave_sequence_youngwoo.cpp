#include <stdio.h>

#define MAX 100

long long int p[MAX+1];

int main(int argc, char const *argv[])
{
    /* code */
    int T, num;

    scanf("%d", &T);

    p[0] = 0;
    p[1] = p[2] = p[3] = 1;
    p[4] = p[5] = 2;
    

    for(;T > 0; T--) {
        scanf("%d", &num);
        for(int i = 6; i <= num; i++)
            p[i] = p[i-1] + p[i-5];
        printf("%lld\n", p[num]);
    }
    return 0;
}



// p1 1
// p2 1
// p3 1
// p4 p1 + p3 2
// p5 p3 2
// p6 p1 + p5 3
// p7 p2 + p6 4 
// p8 p3 + p7 5
// p9 p4 + p8 7
// p10 p5 + p9 9
// p11 p6 + p10 12
// p12 p7 + p11 16

// pn pn-5 + pn-1 if n >= 6

