#include<stdio.h>
#include<stack>

using namespace std;

#define MAXN 1000

int visited[MAXN+1], branches[MAXN+1][MAXN+1];
stack<int> s;

int dfs(int N) {
    int top, n, length;
    
    length = 0;
    while (!s.empty())
    {
        top = s.top();
        visited[top] = 1;
        s.pop();
        length++;

        for (n = 1; n <= N; n++)
            if (!visited[n] && branches[top][n])
                s.push(n);
    }

    return length;
}

int main(int argc, char **argv) {
    // inputs
    int N, M;
    // usage
    int n, m, node1, node2, begin, count, length;

    scanf("%d %d", &N, &M);

    for(m = 0; m < M; m++) {
        scanf("%d %d", &node1, &node2);

        if(m == 0)
            begin = node1;
        
        branches[node1][node2] = 1;
        branches[node2][node1] = 1;
    }

    count = 0;
    for(n = 1; n <= N; n++) {
        if(!visited[n]) {
            s.push(n);
            length = dfs(N);

            count++;
        }
    }
    
    printf("%d\n", count);
    
    return 0;
}
