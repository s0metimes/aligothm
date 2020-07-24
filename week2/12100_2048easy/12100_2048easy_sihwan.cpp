#include<stdio.h>

#define MAX 20

unsigned long long int board[MAX][MAX];

void moveLeft(unsigned long long int board[MAX][MAX], int N) {
    int i, j, targetIndex, boundary;
    unsigned long long int targetValue, currValue;

    for(i = 0; i < N; i++) {
        boundary = 0;
        for(j = 1; j < N; j++) {
            currValue = board[i][j];
            targetIndex = j-1;
            targetValue = board[i][j-1];

            if(currValue == 0)
                continue;
            


            while(targetIndex >= boundary && targetValue == 0) {
                board[i][targetIndex+1] = 0;
                board[i][targetIndex] = currValue;
                targetIndex--;
                targetValue = board[i][targetIndex];
            }
            
            if(targetIndex >= boundary) {
                boundary = targetIndex+1;
                if(board[i][targetIndex] == currValue) {
                    board[i][targetIndex] = currValue * 2;
                    board[i][targetIndex+1] = 0;
                }
            } 
        }
    }
}

void moveRight(unsigned long long int board[MAX][MAX], int N) {
    int i, j, targetIndex, boundary;
    unsigned long long int targetValue, currValue;

    for(i = 0; i < N; i++) {
        boundary = N-1;
        for(j = N-2; j >= 0; j--) {
            currValue = board[i][j];
            targetIndex = j+1;
            targetValue = board[i][j+1];

            if(currValue == 0)
                continue;
            
            while(targetIndex <= boundary && targetValue == 0) {
                board[i][targetIndex-1] = 0;
                board[i][targetIndex] = currValue;
                targetIndex++;
                targetValue = board[i][targetIndex];
            }
            
            if(targetIndex <= boundary) {
                boundary = targetIndex-1;
                if(board[i][targetIndex] == currValue) {
                    board[i][targetIndex] = currValue * 2;
                    board[i][targetIndex-1] = 0;
                }
            } 
        }
    }
}

void moveUp(unsigned long long int board[MAX][MAX], int N) {
    int i, j, targetIndex, boundary;
    unsigned long long int targetValue, currValue;

    for(j = 0; j < N; j++) {
        boundary = 0;
        for(i = 1; i < N; i++) {
            currValue = board[i][j];
            targetIndex = i-1;
            targetValue = board[i-1][j];

            if(currValue == 0)
                continue;
            
            while(targetIndex >= boundary && targetValue == 0) {
                board[targetIndex+1][j] = 0;
                board[targetIndex][j] = currValue;
                targetIndex--;
                targetValue = board[targetIndex][j];
            }
            
            if(targetIndex >= boundary) {
                boundary = targetIndex+1;
                if(board[targetIndex][j] == currValue) {
                    board[targetIndex][j] = currValue * 2;
                    board[targetIndex+1][j] = 0;
                }
            }
        }
    }
}

void moveDown(unsigned long long int board[MAX][MAX], int N) {
    int i, j, targetIndex, boundary;
    unsigned long long int targetValue, currValue;

    for(j = 0; j < N; j++) {
        boundary = N-1;
        for(i = N-2; i >= 0; i--) {
            currValue = board[i][j];
            targetIndex = i+1;
            targetValue = board[i+1][j];

            if(currValue == 0)
                continue;
            
            while(targetIndex <= boundary && targetValue == 0) {
                board[targetIndex-1][j] = 0;
                board[targetIndex][j] = currValue;
                targetIndex++;
                targetValue = board[targetIndex][j];
            }
            
            if(targetIndex <= boundary) {
                boundary = targetIndex-1;
                if(board[targetIndex][j] == currValue) {
                    board[targetIndex][j] = currValue * 2;
                    board[targetIndex-1][j] = 0;
                }
            } 
        }
    }
}

void move(unsigned long long int board[MAX][MAX], int N, int direction) {
    if(direction == 0)
        moveLeft(board, N);
    else if(direction == 1)
        moveRight(board, N);
    else if(direction == 2)
        moveUp(board, N);
    else if(direction == 3)
        moveDown(board, N);
}

void copyBoard(unsigned long long int board[MAX][MAX], unsigned long long int boardCopied[MAX][MAX], int N) {
    int i, j;
    
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            boardCopied[i][j] = board[i][j];
        }
    }
}

void printBoard(unsigned long long int board[MAX][MAX], int N) {
    int i, j;
    
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            printf("%lld\t", board[i][j]);
        }
        printf("\n");
    }
}

int findBiggestNum(unsigned long long int board[MAX][MAX], int N) {
    int i, j, biggestNum;

    biggestNum = 0;
    
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            if(biggestNum < board[i][j])
                biggestNum = board[i][j];
        }
    }

    return biggestNum;
}

int main(int argc, char **argv) {
    int i, j, N, a,b,c,d,e;
    unsigned long long int biggestNum, tmpBoard[5][MAX][MAX], bestSteps[5][MAX][MAX], tmp;

    scanf("%d", &N);

    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            scanf("%lld", &board[i][j]);
        }
    }
    
    copyBoard(board, tmpBoard[0], N);
    biggestNum = 0;

    for(a = 0; a < 4; a++) {
        copyBoard(board, tmpBoard[0], N);
        move(tmpBoard[0], N, a);
        for(b = 0; b < 4; b++) {
            copyBoard(tmpBoard[0], tmpBoard[1], N);
            move(tmpBoard[1], N, b);
            for(c = 0; c < 4; c++) {
                copyBoard(tmpBoard[1], tmpBoard[2], N);
                move(tmpBoard[2], N, c);
                for(d = 0; d < 4; d++) {
                    copyBoard(tmpBoard[2], tmpBoard[3], N);
                    move(tmpBoard[3], N, d);
                    for(e = 0; e < 4; e++) {
                        copyBoard(tmpBoard[3], tmpBoard[4], N);
                        move(tmpBoard[4], N, e);

                        tmp = findBiggestNum(tmpBoard[4], N);
                        if(biggestNum < tmp) {/*
                            for(i = 0; i < 5; i++)
                                copyBoard(tmpBoard[i], bestSteps[i], N);
                            */
                            biggestNum = tmp;
                        }
                    }
                }
            }
        }
    }

/*
    for(i = 0; i < 5; i++) {
        printBoard(bestSteps[i], N);
        printf("-----------------\n");
    }
*/
    printf("%lld\n", biggestNum);

    return 0;
}

