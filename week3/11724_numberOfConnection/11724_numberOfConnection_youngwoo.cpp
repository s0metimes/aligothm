#include <stdio.h>
#define MAX 1000
#define GROUP(no) group[no][0]

int group[MAX+1][MAX+1];
int where[MAX+1];

int cnt = 0;
int g = 0;

void insert(int no, int val);

int main(int argc, char const *argv[])
{
    int nodes, lines;

    scanf("%d %d", &nodes, &lines);

    while(lines--) {
        int from, to;
        scanf("%d %d", &from, &to);

        if(where[from] == 0 && where[to] == 0) {
            where[from] = where[to] = ++g;
            ++cnt;
            insert(g, from);
            insert(g, to);
        } else if(where[from] == 0) {
            where[from] = where[to];
            insert(where[to], from);
        } else if(where[to] == 0) {
            where[to] = where[from];
            insert(where[from], to);
        } else {
            if(where[from] == where[to]) continue;
            //group을 concate할때 그룹 구분 
            int sno = where[from] > where[to] ? where[to] : where[from];    //base가 될 그룹
            int bno = where[from] < where[to] ? where[to] : where[from];    //사라질 그룹    
            for(int i = 1; i <= GROUP(bno); i++) {
                where[group[bno][i]] = sno;
                insert(sno, group[bno][i]);
                group[bno][i] = 0;
            }
            GROUP(bno) = 0;
            cnt--;
        }
    }

    for(int i = 1; i <= nodes; i++) 
        if(where[i] == 0) cnt++;
    
    printf("%d\n", cnt);
    
    return 0;
}

void insert(int no, int val) {
    group[no][++GROUP(no)] = val;
}


// #include <stdio.h>
// #define MAX 1000
// #define GROUP(no) group[no][0]

// int group[MAX+1][MAX+1];
// int where[MAX+1];

// int cnt = 0;
// int g = 0;

// void insert(int no, int val);
// void printGroup(int nodes);

// int main(int argc, char const *argv[])
// {
//     int nodes, lines;

//     scanf("%d %d", &nodes, &lines);

//     while(lines--) {
//         int from, to;
//         scanf("%d %d", &from, &to);

//         if(where[from] == 0 && where[to] == 0) {
//             where[from] = where[to] = ++g;
//             cnt++;
//             insert(g, from);
//             insert(g, to);
//         } else if(where[from] == 0) {
//             where[from] = where[to];
//             insert(where[to], from);
//         } else if(where[to] == 0) {
//             where[to] = where[from];
//             insert(where[from], to);
//         } else {
//             int sno = where[from] > where[to] ? where[to] : where[from];
//             int bno = where[from] < where[to] ? where[to] : where[from];
//             printf("bno : %d, sno : %d GROUP(bno) : %d\n", bno, sno, GROUP(bno));
            
//             if(where[from] == where[to]) {
//                 printf("cnt : %d\n", cnt);
//                 printf("val : ");
//                 for(int i = 1; i <= nodes; i++) 
//                     printf("%3d", where[i]);
//                 printf("\n");
//                 printf("idx : ");
//                 for(int i = 1; i <= nodes; i++) 
//                     printf("%3d", i);
//                 printf("\n");
//                 printGroup(nodes);
//                 continue;
//             }

//             for(int i = 1; i <= GROUP(bno); i++) {
//                 where[group[bno][i]] = sno;
//                 insert(sno, group[bno][i]);
//                 group[bno][i] = 0;
//             }
//             GROUP(bno) = 0;
//             cnt--;
//         }
//         printf("cnt : %d\n", cnt);
//         printf("val : ");
//         for(int i = 1; i <= nodes; i++) 
//             printf("%3d", where[i]);
//         printf("\n");
//         printf("idx : ");
//         for(int i = 1; i <= nodes; i++) 
//             printf("%3d", i);
//         printf("\n");
//         printGroup(nodes);
//     }

//     for(int i = 1; i <= nodes; i++) {
//         if(where[i] == 0) {
//             cnt++;
//             insert(++g, i);
//         }
//     }

//     printf("cnt : %d\n", cnt);
//     printf("val : ");
//     for(int i = 1; i <= nodes; i++) 
//         printf("%3d", where[i]);
//     printf("\n");
//     printf("idx : ");
//     for(int i = 1; i <= nodes; i++) 
//         printf("%3d", i);
//     printf("\n");
//     printGroup(nodes);

//     printf("%d\n", cnt);
//     return 0;
// }

// void insert(int no, int val) {
//     group[no][++GROUP(no)] = val;
// }

// void printGroup(int nodes) {
//     for(int no = 1; no <= nodes; no++) {
//         if(GROUP(no) == 0) continue;
//         printf("[%d] : ", no);
//         for(int idx = 1; idx <= GROUP(no); idx++) 
//             printf("%4d", group[no][idx]);
//         printf("\n\n");
//     }
// }
/*
12 5
1 2
3 4
5 6
7 8
1 3

*/
// #include <stdio.h>

