#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
#define pii pair<int, int>
#define BIT 9

int MAP[10][10][10];
int zero;

int toBinary(int x){
    return 1;
}

void solve(){
    for (int i = 1; i <= 9; i++)
            for (int j = 1; j <= 9; j++)
                if (MAP[i][j][0] == "0"){
                    for(int k =1 ;k<10;k++){
                    MAP[i][j][k] = 1 if
                    }
                    
                }

    while (zero > 0)
    {
        
    }
}

int main()
{
    // input
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
        {
            scanf("%1s", &MAP[i][j][0]);
            if (MAP[i][j][0] == "0")
                zero++;
        }

    // execute
    solve();

    // output
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            printf("%c ", MAP[i][j][0]);
        }
        printf("\n");
    }
}
