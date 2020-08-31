#include<stdio.h>

#define MAXN 200

int parents[MAXN];

int roads[MAXN][MAXN];

int find(int a) {
    if(a == parents[a]) return a;
    else return parents[a] = find(parents[a]);
}

void unionWith(int a, int b) {
    parents[find(a)] = find(b);
}

int main(void) {
    int N;  // 200 이하. 자연수인듯?
    int M;  // 1000 이하. 자연수인듯?
    int i, j, city, targetCity, isPossible;

    scanf("%d", &N);
    scanf("%d", &M);
    
    // initalize parents and heights
    for(i = 0; i < N; i++) parents[i] = i;

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            scanf("%d", &roads[i][j]);

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++) {
            if(roads[i][j])
                unionWith(i, j);
        }


    isPossible = 1;
    for(i = 0; i < M; i++) {
        scanf("%d", &city);
        if(i == 0) targetCity = city;
        else if(find(targetCity-1) != find(city-1)) {
            isPossible = 0;
            break;
        }
    }
    
    printf("%s\n", isPossible ? "YES" : "NO");

    return 0;
}