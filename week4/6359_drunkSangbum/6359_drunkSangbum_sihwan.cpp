#include<stdio.h>

#define MAX 100

// 0: 잠김, 1: 열림
int rooms[MAX];

void toggle(int i) {
    if(rooms[i]) rooms[i] = 0;
    else rooms[i] = 1;
}

int main(void) {
    int T, t, n, i, k, cnt;
    
    scanf("%d", &T);
    
    for(t = 0; t < T; t++) {
        scanf("%d", &n);    // 방의 개수
        
        for(k = 1; k <= n; k++)
            for(i = 0; i < n; i++) {
                if(k == 1) rooms[i] = 1;
                else if(k == 2 && (i+1)%k == 0) rooms[i] = 0;
                else if((i+1)%k == 0) toggle(i);
            }
        
        cnt = 0;
        for(i = 0; i < n; i++)
            if(rooms[i]) cnt++;
        
        printf("%d\n", cnt);
    }
    return 0;
}