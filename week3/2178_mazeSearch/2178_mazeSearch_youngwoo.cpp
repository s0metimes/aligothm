#include <stdio.h>
#include <cstring>
#include <queue>
#include <utility>

#define MAX 100
using namespace std;

queue<pair<int, int> > q;

bool visit[MAX+2][MAX+2];
int MAP[MAX+2][MAX+2];
int dis[MAX+2][MAX+2];

int dx[4] = {0,0,-1,1};  // ^ v < >
int dy[4] = {-1,1,0,0};  // ^ v < >

int raw, col;

int bfs() {
    q.push(make_pair(1,1)); // 1, 1에서 미로탐색 시작 
    dis[1][1] = 1;
    while(!q.empty()) {
        int size = q.size(); // q의 값 = 현재 연결된 정점 갯수
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        visit[x][y] = true; // visit 표시

        if(x == raw && y == col) break;

        for(int i = 0; i < size; i++) {
            for(int j = 0; j < 4; j++) { // 상하좌우 
                int nx = x + dx[j];
                int ny = y + dy[j];
                // if(nx == 0 || nx == raw+1 || ny == 0 || ny == col+1) continue;
                if(MAP[nx][ny] != -1  && !visit[nx][ny] && MAP[nx][ny] == 1) {
                    q.push(make_pair(nx,ny));
                    dis[nx][ny] = dis[x][y] + 1;
                    visit[nx][ny] = true;
                }
            }
        }
    }
    return dis[raw][col];
}

int main(int argc, char const *argv[])
{
    char str[MAX+1];

    memset(MAP, -1, sizeof(MAP));   // -1로 배열 초기화
    scanf("%d %d", &raw, &col);

    for(int i = 1; i <= raw; i++) {
        scanf("%s", str);
        for(int j = 1; j<= col; j++) {
            MAP[i][j] = str[j-1] - 48;
        }
    }

    printf("%d\n", bfs());
    return 0;
}

// #include <stdio.h>
// #include <string>
// #include <queue>
// #include <vector>
// #include <utility>


// #define MAX 100
// #define INF MAX*MAX
// using namespace std;

// queue<pair<int, int> > q;
// bool visit[MAX+1][MAX+1];
// int MAP[MAX+1][MAX+1];
// int dis[MAX+1][MAX+1];

// int dx[4] = {0,0,-1,1};  // ^ v < >
// int dy[4] = {-1,1,0,0};  // ^ v < >

// int raw, col;

// int bfs() {
//     q.push(make_pair(1,1)); // 1, 1에서 미로탐색 시작 
//     dis[1][1] = 1;
//     while(!q.empty()) {
//         int size = q.size(); // q의 값 = 현재 연결된 정점 갯수
//         int x = q.front().first;
//         int y = q.front().second;
//         q.pop();
//         visit[x][y] = true; // visit 표시
//         if(x == raw && y == col) break;

//         for(int i = 0; i < size; i++) {
//             for(int j = 0; j < 4; j++) { // 상하좌우 
//                 int nx = x + dx[j];
//                 int ny = y + dy[j];
                
//                 // if(nx == 0 || nx == raw+1 || ny == 0 || ny == col+1) continue;
//                 if(MAP[nx][ny] != -1  && !visit[nx][ny] && MAP[nx][ny] == 1) {
//                     q.push(make_pair(nx,ny));
//                     dis[nx][ny] = dis[x][y] + 1;
//                     visit[nx][ny] = true;
//                 }
//             }
//         }
//     }

//     for(int i = 1; i <= raw; i++) {
//         for(int j = 1; j<= col; j++) 
//             printf("%3d", dis[i][j]);
//         printf("\n");
//     }
//     return dis[raw][col];
// }

// int main(int argc, char const *argv[])
// {
//     char str[MAX+1];
//     memset(visit, false, sizeof(visit));
//     memset(MAP, -1, sizeof(MAP));   // -1로 배열 초기화
//     memset(dis, 0, sizeof(dis));
//     scanf("%d %d", &raw, &col);

