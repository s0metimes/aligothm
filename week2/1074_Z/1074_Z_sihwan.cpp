#include<stdio.h>

int cnt = 0;

void zExplore(int r, int c, int i, int j, int x, int y) {
    int halfx, halfy, cntOfPart;

    if(i==x && j==y) {
        if (r == x && c == y) {
            printf("%d\n", cnt);
        }
        cnt++;
    }
    else {
        halfx = (i + x - 1) / 2;
        halfy = (j + y-1) / 2;
        cntOfPart = (halfx-i+1)*(halfy-j+1);
        
        if(i <= r && r <= halfx) {
            if(j <= c && c <= halfy) {
                zExplore(r, c, i, j, halfx, halfy);
            }
            else {
                cnt += cntOfPart;
                zExplore(r, c, i, halfy + 1, halfx, y);
            }
        }
        else {
            if (j <= c && c <= halfy) {
                cnt += cntOfPart*2;
                zExplore(r, c, halfx + 1, j, x, halfy);
            }
            else {
                cnt += cntOfPart*3;
                zExplore(r, c, halfx + 1, halfy + 1, x, y);
            }
        }
    }
}

int power(int N) {
    int result = 1;
    for(int i = 0; i < N; i++)
        result *= 2;
    return result;
}

int main(int argc, char **argv) {
    int N, r, c;

    scanf("%d %d %d", &N, &r, &c);

    zExplore(r,c,0,0,power(N)-1,power(N)-1);

    return 0;
}