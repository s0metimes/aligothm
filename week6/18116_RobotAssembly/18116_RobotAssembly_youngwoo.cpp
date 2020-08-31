#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX 1000010

int robot[MAX];
int cnt[MAX];
void initialize() {
    for(int i = 0; i <= MAX; i++) {
        robot[i] = i;
        cnt[i] = 1;
    }
}

int FIND(int part) {
    if(robot[part] == part) return part;
    else return robot[part] = FIND(robot[part]);
}

bool isDisjoint(int part_a, int part_b) {
    return !(FIND(part_a) == FIND(part_b));
}

void UNION(int part_a, int part_b) {
    if(isDisjoint(part_a, part_b)) {
        int root_a = robot[part_a];
        int root_b = robot[part_b];
        robot[root_b] = root_a;
        cnt[root_a] += cnt[root_b];
    }
} 

int getNumberOfParts(int part_a, int maxV) {
    if(part_a > maxV) return 1;
    else return cnt[FIND(part_a)];
}

int main(int argc, char const *argv[])
{
    int N;
    int maxV = 0;
    
    initialize();

    scanf("%d", &N);
    while(N--) {
        getchar();  // 줄바꿈 처리 
        char command;
        int a, b;
        scanf("%c", &command);
        switch (command)
        {
        case 'I':            
            scanf("%d %d", &a, &b);
            UNION(a, b);
            maxV = max(maxV, max(a,b));
            break;

        case 'Q':
            scanf("%d", &a);
            printf("%d\n",getNumberOfParts(a, maxV));
            break;
        }
    }
    return 0;
}
