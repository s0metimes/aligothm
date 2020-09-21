#include <stdio.h>
#define MAX 1000000
bool isTicketRemain[MAX];
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    while(n--) {
        int idx;
        scanf("%d", &idx);
        isTicketRemain[idx-1] = true;
    }

    for(int i = 0; i < MAX; i++) {
        if(!isTicketRemain[i]) {
            printf("%d\n", i+1);
            break;
        }
    }
    return 0;
}
