#include<stdio.h>

#define MAXH 256
#define MAXNM 500
#define MAXT 256

typedef struct coor {
    int i;
    int j;
} Coor;

Coor blocks[MAXH+1][MAXNM * MAXNM];
int blockSizes[MAXH+1];

void printCoors() {
    for(int i = 0; i < MAXH+1; i++) {
        printf("----Height: %d-----\n", i);
        for(int j = 0; j < blockSizes[i]; j++) {
            Coor coor = blocks[i][j];
            printf("(%d, %d), ", coor.i, coor.j);
        }
        printf("\n");
    }
}

int getTop() {
    for(int i = MAXH; i >= 0; i--) {
        if(blockSizes[i] > 0)
            return i;
    }

    return 0;
}

int getBottom() {
    for(int i = 0; i <= MAXH; i++) {
        if(blockSizes[i] > 0)
            return i;
    }

    return 0;
}

int checkDecrease() {
    int top = getTop();
    int time = 0;

    if (top == 0)
        return MAXNM * MAXNM;

    for (int i = 0; i < blockSizes[top]; i++) {
        time += 2;
    }

    return time;
}

int checkIncrease(int B) {
    int bottom = getBottom();
    int time = 0;

    if (B < blockSizes[bottom])
        return MAXNM * MAXNM;

    for (int i = 0; i < blockSizes[bottom]; i++)
    {
        time++;   
    }

    return time;
}

int decrease(int *B) {
    int top = getTop();
    int time = 0;

    if(top == 0)
        return MAXNM * MAXNM;

    for(int i = 0; i < blockSizes[top]; i++) {
        blocks[top-1][blockSizes[top-1]++] = blocks[top][i];
        time += 2;
        (*B)++;
    }

    blockSizes[top] = 0; 
    
    return time;
}

int increase(int *B) {
    int bottom = getBottom();
    int time = 0;

    if(*B < blockSizes[bottom])
        return MAXNM * MAXNM;
    
    for(int i = 0; i < blockSizes[bottom]; i++) {
        blocks[bottom+1][blockSizes[bottom+1]++] = blocks[bottom][i];
        time++;
        (*B)--;
    }

    blockSizes[bottom] = 0;

    return time;
}

int main(int argc, char **argv) {
    int i, N, j, M, B, input, bottom, top, time;
    
    scanf("%d %d %d", &N, &M, &B);
    
    for(i = 0; i < N; i++) {
        for(j = 0; j < M; j++) {
            scanf("%d", &input);
            Coor coor;
            coor.i = i;
            coor.j = j;
            blocks[input][blockSizes[input]++] = coor;
        }
    }

    // printCoors();

    bottom = getBottom();
    top = getTop();
    
    time = 0;
    while(bottom < top) {
        if(checkDecrease() < checkIncrease(B)) {
            time += decrease(&B);
        }
        else {
            time += increase(&B);
        }

        bottom = getBottom();
        top = getTop();
    }

    printf("%d %d\n", time, top);

    return 0;
}