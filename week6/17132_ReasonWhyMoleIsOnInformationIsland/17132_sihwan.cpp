#include<stdio.h>
#include<vector>
#include<utility>
#include<queue>

using namespace std;

#define MAX 100000
#define Pii pair<int ,int>  // to, weight

vector<Pii> branches[MAX];
vector<Pii> results[MAX];
priority_queue<pair<int, Pii> > pq;
int parents[MAX];

int find(int a) {
    if(a == parents[a]) return a;
    else return parents[a] = find(parents[a]);
}

void unionWith(int a, int b) {
    int root1 = find(a);
    int root2 = find(b);
    parents[root2] = root1;
}

int main(void) {
    int N;  // 1 ~ 100,000
    int X, Y, W;    // X,Y: 1~N, W: 1~200
    int i, j, to, weight;

    scanf("%d", &N);

    for(i = 0; i < N; i++) parents[i] = i;
    
    for(i = 0; i < N-1; i++) {
        scanf("%d %d %d", &X, &Y, &W);
        branches[X-1].push_back(make_pair(Y-1, W));
        branches[Y-1].push_back(make_pair(X-1, W));
    }

    while(!pq.empty()) {
        pair<int, Pii> top = pq.top();
        int a = -top.first;
        int b = top.second.first;
        int w = top.second.second;
        pq.pop();

        vector<Pii> v = branches[a];
        for(auto iter = v.begin(); iter != v.end(); ++iter) {
            Pii p = (*iter);
            to = p.first;
            weight = p.second;
            
        }
        if(a != b) {
            for(auto iter = v.begin(); iter != v.end(); ++iter) {
            
            }
        }
            
    }
    
    return 0;
}