//     for(int i = 1; i <= raw; i++) {
//         scanf("%s", str);
//         for(int j = 1; j<= col; j++) {
//             MAP[i][j] = str[j-1] - 48;
//         }
//     }

//     for(int i = 1; i <= raw; i++) {
//         for(int j = 1; j<= col; j++) 
//             printf("%2d", MAP[i][j]);
//         printf("\n");
//     }

//     printf("%d\n", bfs());
//     return 0;
// }




// #include <stdio.h>
// #include <string>
// #define MAX 100
// #define MAZE(i,j) maze[i][j]
 
// using namespace std;

// int maze[MAX+1][MAX+1];
// int minRoute = (MAX+1)*(MAX+1);
// int raw, col;

// void move(int xpos, int ypos, int temp);

// int main(int argc, char const *argv[])
// {
//     char str[MAX+2];
//     scanf("%d %d", &raw, &col);

//     for(int i = 1; i <= raw; i++) {
//         scanf("%s", str);
//         for(int j = 1; j<= col; j++)
//             maze[i][j] = str[j-1] - 48;
//     }

//     int xpos = 1, ypos = 1;
    
//     move(xpos, ypos, 0);

//     printf("%d\n",minRoute);
//     return 0;
// }

// void move(int xpos, int ypos, int temp) {
//     if(minRoute < temp) return;
//     temp++;
//     if(xpos == raw && ypos == col) {
//         if(minRoute > temp) minRoute = temp;
//         return;
//     }
//     MAZE(xpos, ypos) = 0;
//     if(MAZE(xpos-1, ypos) == 1 && xpos-1 > 0) move(xpos-1, ypos, temp);

//     if(MAZE(xpos, ypos+1) == 1 && ypos+1 <= col) move(xpos, ypos+1, temp);

//     if(MAZE(xpos, ypos-1) == 1 && ypos-1 > 0) move(xpos, ypos-1, temp);

//     if(MAZE(xpos+1, ypos) == 1 && xpos+1 <= raw) move(xpos+1, ypos, temp);
//     MAZE(xpos, ypos) = 1;
// }

// #include <iostream>
// #include <string>
// #define MAX 100
// #define MAZE(i,j) maze[i][j]
 
// using namespace std;

// int maze[MAX+1][MAX+1];
// int minRoute = (MAX+1)*(MAX+1);
// int raw, col;  // 전역으로 설정하지않으면 파라미터로 계속 넘겨줘야해서 귀찮... 

// void move(int xpos, int ypos, int temp);

// void printMaze(int xpos, int ypos) {
//     for(int i = 1; i <= raw; i++) {
//         for(int j = 1; j <= col; j++) {
//             if(i == xpos && j == ypos) printf("*");
//             else printf("%d", MAZE(i,j));
//         }
//         printf("\n");
//     }
// }

// int main(int argc, char const *argv[])
// {
//     string str;
//     cin>>raw>>col;

//     for(int i = 1; i <= raw; i++) {
//         cin>>str;
//         for(int j = 1; j<= col; j++)
//             maze[i][j] = str[j-1] - 48;
//     }

//     int xpos = 1, ypos = 1;  // now index;
    
//     move(xpos, ypos, 0);

//     cout<<minRoute<<endl;
//     return 0;
// }

// void move(int xpos, int ypos, int temp) {
//     if(minRoute < temp) return;
//     printf("move(%d, %d) called\n", xpos, ypos);
//     printMaze(xpos, ypos);
//     temp++;
//     printf("temp : %d\n", temp);
//     if(xpos == raw && ypos == col) {
//         if(minRoute > temp) minRoute = temp;
//         return;
//     }
//     MAZE(xpos, ypos) = 0;
//     if(MAZE(xpos-1, ypos) == 1 && xpos-1 > 0) move(xpos-1, ypos, temp);
    
