/**/

//-------------------------------------------------

#include <stdio.h>
#define MAX 500

int ground[MAX+1][MAX+1];

int main(int argc, char const *argv[])
{
    int n, m, have, i, j;
    int exist = 0;
    scanf("%d %d %d", &n, &m, &have);
    
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &ground[i][j]);
            exist += ground[i][j];
        }
    }
    int aver = (exist+have) / (n*m) > 256 ? 256 : (exist+have) / (n*m);
    int h = 0;
    int minT = 256*500*500;
    for(int height = aver; height >= 0; height--) {
        int sum = 0;
        for(i = 0; i < n; i++)
            for(j = 0; j < m; j++) 
                sum += (ground[i][j]-height) > 0 ? 2*(ground[i][j]-height) : height-ground[i][j];
        if(minT > sum) {
            minT = sum;
            h = height;
        }
    }
    printf("%d %d", minT, h);
    return 0;
}
//-------------------------------------------------
// #include <stdio.h>
// #define MAX 500

// int ground[MAX+1][MAX+1];

// int main(int argc, char const *argv[])
// {
//     int n, m, have, i, j;
//     int exist = 0;
//     int num;
//     scanf("%d %d %d", &n, &m, &have);
    
//     // 쌓여있는 걸로만 sum을 구한다.  
//     for(i = 0; i < n; i++) {
//         for(j = 0; j < m; j++) {
//             scanf("%d", &ground[i][j]);
//             exist += ground[i][j];
//         }
//     }
//     int aver = (exist+have) / (n*m) > 256 ? 256 : (exist+have) / (n*m);
//     int h = 0;
//     int minT = 256*500*500;
//     for(int height = aver; height >= 0; height--) {
//         int sum = 0;
//         for(i = 0; i < n; i++) {
//             for(j = 0; j < m; j++) {
//                 sum += (ground[i][j]-height) > 0 ? 2*(ground[i][j]-height) : height-ground[i][j];
//             }
//         }
//         if(minT > sum) {
//             minT = sum;
//             h = height;
//         }
//     }
//     //exist과 have + exist 의 평균을 구한다.
//     //만약, have + exist의 평균이 256을 넘어간다면, 256으로 바꾸고, 음수가 된다면, 0으로 고정한다.
//     //for문에서 0부터 have+sum의 평균까지 for문을 돈다 (최대 256)
//         //각 좌표에서 평균값과의 편차를 구해 총 걸리는 시간을 계산한다
//     printf("%d %d", minT, h);
//     return 0;
// }
