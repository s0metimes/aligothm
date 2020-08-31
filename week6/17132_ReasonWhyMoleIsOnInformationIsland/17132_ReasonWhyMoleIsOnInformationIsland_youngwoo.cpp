#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>
#define WEIGHT int
#define NODE int
using namespace std;

#define MAX 100000 
typedef pair< NODE, WEIGHT > Pii;
vector< Pii > edges[MAX];
vector< vector <int> > dist(MAX, vector(MAX, 300));
bool chk[MAX];


int main(int argc, char const *argv[])
{
    /* code */
    // N : 집의 갯수 : (1 ≤ N ≤ 100,000)
    int N, i = 0;
    
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        // X, Y : 두 정점 : (1 ≤ X,Y ≤ N)
        // W : X에서 Y가 연결된 길을 지날 때 만족도 : (1 ≤ W ≤ 200) 
        int X, Y, W;
        scanf("%d %d %d", &X, &Y, &W);
        edges[X].push_back({Y, W});
        edges[Y].push_back({X, W});
    }

    for(int from = 1; from <= N; from++) {
        for(int to = from+1; to <= N; to++) {
            FIND(from, to);
        }
    }

    return 0;
}

