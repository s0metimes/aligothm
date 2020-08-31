#include<stdio.h>

using namespace std;

#define MAX 1000000

int parents[MAX];
int cnts[MAX];

int find(int a) {
    if(a == parents[a]) return a;
    else return parents[a] = find(parents[a]);
}

void unionWith(int from, int to) {
    parents[find(from)] = find(to);
}

int main(void) {
    int N;  // 2 ~ 1,000,000
    int M;  // 0 ~ 5,000
    int x, y;   // 1 ~ N
    int i;
    int numOfDongBang;

    scanf("%d", &N);
    scanf("%d", &M);

    for(i = 0; i < N; i++)
        parents[i] = i;
    
    while(M--) {
        scanf("%d %d", &x, &y);
        for(i = find(x-1); i < y-1; i = find(i+1))
            unionWith(i, y-1);
    }

    for(i = 0; i < N; i++) cnts[find(i)]++;
        
    numOfDongBang = 0;
    for(i = 0; i < N; i++) 
        if(cnts[i] > 0) numOfDongBang++;

    printf("%d\n", numOfDongBang);

    return 0;
}