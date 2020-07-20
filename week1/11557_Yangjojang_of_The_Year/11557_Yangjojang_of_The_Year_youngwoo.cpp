#include <stdio.h>
#include <string>

using namespace std;

#define MAX 100

char uni[MAX+1][20];
int drinks[MAX];

int main(int argc, char const *argv[])
{
    int t, num, drink, i;

    scanf("%d", &t);

    for(;t > 0; t--) {
        scanf("%d", &num);
        for(i = 0; i < num; i++) {
            scanf("%s %d", uni[i], &drinks[i]);
        }
        int max = 0;
        for(i = 1; i < num; i++) {
            if(drinks[i] > drinks[max]) max = i;
        }
        printf("%s\n", uni[max]);
    }
    return 0;
}

