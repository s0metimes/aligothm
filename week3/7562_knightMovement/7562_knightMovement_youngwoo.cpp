#include <stdio.h>
#include <cstring>
#include <queue>
#include <utility>

#define MAX 300
using namespace std;

int dis[MAX+2][MAX+2];

int dx[8] = {-2,-1, 1, 2, 2, 1,-1,-2};  
int dy[8] = {-1,-2,-2,-1, 1, 2, 2, 1}; 

int len = 0;

bool isInside(int cur_x, int cur_y) {
    return (cur_x >= 0) && (cur_x < len) && (cur_y >= 0) && (cur_y < len);
}

int bfs(int init_x, int init_y, int tar_x, int tar_y) {
    queue<pair<int, int> > q;
    q.push(make_pair(init_x,init_y)); // init_x, init_y에서 미로탐색 시작 
    while(!q.empty()) {
        int size = q.size(); // q의 값 = 현재 연결된 정점 갯수
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        if(cur_x == tar_x && cur_y == tar_y) break;

        for(int j = 0; j < 8; j++) { // 8방향 
            int next_x = cur_x + dx[j];
            int next_y = cur_y + dy[j];
            
            if(isInside(next_x, next_y) && dis[next_x][next_y] == 0) {
                q.push(make_pair(next_x,next_y));
                dis[next_x][next_y] = dis[cur_x][cur_y] + 1;
                // for(int ii = 0; ii < len; ii++) {
                //     for(int jj = 0; jj< len; jj++) 
                //         printf("%2d", dis[ii][jj]);
                //     printf("\n");
                // }
                // printf("\n");
            }
        }
        
    }
    return dis[tar_x][tar_y];
}

int main(int argc, char const *argv[])
{
    int tCase, init_x, init_y, tar_x, tar_y;

    scanf("%d", &tCase);
    while(tCase--) {
        scanf("%d", &len);
        memset(dis, 0, sizeof(dis));
        scanf("%d %d %d %d", &init_x, &init_y, &tar_x, &tar_y); 
        printf("%d\n", bfs(init_x, init_y, tar_x, tar_y));
    }
    
    return 0;
}

