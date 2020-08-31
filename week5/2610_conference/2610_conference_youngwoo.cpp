#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

#define MAX 105
#define FRIEND 1
#define NO 500
using namespace std;

vector< int > minInMax(MAX);
vector< int > g(MAX, 0);
vector< vector< int > > group(MAX);
vector< bool > chk(MAX, false);
vector< vector< int > > cost(MAX, vector< int >(MAX, 0));

int gNum = 0;
int N;
bool flag = false;

void Grouping() {
    for(int s = 1; s <= N; s++) {
        if(g[s] != 0) continue;
        gNum++; 
        dfs(s);
    }

    for(int k = 1; k <= gNum; k++) 
        for(int i = 1; i <= N; i++) 
            if(g[i] == k) group[k].push_back(i);
}

void Floyd_Whashall() {
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
}

void dfs(int s) {
    if(g[s] != 0) return;
    g[s] = gNum;

    for(int i = 1; i <= N; i++) 
        if(cost[s][i] == 1) dfs(i); 
}

int main(int argc, char const *argv[])
{
    int M;
    scanf("%d %d", &N, &M);

    for(int f = 1; f <= N; f++) 
        for(int t = 1; t <= N; t++) 
            cost[f][t] = NO;

    for(int s = 1; s <= N; s++) 
        cost[s][s] = 0;

    while(M--) {
        int p1, p2;
        scanf("%d %d", &p1, &p2);
        cost[p1][p2] = 1;
        cost[p2][p1] = 1;
    }
    
    Grouping();

    Floyd_Whashall();

    for(int f = 1; f <= N; f++) 
        for(int t = 1; t <= N; t++) 
            if(cost[f][t] == NO) cost[f][t] = 0;
    
    printf("%d\n", gNum);
    vector< int > result;
    for(int i = 1; i <= gNum; i++) {
        int minV = NO;
        int minIdx = 0;
        for(auto p : group[i]) {
            int maxV = *max_element(cost[p].begin(), cost[p].end());
            if(minV > maxV) {
                minV = maxV;
                minIdx = p;
            }
        }
        result.push_back(minIdx);
    }

    sort(result.begin(), result.end());
    // for(auto ceo : result) 
    //     printf("%d\n", ceo);
    for(int i = 0; i < result.size(); i++) {
        printf("%d\n", result[i]);
    }
    
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <vector>
// #include <algorithm>

// #define MAX 105
// #define FRIEND 1
// #define NO 500
// using namespace std;
// vector< int > minInMax(MAX);
// vector< int > g(MAX, 0);
// vector< vector< int > > group(MAX);
// vector< bool > chk(MAX, false);
// vector< vector< int > > cost(MAX, vector< int >(MAX, 0));

// int gNum = 0;
// int N;
// bool flag = false;

// void dfs(int s) {
//     if(g[s] != 0) return;
//     if(!flag) gNum++;
//     g[s] = gNum;

//     // printf("s : %d, gNum : %d\n", s, gNum);
//     for(int i = s+1; i <= N; i++) {
//         if(g[i] != 0) continue;
//         if(cost[s][i] == 1) {
//             flag = true;
//             dfs(i);
//         }
//     }
// }

// void Grouping() {
//     for(int k = 1; k <= gNum; k++) 
//         for(int i = 1; i <= N; i++) 
//             if(g[i] == k) group[k].push_back(i);
// }

// void Floyd_Whashall() {
//     for(int k = 1; k <= N; k++) {
//         for(int i = 1; i <= N; i++) {
//             for(int j = 1; j <= N; j++) {
//                 cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
//             }
//         }
//     }
// }

// int main(int argc, char const *argv[])
// {
//     int M;
//     scanf("%d %d", &N, &M);

//     for(int f = 1; f <= N; f++) 
//         for(int t = 1; t <= N; t++) 
//             cost[f][t] = NO;

//     for(int s = 1; s <= N; s++) 
//         cost[s][s] = 0;

//     while(M--) {
//         int p1, p2;
//         scanf("%d %d", &p1, &p2);

//         cost[p1][p2] = 1;
//         cost[p2][p1] = 1;
//     }

//     for(int s = 1; s <= N; s++) {
//         dfs(s);
//         flag = false;
//     }

//     for(int s = 1; s <= N; s++) 
//         printf("%d ", g[s]);
//     printf("\n\n");

//     Grouping();

//     Floyd_Whashall();

//     for(int i = 1; i <= gNum; i++) {
//         printf("group num : %d | ", i);
//         for(auto p : group[i]) {
//            printf("%d", p); 
//         }
//         printf("\n");
//     }

//     for(int f = 1; f <= N; f++) 
//         for(int t = 1; t <= N; t++) 
//             if(cost[f][t] == NO) cost[f][t] = 0;

//     for(int f = 1; f <= N; f++) {
//         for(int t = 1; t <= N; t++) {
//             printf("%d", cost[f][t]);
//             if(t != N) printf(" ");
//         }
//         printf("\n");
//     }
//     printf("\n");
//     printf("%d\n", gNum);
//     for(int i = 1; i <= gNum; i++) {
//         int minV = NO;
//         int minIdx = 0;
//         for(auto p : group[i]) {
//             printf("i = %d, p = %d\n", i, p);
//             printf("minV : %d max_element : %d\n", minV, *max_element(cost[p].begin(), cost[p].end()));
//             int maxV = *max_element(cost[p].begin(), cost[p].end());
//             if(minV > maxV) {
//                 minV = maxV;
//                 minIdx = p;
//             }
//             // minV = min(minV, *max_element(cost[p].begin(), cost[p].end()));
//         }
//         printf("minV : %d, minIdx : %d\n", minV, minIdx);
//         printf("%d\n", minIdx);
//     }
//     return 0;
// }