#include <stdio.h>
#define MAX 15

int map[MAX+1];
int cnt = 0;
int N;

bool rowCheck(int cur_y,int cur_x) {
    for(int x = 0; x < N; x++) 
        if(cur_y == map[x]) return false;
    return true;
}

bool lUpCrossCheck(int cur_y, int cur_x) {
    for(int x = 0; x < N; x++) 
        if(cur_x - cur_y == x - map[x]) return false;
    return true;
}

bool rUpCrossCheck(int cur_y, int cur_x) {
    for(int x = 0; x < N; x++)
        if(cur_x + cur_y == x + map[x]) return false;
    return true;
}

void backTracking(int cur_y, int cur_x) {     
    if(cur_x == N-1) {
        cnt++;   
        return;
    }
    map[cur_x] = cur_y;
    int next_x = cur_x + 1;
    for(int next_y = 0; next_y < N; next_y++) {
        if(rowCheck(next_y, next_x) && lUpCrossCheck(next_y, next_x) && rUpCrossCheck(next_y, next_x)) 
            backTracking(next_y, next_x);
        for(int cl = next_x; cl < N; cl++) 
            map[cl] = -20;
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d", &N);    
    for(int cur_y; cur_y < N; cur_y++) {
        for(int x = 0; x < N; x++)
            map[x] = -20;
        backTracking(cur_y, 0);
    }
    printf("%d\n", cnt);
    return 0;
}




// #include <stdio.h>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// #include <cstring>

// #define MAX 15
// using namespace std;

// int map[MAX+1];
// int temp[MAX+1];
// int cnt = 0;
// int N;

// void backTracking(int cur_y, int cur_x);
// bool rowCheck(int cur_y, int cur_x);
// // bool columnCheck(int cur_y, int cur_x, int n);
// bool lUpCrossCheck(int cur_y, int cur_x);
// bool rUpCrossCheck(int cur_y, int cur_x);
// void printMap();

// int main(int argc, char const *argv[])
// {
//     scanf("%d", &N);    
//     for(int cur_y; cur_y < N; cur_y++) {
//         for(int x = 0; x < N; x++)
//             map[x] = -20;
//         backTracking(cur_y, 0);
//     }
//     printf("%d\n", cnt);
//     return 0;
// }

// void backTracking(int cur_y, int cur_x) {     
//     // printf("backTracking(%d, %d) called\n", cur_y, cur_x);
//     // printMap();
//     // 둘수 있는 지 체크 
//     // row lupCross rupCross
    
//     if(cur_x == N-1) {
//         cnt++;
//         // printf("cnt : %d\n", cnt);    
//         return;
//     }
//     map[cur_x] = cur_y;
//     // printf("put map[%d] = %d\n", cur_x, cur_y);
//     // printMap();
//     int next_x = cur_x + 1;
//     for(int next_y = 0; next_y < N; next_y++) {
//         if(rowCheck(next_y, next_x) && lUpCrossCheck(next_y, next_x) && rUpCrossCheck(next_y, next_x)) 
//             backTracking(next_y, next_x);
//         // printf("backTracking(%d, %d) RECALLED\n", cur_y, cur_x);
//         // printf("role back\n");
//         for(int cl = next_x; cl < N; cl++) 
//             map[cl] = -20;
//         // printMap();
//     }
// }

// bool rowCheck(int cur_y,int cur_x) {
//     for(int x = 0; x < N; x++) {
//         if(cur_y == map[x]) {
//             // printf("rowCheck : false\n");
//             return false;
//         }
//     }
//     // printf("rowCheck : true\n");
//     return true;
// }

// // bool columnCheck(int cur_y,int cur_x, int n) {

// // }

// bool lUpCrossCheck(int cur_y, int cur_x) {
//     for(int x = 0; x < N; x++) {
//         if(cur_x - cur_y == x - map[x]) {
//             // printf("lUpCrossCheck : false\n");
//             return false;
//         }
//     }
//     // printf("lUpCrossCheck : true\n");
//     return true;
// }

// bool rUpCrossCheck(int cur_y, int cur_x) {
//     for(int x = 0; x < N; x++) {
//         if(cur_x + cur_y == x + map[x]) {
//             // printf("x : %d ", x);
//             // printf("rUpCrossCheck : false\n");
//             return false;
//         }
//     }
//     // printf("rUpCrossCheck : true\n");
//     return true;
// }

// void printMap() {
//     for(int x = 0; x < N; x++)
//         printf("%3d", map[x]);
//     printf("\n");
// }