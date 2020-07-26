#include <stdio.h>
#define MAX 20

#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4

int m[MAX+1][MAX+1];
void moveOneDir(int dir, int N);
void getMax(int N);
void printM(int N);
int maxV;

int main(int argc, char const *argv[])
{
    int N, i, j, a, b, c, d, e;
    scanf("%d", &N);

    for(i = 1; i <= N; i++)
        for(j = 1; j <= N; j++)
            scanf("%d", &m[i][j]);

    for(a = 1; a <= 4; a++) {
        moveOneDir(a, N);
        for(b = 1; b <= 4; b++) {
            moveOneDir(b, N);
            for(c = 1; c <= 4; c++) {
                moveOneDir(c, N);
                for(d = 1; d <= 4; d++) {
                    moveOneDir(d, N);
                    for(e = 1; e <= 4; e++) {
                        moveOneDir(e, N);
                        int bef = maxV;
                        getMax(N);
                        if(bef != maxV) 
                            printM(N);
                    }
                }
            }
        }
    }
    printf("%d\n", maxV);
    return 0;
}

void moveOneDir(int dir, int N) {
    int i, j;
    for(i = 1; i <= N; i++) {
        for(j = 1; j <= N; j++) {
            if(dir == LEFT) {
                for(int k = 1; j+k <= N; k++) {
                    if(m[i][j+k] == 0) continue;
                    if(m[i][j] == m[i][j+k]) {
                        m[i][j] *= 2;
                        m[i][j+1] = 0;
                        j += k;
                        break;
                    }
                }
            } else if(dir == RIGHT) {
                if(m[i][N-j+1] == m[i][N-j]) {
                    m[N-j+1][i] *= 2;
                    m[N-j][i] = 0;
                    j++;
                }
            } else if(dir == UP) {
                if(m[j][i] == m[j+1][i]) {
                    m[j][i] *= 2;
                    m[j+1][i] = 0;
                    j++;
                }
            } else if(dir == DOWN) {
                if(m[N-j+1][i] == m[N-j][i]) {
                    m[N-j+1][i] *= 2;
                    m[N-j][i] = 0;
                    j++;
                }                
            }
        } 
    }
}

void getMax(int N) {
    int i, j;
    for(i = 1; i <= N; i++) {
        for(j = 1; j <= N; j++) {
            if(maxV < m[i][j]) {
                maxV = m[i][j];
            }
        }            
    }
}

void printM(int N) {
    int i, j;
    for(i = 1; i <= N; i++) {
        for(j = 1; j <= N; j++) {
            printf("%4d", m[i][j]);
        }            
        printf("\n");
    }
}