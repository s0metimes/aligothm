#include <stdio.h>
#define MAX 1000010

int rooms[MAX];

void initialize(int N = MAX) {
    for(int i = 1; i <= N; i++) {
        rooms[i] = i;
    }
}

int FIND(int room) {
    if(rooms[room] == room) return room;
    else return rooms[room] = FIND(rooms[room]);
}

bool isDisjoint(int room_x, int room_y) {
    return !(FIND(room_x) == FIND(room_y));
}

void UNION(int room_x, int room_y) {
    if(isDisjoint(room_x, room_y)) {
        int root_y = rooms[room_y];
        for(int i = room_x; i < room_y;) {
            int root_i = FIND(i);
            rooms[root_i] = root_y;
            i = root_i+1;
        }
    }
}

int countRemain(int N) {
    int cnt = 0;
    int root_i, i;
    for(int i = 1; ;) {
        root_i = FIND(i);
        i = root_i+1;
        cnt++;
        if(root_i == N) break;
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    int N, M;

    scanf("%d", &N);
    initialize(N);   
    
    scanf("%d", &M);
    while(M--) {
        int a, b;   
        scanf("%d %d", &a, &b);
        UNION(a, b);
    }
    printf("%d\n", countRemain(N));
    return 0;
}