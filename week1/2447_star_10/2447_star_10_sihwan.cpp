#include<stdio.h>

#define MAXN 6561

int stars[MAXN][MAXN];

// (i, j) 부터 (x, y) 까지.
void markStar(int i, int j, int x, int y) {
	if((x - i) / 3 == 1 && (y - j) / 3 == 1){
		stars[i][j] = 1;
		stars[i][j+1] = 1;
		stars[i][j+2] = 1;
		stars[i+1][j] = 1;
		stars[i+1][j+1] = 0;
		stars[i+1][j+2] = 1;
		stars[i+2][j] = 1;
		stars[i+2][j+1] = 1;
		stars[i+2][j+2] = 1;
	}
	else {
		int ru = (x-i)/3;
		int cu = (y-j)/3;
		markStar(i, j, i+ru, j+cu);
		markStar(i, j+cu, i+ru, j+cu*2);
		markStar(i, j+cu*2, i+ru, j+cu*3);
		markStar(i+ru, j, i+ru*2, j+cu);
		// 중간꺼는 그리지 않는다.
		markStar(i+ru, j+cu*2, i+ru*2, j+cu*3);
		markStar(i+ru*2, j, i+ru*3, j+cu);
		markStar(i+ru*2, j+cu, i+ru*3, j+cu*2);
		markStar(i+ru*2, j+cu*2, i+ru*3, j+cu*3);
	}
}

int main(int argc, char **argv) {
	int N;
	
	scanf("%d", &N);
	
	markStar(0, 0, N, N);
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++)
			if(stars[i][j])
				printf("*");
			else
				printf(" ");
		printf("\n");
	}

	return 0;
}