//     if(MAZE(xpos, ypos+1) == 1 && ypos+1 <= col) move(xpos, ypos+1, temp);

//     if(MAZE(xpos, ypos-1) == 1 && ypos-1 > 0) move(xpos, ypos-1, temp);

//     if(MAZE(xpos+1, ypos) == 1 && xpos+1 <= raw) move(xpos+1, ypos, temp);
//     MAZE(xpos, ypos) = 1;
// }



//---------------------------------------


// #include <iostream>
// #include <string>
// #define MAX 100
// #define MAZE(i,j) maze[i][j]
// #define DIR(i,j) dir[i][j]
// #define X 0
// #define Y 1

// using namespace std;

// int maze[MAX+1][MAX+1];
// int minRoute = (MAX+1)*(MAX+1);
// int temp = 1;
// //raw = n, col = m
// int raw, col;  // 전역으로 설정하지않으면 파라미터로 계속 넘겨줘야해서 귀찮... 

// void move(int xpos, int ypos);
// int search(int xpos , int ypos, int (*dir)[2]);
// void printMaze(int xpos, int ypos);

// int main(int argc, char const *argv[])
// {
//     string str;
//     cin>>raw>>col;

//     for(int i = 1; i <= raw; i++) {
//         cin>>str;
//         for(int j = 1; j<= col; j++)
//             maze[i][j] = str[j-1] - 48;
//     }

//     int nxpos = 1, nypos = 1;  // now index;
    
//     move(nxpos, nypos);

//     cout<<minRoute<<endl;
//     return 0;
// }

// //파라미터로 받은 현재 위치에서 search한후, 갈수 있는 곳으로 이동
// void move(int xpos, int ypos) {
//     if(xpos == raw && ypos == col) {
//         if(minRoute > temp) minRoute = temp;
//         return;
//     }
//     int dir[4][2] = {};  // 빈 배열로 초기화 
//     int len = search(xpos, ypos, dir);
//     if(len == 0) return;
    
//     for(int i = 0; i < 4; i++) {
//         if(DIR(i,X) == -1) continue;
//         temp++;
//         MAZE(xpos, ypos) = 0;
//         move(DIR(i,X), DIR(i,Y));
//         MAZE(xpos, ypos) = 1;
//         temp--;
//     }
// }

// // M(xpos, ypos) 주변의 1의 갯수를 반환 
// // 탐색방향은 < v ^ > 순 
// // 갈 수 없으면 DIR(i,X) 에 -1 넣기
// int search(int xpos , int ypos, int (*dir)[2]) {
//     int dircnt = 0;
//     if(MAZE(xpos-1, ypos) != 1 || xpos-1 <= 0) DIR(0,X) = -1;
//     else {DIR(0,X) = xpos-1; DIR(0,Y) = ypos; dircnt++;} // <
    
//     if(MAZE(xpos, ypos+1) != 1 || ypos+1 > col) DIR(1,X) = -1;
//     else {DIR(1,X) = xpos; DIR(1,Y) = ypos+1; dircnt++;} // v
    
//     if(MAZE(xpos, ypos-1) != 1 || ypos-1 <= 0) DIR(2,X) = -1;
//     else {DIR(2,X) = xpos; DIR(2,Y) = ypos-1; dircnt++;} // ^
    
//     if(MAZE(xpos+1, ypos) != 1 || xpos+1 > raw) DIR(3,X) = -1;
//     else {DIR(3,X) = xpos+1; DIR(3,Y) = ypos; dircnt++;} // >
    
//     return dircnt;
// }


//-----------------------------------------------------------------

// #include <iostream>
// #include <string>
// #define MAX 100
// #define MAZE(i,j) maze[i][j]
// #define DIR(i,j) dir[i][j]
// #define X 0
// #define Y 1
// #define C0 48
// #define C1 49

// using namespace std;

