#include<stdio.h>

#define MAXD 36

long long int powOfBinarySmallerThan(long long int B, int *cnt) {
    long long int result = 1;
    
    while(result <= B) {
        result *= 2;
        (*cnt)++;
    }
    
    return result;
}

void mult(int resultMat[5][5], int mat1[5][5], int mat2[5][5], int N) {
    
}

void printMat(int mat[5][5], int N) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void getResult(int resultMat[5][5], long long int B, int N, int matSet[MAXD][5][5]) {
    int powCnt = 0;
    long long int newB = powOfBinarySmallerThan(B, &powCnt);
    
    if(B - newB > 0) {
        mult(resultMat, resultMat, matSet[powCnt-1], N);
        getResult(resultMat, newB, N, matSet);
    }
    else if(B - newB == 0){
        mult(resultMat, resultMat, matSet[powCnt - 1], N);
        
    }
    else {
        printf("What the fuck?\n");
    }
}


int main(int argc, char **argv) {
    int i, j, N, matSet[MAXD][5][5], powCnt = 0, identityMat[5][5];
    long long int B, pow;
    scanf("%d %lld", &N, &B);
    
    pow = powOfBinarySmallerThan(B, &powCnt);

    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            scanf("%d", &matSet[0][i][j]);
            if(i == j)
                identityMat[i][j] = 1;
            else
                identityMat[i][j] = 0;
        }
    }

    for(i = 1; i < MAXD; i++) {
        mult(matSet[i], matSet[i-1], matSet[i-1], N);
    }
    
    getResult(identityMat, B, N, matSet);

    return 0;
}