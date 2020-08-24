#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>

#define MAXN 100
#define INF 987654321

using namespace std;

int dp[MAXN][MAXN];
vector<int> confs[MAXN];
int visited[MAXN];
stack<int> s;

int min(int a, int b) {
    return a < b ? a : b;
}

void floyd(int n) {
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
}

int maxOfNetwork(int i, int n) {
    int max = 0;
    for(int j = 0; j < n; j++)
        if(dp[i][j] != INF && max < dp[i][j])
            max = dp[i][j];
    return max;
}

int main(void) {
    int N;  // 참석 사람 수
    int M;  // 관계의 수
    int i, j;
    int a, b;
    int confNum;
    int reps[MAXN], minimum, max;
    
    scanf("%d", &N);
    scanf("%d", &M);

    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            dp[i][j] = i == j ? 0 : INF;
        }
    }
    
    for(i = 0; i < M; i++) {
        scanf("%d %d", &a, &b);
        dp[a-1][b-1] = 1;
        dp[b-1][a-1] = 1;
    }

    floyd(N);

    confNum = 0;
    for(i = 0; i < N; i++) {
        if(!visited[i]) {
            for(j = 0; j < N; j++)
                if(dp[i][j] != INF) {
                    visited[j] = 1;
                    s.push(j);
                    confs[confNum].push_back(j);
                }
            
            while(!s.empty()) {
                int top = s.top();
                s.pop();
                
                for(j = 0; j < N; j++)
                    if(dp[top][j] != INF && !visited[j]) {
                        visited[j] = 1;
                        s.push(j);
                        confs[confNum].push_back(j);
                    }
            }

            confNum++;
        }
    }

    for(i = 0; i < confNum; i++) {
        minimum = INF;
        for(j = 0; j < confs[i].size(); j++) {
            max = maxOfNetwork(confs[i][j], N);
            if(minimum > max) {
                minimum = max;
                reps[i] = confs[i][j]+1;
            }
        }
    }

    sort(reps, reps+confNum);

    printf("%d\n", confNum);
    for(i = 0; i < confNum; i++)
        printf("%d\n", reps[i]);
    

    return 0;
}