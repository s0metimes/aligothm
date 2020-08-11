#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX 100

using namespace std;

int g[MAX+1][MAX+1];
int d[4][2] = {{-1,0}, {0,-1}, {1,0}, {0,1}}; // < ^ > v

int cnt = 0;
int width, height;
int range = 0;
vector<int> r_vec;

bool isInside(int cur_w, int cur_h);
void dfs(int cur_w, int cur_h);

int main(int argc, char const *argv[])
{
    int squares;
    scanf("%d %d %d", &height, &width, &squares);

    for(int t = 0; t < squares; t++) {
        int lb_p_w, lb_p_h, rt_p_w, rt_p_h;
        scanf("%d %d %d %d", &lb_p_w, &lb_p_h, &rt_p_w, &rt_p_h);

        for(int w = lb_p_w; w < rt_p_w; w++) {
            for(int h = lb_p_h; h < rt_p_h; h++) {
                g[w][h] = -1;
            }
        }
    }

    for(int w = 0; w < width; w++) {   // 모든 좌표에서 dfs 
        for(int h = 0; h < height; h++) {
            if(g[w][h] == 0) {
                cnt++;
                dfs(w, h);
            }
            if(range != 0) r_vec.push_back(range);
            range = 0;
        }
    }

    sort(r_vec.begin(), r_vec.end());
    
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++) 
        printf("%d ", r_vec[i]);

    return 0;
}

void dfs(int cur_w, int cur_h) {
    if(g[cur_w][cur_h] != 0) return;    // 이미 지나왔거나 또는 없거나 체크 
    
    range++;
    g[cur_w][cur_h] = cnt;  // 이미 지나온곳은 cnt의 값을 가진다.

    for(int dir = 0; dir < 4; dir++) {  // < ^ > v
        int next_w = cur_w + d[dir][0];
        int next_h = cur_h + d[dir][1];
        if(isInside(next_w, next_h) && g[next_w][next_h] == 0) // 벗어나는지 체크 && 이미 지나온곳인지 체크
            dfs(next_w, next_h);
    }
}

bool isInside(int cur_w, int cur_h) {
    return (cur_w >= 0) && (cur_w < width) && (cur_h >= 0) && (cur_h < height);
}