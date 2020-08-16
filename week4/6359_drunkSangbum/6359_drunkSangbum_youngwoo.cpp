#include <stdio.h>
#define MAX 100
#define BTOINT(bool) bool ? 1: 0
bool isRoomOpen[MAX+1];

void printMap(int n) {
    for(int x = 0; x < n; x++)
        printf("%2d", BTOINT(isRoomOpen[x]));
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int testCase,n;

    scanf("%d", &testCase);
    while(testCase--) {
        scanf("%d", &n);
        int cnt = 0;

        for(int idx = 1; idx <= n; idx++)
            isRoomOpen[idx] = false;

        for(int round = 1; round <= n; round++) 
            for(int idx = 1; idx*round <= n; idx++) 
                isRoomOpen[idx*round] = !(isRoomOpen[idx*round] == true);

        for(int idx = 1; idx <= n; idx++) 
            if(isRoomOpen[idx] == true) cnt++;
        printf("%d\n", cnt);
    }
    return 0;
}