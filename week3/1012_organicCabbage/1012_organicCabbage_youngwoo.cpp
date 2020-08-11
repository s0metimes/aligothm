#include <stdio.h>
#define MAX 50

int g[MAX+1][MAX+1];
int d[4][2] = {{-1,0}, {0,-1}, {1,0}, {0,1}}; // ^ < v >

int cnt = 0;    // 출력값 
int height, width;

bool isInside(int cur_h, int cur_w);
void dfs(int cur_h, int cur_w);

int main(int argc, char const *argv[])
{
    int tCase, numOfCab;

    scanf("%d", &tCase);

    while(tCase--) {
        scanf("%d %d %d", &width, &height, &numOfCab);
        while(numOfCab--) { //  cabbage 위치 입력
            int w, h;
            scanf("%d %d", &w, &h);
            g[h][w] = 1;
        }

        for(int h = 0; h < height; h++) {   // 모든 좌표에서 dfs 
            for(int w = 0; w < width; w++) {
                if(g[h][w] == 1) cnt++;
                dfs(h, w);
            }
        }
        printf("%d\n", cnt);
        cnt = 0;
    }

}

void dfs(int cur_h, int cur_w) {
    if(g[cur_h][cur_w] != 1) return;    // 이미 지나왔거나 또는 없거나 체크 
    
    g[cur_h][cur_w]++;  // 이미 지나온곳은 2의 값을 가진다.

    for(int dir = 0; dir < 4; dir++) {
        int next_h = cur_h + d[dir][0];
        int next_w = cur_w + d[dir][1];
        if(isInside(next_h, next_w) && g[next_h][next_w] == 1) // 벗어나는지 체크 && 이미 지나온곳인지 체크
            dfs(next_h, next_w);
    }
}

bool isInside(int cur_h, int cur_w) {
    return (cur_h >= 0) && (cur_h < height) && (cur_w >= 0) && (cur_w < width);
}