#include <stdio.h>

int main(int argc, char const *argv[])
{
    int T, a, b;
    scanf("%d", &T);

    for(; T > 0; T--) {
        scanf("%d %d", &a, &b);
        printf("%d\n", a+b);
    }
    return 0;
}