// int maze[MAX+1][MAX+1];
// int minRoute = (MAX+1)*(MAX+1);
// int temp = 1;
// //raw = n, col = m
// int raw, col;  // 전역으로 설정하지않으면 파라미터로 계속 넘겨줘야해서 귀찮... 

// void move(int xpos, int ypos);
// int search(int xpos , int ypos, int (*dir)[2]);
// void printMaze(int xpos, int ypos);

// int main(int argc, char const *argv[])
// {
//     string str;
//     cin>>raw>>col;

//     for(int i = 1; i <= raw; i++) {
//         cin>>str;
//         for(int j = 1; j<= col; j++)
//             maze[i][j] = str[j-1] - 48;
//     }

//     int nxpos = 1, nypos = 1;  // now index;
    
//     move(nxpos, nypos);

//     cout<<minRoute<<endl;
//     return 0;
// }

// //파라미터로 받은 현재 위치에서 search한후, 갈수 있는 곳으로 이동
// void move(int xpos, int ypos) {
//     printf("move(%d, %d) called\n", xpos, ypos);
//     printMaze(xpos, ypos);

//     if(xpos == raw && ypos == col) {
//         printf("arrive at maze[%d][%d]\n", raw, col);
//         if(minRoute > temp) {minRoute =temp; printf("min : %d\n", minRoute);}
//         return;
//     }

//     int dir[4][2] = {};  // 빈 배열로 초기화 
//     int len = search(xpos, ypos, dir);
//     printf("len : %d\n", len);
    
//     if(len == 0) return;
//     else {
//         for(int i = 0; i < 4; i++) {
//             printf("%2d%2d", DIR(i,X), DIR(i,Y));
//             printf("\n");
//         }
//     }

//     for(int i = 0; i < 4; i++) {
//         if(DIR(i,X) == -1) continue;
        
//         printf("temp : %d, temp++ : %d\n", temp, temp+1);
//         temp++;
//         MAZE(xpos, ypos) = 0;
//         move(DIR(i,X), DIR(i,Y));
//         MAZE(xpos, ypos) = 1;
//         printMaze(xpos, ypos);
//         printf("temp : %d, temp-- : %d\n", temp, temp-1);
//         temp--;
//     }
// }


// int search(int xpos , int ypos, int (*dir)[2]) {
//     int dircnt = 0;
//     if(MAZE(xpos-1, ypos) != 1 || xpos-1 <= 0) DIR(0,X) = -1;
//     else {DIR(0,X) = xpos-1; DIR(0,Y) = ypos; dircnt++;} // <
    
//     if(MAZE(xpos, ypos+1) != 1 || ypos+1 > col) DIR(1,X) = -1;
//     else {DIR(1,X) = xpos; DIR(1,Y) = ypos+1; dircnt++;} // v
    
//     if(MAZE(xpos, ypos-1) != 1 || ypos-1 <= 0) DIR(2,X) = -1;
//     else {DIR(2,X) = xpos; DIR(2,Y) = ypos-1; dircnt++;} // ^
    
//     if(MAZE(xpos+1, ypos) != 1 || xpos+1 > raw) DIR(3,X) = -1;
//     else {DIR(3,X) = xpos+1; DIR(3,Y) = ypos; dircnt++;} // >
    
//     return dircnt;
// }

// void printMaze(int xpos, int ypos) {
//     for(int i = 1; i <= raw; i++) {
//         for(int j = 1; j <= col; j++) {
//             if(i == xpos && j == ypos) printf("*");
//             else printf("%d", MAZE(i,j));
//         }
//         printf("\n");
//     }
// }

// /*
// 4 6
// 1 0 1 1 1 1 
// 1 0 1 0 1 0 
// 1 0 1 0 1 1
// 1 1 1 0 1 1 
// */

// // M(xpos, ypos) 주변의 1의 갯수를 반환 
// // 탐색방향은 < v ^ > 순 
// // 갈 수 없으면 DIR(i,X) 에 -1 넣기
// // 