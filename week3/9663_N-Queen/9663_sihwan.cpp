#include<stdio.h>
#include<stack>
#include<utility>

using namespace std;

#define MAX 14

int visited[MAX][MAX];
stack< pair<int, int> > s;
int count;

bool isPlacable(int i, int j, int x, int y, int N) {
    if(i < 0 || i >= N || j < 0 || j >= N) 
        return false;
    else if(x-i == 0 || y-j == 0 || x-i == y-j || x-i == j-y || visited[i][j]) 
        return false;
    else
        return true;
}

void backtracking(int N) {
    int i, j, x, y;
    pair<int, int> top;
    int length = 0;
    while(!s.empty()) {
        top = s.top();
        x = top.first;
        y = top.second;
        if(!visited[x][y])
            length++;
        visited[x][y] = 1;
        s.pop();

        for(i = 0; i < N; i++) {
            for(j = 0; j < N; j++) {
                if(!visited[i][j] && isPlacable(i, j, x, y, N)) {
                    if(length == N) {
                        count++;
                    }

                    s.push((make_pair(i, j)));
                }
            }
        }

        if(length == N)
            break;
    }
}

int main(void) {
    int N;
    int i, j;
    scanf("%d", &N);

    for(i = 0; i < N-1; i++) {
        for(j = 0; j < N-1; j++) {
            if(!visited[i][j]) {
                s.push(make_pair(i, j));
                backtracking(N-1);
            }
        }
    }

    printf("%d\n", count+1);

    return 0;
}
