#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>

#define MAXN 110
#define INF 987654321

using namespace std;
vector< vector< int > > cost(MAXN, vector< int >(MAXN, INF));

void Floyd_Warshall(int n) {
    int temp, f, t;
    for(temp = 1; temp <= n; temp++) {
        for(f = 1; f <= n; f++) {
            for(t = 1; t <= n; t++) {
                cost[f][t] = min(cost[f][t], cost[f][temp] + cost[temp][t]);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++) 
        cost[i][i] = 0;
    
    for(int i = 0; i < m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        cost[a][b] = min(cost[a][b], c);
    }

    Floyd_Warshall(n);

    for(int f = 1; f <= n; f++) {
        for(int t = 1; t <= n; t++) {
            if(cost[f][t] == INF) cost[f][t] = 0;
            printf("%d", cost[f][t]);
            if(t != n) printf(" ");
        }
        printf("\n");
    }   
    return 0;
}
// #include <stdio.h>
// #include <stdlib.h>
// #include <queue>
// #include <vector>

// #define MAXN 110
// #define INF 987654321

// using namespace std;
// vector< vector< int > > cost(MAXN, vector< int >(MAXN, INF));

// void Floyd_Warshall(int n) {
//     int temp, f, t;
//     for(temp = 1; temp <= n; temp++) {
//         for(f = 1; f <= n; f++) {
//             for(t = 1; t <= n; t++) {
//                 printf("cost[%d][%d](%d), cost[%d][%d](%d) + cost[%d][%d](%d)\n", f, t, cost[f][t], f, temp, cost[f][temp], temp, t, cost[temp][t]);
//                 if(cost[f][t] > cost[f][temp] + cost[temp][t]) printf("refresh\n");
//                 cost[f][t] = min(cost[f][t], cost[f][temp] + cost[temp][t]);
//                 printf("cost[%d][%d] = %d\n\n", f,t, cost[f][t]);
//             }
//         }
//     }
// }

// int main(int argc, char const *argv[])
// {
//     int n, m;
//     scanf("%d %d", &n, &m);

//     for(int i = 1; i <= n; i++) 
//         cost[i][i] = 0;
    
//     for(int i = 0; i < m; i++){
//         int a, b, c;
//         scanf("%d %d %d", &a, &b, &c);
//         cost[a][b] = min(cost[a][b], c);
//     }

//     for(int f = 1; f <= n; f++) {
//         for(int t = 1; t <= n; t++) {
//             if(cost[f][t] == INF) printf("-1");
//             else printf("%d", cost[f][t]);
//             if(t != n) printf(" ");
//         }
//         printf("\n");
//     }

//     Floyd_Warshall(n);

//     for(int f = 1; f <= n; f++) {
//         for(int t = 1; t <= n; t++) {
//             if(cost[f][t] == INF) cost[f][t] = 0;
//             printf("%d", cost[f][t]);
//             if(t != n) printf(" ");
//         }
//         printf("\n");
//     }
        
//     return 0;
// }