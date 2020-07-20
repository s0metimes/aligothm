#include <stdio.h>
#include <stack>
#include <utility>

using namespace std;

stack< pair<int, int> > s;

int main(int argc, char const *argv[])
{
    int n, h, i;
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        scanf("%d", &h);

        while(!s.empty()) {
            if(s.top().second > h) {
                printf("%d ", s.top().first);
                break;
            } 
            s.pop();   
        }

        if(s.empty()) printf("0 ");

        s.push(make_pair(i, h)); 
    }
    return 0;
}



// #include <stdio.h>

// #define MAX 500000

// int height[MAX+1];


// int main(int argc, char const *argv[])
// {
//     int n, h, i, j;

//     scanf("%d", &n);

//     for(i = 1; i <= n; i++) {
//         scanf("%d", &height[i]);
//         for(j = i-1; j >= 1; j--) 
//             if(height[j] >= height[i])
//                 break;
//         printf(i == 1 ? "%d" : " %d", j);
//     }
//     return 0;
// }