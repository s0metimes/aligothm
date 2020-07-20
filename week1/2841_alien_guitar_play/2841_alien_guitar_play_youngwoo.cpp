#include <stdio.h>
#include <stack>
using namespace std;
int main(int argc, char const *argv[])
{
    stack<int> lines[7];
    int N, P, line, flat;
    int cnt = 0;

    scanf("%d %d", &N, &P);
    for(; N > 0; N--) {
        scanf("%d %d", &line, &flat);
        if(P < flat)
            continue;
        if(lines[line].empty()) { // 만약 비어있다면, 즉, 해당 줄이 아무것도 안눌렸다면,
            lines[line].push(flat);
            cnt++;
        } else { // 하나라도 눌려있다면
            if(lines[line].top() < flat) {  // 누를 flat이 기존보다 높다면
                lines[line].push(flat);
                cnt++;
            } else if(lines[line].top() > flat) { // 무언가 때야한다면,
                while(!lines[line].empty() && lines[line].top() > flat) { // 탑이 가장 큰 값이므로, 큰것부터 뺀다.
                    lines[line].pop();
                    cnt++;
                }
                if(lines[line].empty()) { // 전부다 뺐다면
                    lines[line].push(flat);
                    cnt++;
                }
                else if(lines[line].top() != flat) { // flat보다 큰거 다 빼고나서 flat이 눌려있는지 체크
                    lines[line].push(flat);
                    cnt++;
                }
            }
        }
    }
    return 0;
}


// 2nd try
// #include <stdio.h>
// #define MAX 300000

// int isClick[7][MAX+1];  

// int main(int argc, char const *argv[])
// {
//     int N, P, line, flat, i;
//     int cnt = 0;

//     scanf("%d %d", &N, &P);

//     for(; N > 0; N--) {
//         scanf("%d %d", &line, &flat);
//         int maxIdx = isClick[line][0];
//         if(maxIdx < flat) {
//             isClick[line][0] = flat;
//             isClick[line][flat] = 1;
//             cnt++; 
//         } else if(maxIdx > flat){
//             for(i = maxIdx; i > flat; i--) {
//                 if(isClick[line][i] == 1) {
//                     isClick[line][i] = 0;
//                     cnt++;
//                 }
//             }
//             isClick[line][0] = flat;
//             if(isClick[line][flat] == 0) {
//                 isClick[line][flat] = 1;
//                 cnt++;
//             }
//         } 
//     }
//     printf("%d\n", cnt);
//     return 0;
// }



// #include <stdio.h>
// #define MAX 300000

// int isClick[6][MAX+1];  

// int main(int argc, char const *argv[])
// {
//     int N, P, line, flat, i;
//     int cnt = 0;

//     scanf("%d %d", &N, &P);

//     for(; N > 0; N--) {
//         scanf("%d %d", &line, &flat);  
//         int maxIdx = isClick[line][0];
//         if(maxIdx < flat) {
//             isClick[line][0] = flat;
//             isClick[line][flat] = 1;
//             cnt++; 
//             printf("%d line %d flat 누름. cnt : %d\n", line, flat, cnt);
//         } else if(maxIdx > flat){
//             for(i = maxIdx; i > flat; i--) {
//                 if(isClick[line][i] == 1) {
//                     isClick[line][i] = 0;
//                     cnt++;
//                     printf("%d line %d flat 손가락 땜. cnt : %d\n", line, i, cnt);
//                 }
//             }
//             isClick[line][0] = flat;
//             if(isClick[line][flat] == 0) {
//                 isClick[line][flat] = 1;
//                 cnt++;
//                 printf("%d line %d flat is 누름. cnt : %d\n", line, flat, cnt);
//             } else {
//                 printf("%d line %d flat is 이미눌려있음. cnt : %d\n", line, flat, cnt);
//             }
//         } else {
//             printf("%d line %d flat is 이미눌려있음. cnt : %d\n", line, flat, cnt);
//         }
//     }

//     printf("%d\n", cnt);
//     return 0;
// }

