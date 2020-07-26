#include <stdio.h>
#include <algorithm>
#define MAX 100000
int can[MAX+1];

using namespace std;

int main(int argc, char const *argv[])
{
    int n, i;
    int max = 0;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &can[i]);

    sort(can, can+n);

    for(i = 0; i < n; i++)
        printf("%d", &can[i]);
    
    for(i = 0; i < n; i++) {
        int num = (n-i) * can[i];
        if(num > max) max = num;
    }

    printf("%d\n", max);
    return 0;
}
