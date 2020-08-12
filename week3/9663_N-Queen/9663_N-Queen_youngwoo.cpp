#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

#define MAX 15
using namespace std;

int map[MAX+1];
int cnt = 0;
int N;

void backTracking(int cur_y, int cur_x);
bool rowCheck(int cur_y, int cur_x, int n);
// bool columnCheck(int cur_y, int cur_x, int n);
bool lUpCrossCheck(int cur_y, int cur_x, int n);
bool rUpCrossCheck(int cur_y, int cur_x, int n);
void printMap();

int main(int argc, char const *argv[])
{
    scanf("%d", &N);    
    for(int cur_y; cur_y < N; cur_y++) {
        memset(map, 0, sizeof(map));
        backTracking(cur_y, 0);
    }
    printf("%d\n", cnt);
    return 0;
}

void backTracking(int cur_y, int cur_x) { 
    // 둘수 있는 지 체크 
    // row lupCross rupCross

    int next_x = cur_x + 1;
    if(rowCheck(cur_y, cur_x) && lUpCrossCheck(cur_y, cur_x) && rUpCrossCheck(cur_y, cur_x)) {
        if(cur_x == N-1) {
            cnt++;
            return;
        }
        map[cur_x] = cur_y;
        for(int y = 0; y < N; y++) {
            backTracking(y, next_x);
        }
    }
}

bool rowCheck(int cur_y,int cur_x) {
    for(int x = 0; x < N; x++) 
        if(cur_y == map[cur_x]) return false;
    return true;
}

// bool columnCheck(int cur_y,int cur_x, int n) {

// }

bool lUpCrossCheck(int cur_y, int cur_x) {
}

bool rUpCrossCheck(int cur_y, int cur_x) {
}

void printMap() {
    for(int row = 0; row < N; row++) {
        for(int col = 0; col < N; col++) 
            printf("%3d", map[row][col]);
        printf("\n");
    }
    printf("\n");
}