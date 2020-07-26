#include <stdio.h>
#include <cmath>

int cnt = 0;

void fillZ(int n, int xpos, int ypos, int r, int c);

int main(int argc, char const *argv[])
{
    int n, r, c;

    scanf("%d %d %d", &n, &r, &c);
 
    fillZ(n, 0, 0, r, c);
    return 0;
}

void fillZ(int n, int xpos, int ypos, int r, int c) {
    int x, y, a, b;
    int incre = pow(2, n-1);
    for(x = xpos, a = 0; a < 2; x += incre, a+=1) {
        for(y = ypos, b = 0; b < 2; y += incre, b+=1) {
            if(x <= r && r < x+incre && y <= c && c < y+incre) {
                if(x == r && y == c) {
                    printf("%d\n", cnt);
                    return ;
                }

                if(n == 1) cnt++;
                else fillZ(n-1, x, y, r, c);
            }
            else cnt += pow(incre, 2);
        }
    }
}

// #include <stdio.h>
// #include <cmath>

// int cnt = 0;

// void fillZ(int n, int xpos, int ypos, int r, int c);

// int main(int argc, char const *argv[])
// {
//     int n, r, c;

//     scanf("%d %d %d", &n, &r, &c);
 
//     fillZ(n, 0, 0, r, c);
//     return 0;
// }

// void fillZ(int n, int xpos, int ypos, int r, int c) {
//     int x, y, a, b;
//     int incre = pow(2, n-1);
//     for(x = xpos, a = 0; a < 2; x += incre, a+=1) {
//         for(y = ypos, b = 0; b < 2; y += incre, b+=1) {
//             if(x == r && y == c) printf("%d\n", cnt);
//             if(n == 1) cnt++;
//             else fillZ(n-1, x, y, r, c);
//         }
//     }
// }

// #include <stdio.h>
// #include <cmath>
// #define MAX 15

// int Z[32768+1][32768+1]; // 2^15 = 32768
// int cnt = 0;

// void fillZ(int n, int xpos, int ypos);

// int main(int argc, char const *argv[])
// {
//     int n, r, c;
//     int i, j;

//     scanf("%d", &n);
    
//     fillZ(n, 0, 0);
    
//     for(i = 0; i < pow(2,n); i++) {
//         for(j = 0; j < pow(2,n); j++)
//             printf("%-4d", Z[i][j]);
//         printf("\n");
//     }
    
//     // scanf("%d %d", &r, &c);
//     // printf("Z[%d][%d] = %d\n", r, c, Z[r][c]);
//     return 0;
// }

// void fillZ(int n, int xpos, int ypos) {
//     if(n != 0)
//         printf("void fillZ(%d, %d, %d) is called!\n", n, xpos, ypos);
//     int x, y, a, b;
//     int incre = pow(2, n-1);
//     for(x = xpos, a = 0; a < 2; x += incre, a+=1) {
//         for(y = ypos, b = 0; b < 2; y += incre, b+=1) {
//             if(n == 1) {
//                 printf("Z[%d][%d] = %d\n", x,y,cnt);
//                 Z[x][y] = cnt++;
//             }
//             else fillZ(n-1, x, y);
//         }
//     }
// }