// #define MAX 1000

// int graph[MAX+1][MAX+1];
// int cnt = 0;

// int maxInRaw(int raw, int nodes);
// void connect(int from, int to, int nodes);

// int main(int argc, char const *argv[])
// {
//     int nodes, lines;

//     scanf("%d %d", &nodes, &lines);

//     while(lines--) {
//         int from, to;
//         scanf("%d %d", &from, &to);
//         connect(from, to, nodes);
//     }

//     for(int i = 1; i <= nodes; i++) 
//         if(maxInRaw(i, nodes) == 0) cnt++;

//     printf("%d\n", cnt);
//     return 0;
// }

// int maxInRaw(int raw, int nodes) {
//     int max = 0;
//     for(int i = 1; i <= nodes; i++) 
//         if(max < graph[raw][i]) max = graph[raw][i];
//     return max;
// }

// void connect(int from, int to, int nodes) {
//     int maxInFrom = maxInRaw(from, nodes);
//     int maxInTo = maxInRaw(to, nodes);

//     if(maxInTo == 0 && maxInFrom == 0)
//         graph[from][to] = graph[to][from] = ++cnt;
//     else if(maxInTo == 0)
//         graph[from][to] = graph[to][from] = maxInFrom;
//     else if(maxInFrom == 0) 
//         graph[from][to] = graph[to][from] = maxInTo;
//     else if(maxInFrom == maxInTo) 
//         graph[from][to] = graph[to][from] = maxInFrom;
//     else {
//         int minV = maxInFrom > maxInTo ? maxInTo : maxInFrom;
//         int maxV = maxInFrom < maxInTo ? maxInTo : maxInFrom;
//         for(int i = 1; i <= nodes; i++) {
//             for(int j = 1; j <= nodes; j++) {
//                 if(graph[i][j] == maxV) 
//                     graph[i][j] = minV;
//             } 
//         }
//         graph[from][to] = graph[to][from] = minV;
//         cnt--;
//     }
// }

// #include <stdio.h>

// #define MAX 1000

// int graph[MAX+1][MAX+1];
// int cnt = 0;

// int maxInRaw(int raw, int nodes);
// void connect(int from, int to, int nodes);
// void printMatrix(int nodes);

// int main(int argc, char const *argv[])
// {
//     int nodes, lines;

//     scanf("%d %d", &nodes, &lines);

//     while(lines--) {
//         int from, to;
//         scanf("%d %d", &from, &to);
//         connect(from, to, nodes);
//         printMatrix(nodes);
//     }

//     for(int i = 1; i <= nodes; i++) 
//         if(maxInRaw(i, nodes) == 0) cnt++;

//     printf("%d\n", cnt);
//     return 0;
// }

// int maxInRaw(int raw, int nodes) {
//     int max = 0;
//     for(int i = 1; i <= nodes; i++) 
//         if(max < graph[raw][i]) max = graph[raw][i];
//     return max;
// }

// void connect(int from, int to, int nodes) {
//     int maxInFrom = maxInRaw(from, nodes);
//     int maxInTo = maxInRaw(to, nodes);

//     if(maxInTo == 0 && maxInFrom == 0) {
//         printf("from : %d, to : %d -> cnt : %d\n", from, to, cnt);
//         graph[from][to] = graph[to][from] = ++cnt;
//         printf("from : %d, to : %d -> cnt : %d\n", from, to, cnt);
//     } else if(maxInTo == 0) {
//         graph[from][to] = graph[to][from] = maxInFrom;
//         printf("from : %d, to : %d -> cnt : %d\n", from, to, cnt);
//     } else if(maxInFrom == 0) {
//         graph[from][to] = graph[to][from] = maxInTo;
//         printf("from : %d, to : %d -> cnt : %d\n", from, to, cnt);
//     } else if(maxInFrom == maxInTo) {
//         printf("from : %d, to : %d -> cnt : %d\n", from, to, cnt);
//         printf("maxInFrom = maxInTo = %d\n", maxInFrom);
//         graph[from][to] = graph[to][from] = maxInFrom;
//     } else {
//         printf("else\n");

//         int minV = maxInFrom > maxInTo ? maxInTo : maxInFrom;
//         int maxV = maxInFrom < maxInTo ? maxInTo : maxInFrom;
//         printf("minV : %d, maxV: %d, cnt : %d\n", minV, maxV, cnt);
        
//         for(int i = 1; i <= nodes; i++) {
//             for(int j = 1; j <= nodes; j++) {
//                 if(graph[i][j] == maxV) 
//                     graph[i][j] = minV;
//             } 
//         }
//         graph[from][to] = graph[to][from] = minV;
//         cnt--;
//         printf("minV : %d, maxV: %d, cnt : %d\n", minV, maxV, cnt);
//     }
// }


// void printMatrix(int nodes) {
//     for(int i = 1; i <= nodes; i++) {
//         for(int j = 1; j <= nodes; j++) {
//             printf("%2d",graph[i][j]);
//         }
//         printf("\n");
//     }
// }