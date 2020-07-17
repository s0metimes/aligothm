#include <stdio.h>
#define MAX_N 301
#define MAX_M 301

int matrix[MAX_N][MAX_M];

int main(int argc, char const *argv[])
{
    int sn, sm, i, j; // sn이 세로, sm이 가로
    // 배열 크기 받기
    scanf("%d %d", &sn, &sm);

    // arr 입력받기 
    for(i = 1; i <= sn; i++) {
        for(j = 1; j <= sm; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int time;
    scanf("%d", &time);
    int di, dj, dx, dy;

    for(int t = 0; t < time; t++) {
        int sum = 0;
        // 계산하고자 하는 범위 받기
        scanf("%d %d %d %d", &di, &dj, &dx, &dy);
        for(i = di; i <= dx; i++) {
            for(j = dj; j <= dy; j++) {
                sum += matrix[i][j];
            } 
        }
        printf("%d\n", sum);
    }
    return 0;
}
