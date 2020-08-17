#include <stdio.h>
#include<algorithm>

#define MAX 1000000

using namespace std;

int LIS[MAX];
int lsize = 0;

int main(void)
{
    int N, n, input, *elem;
    scanf("%d", &N);

    for (n = 0; n < N; n++) {
        scanf("%d", &input);
        
        if(n == 0) LIS[lsize++] = input;
        else {
            if(input > LIS[lsize-1]) LIS[lsize++] = input;
            else {
                elem = lower_bound(LIS, LIS+lsize, input);
                *elem = input;
            }
        }
    }
    
    printf("%d\n", lsize);
    return 0;
}
