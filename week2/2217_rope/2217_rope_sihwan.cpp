#include<stdio.h>
#include<algorithm>

using namespace std;

#define MAXN 100000
#define MAXW 10000

int main(int argc, char **argv) {
    int n, N, wOfRope[MAXN], max, i;

    scanf("%d", &N);

    for(n = 0; n < N; n++) {
        scanf("%d", &wOfRope[n]);
    }

    sort(wOfRope, wOfRope + N);
    
    max = 0;
    for(n = N-1; n >= 0; n--) {
        i = N-1-n;
        if(max < (i+1)*wOfRope[n])
            max = (i+1)*wOfRope[n];
    }

    printf("%d\n", max);

    return 0;
}