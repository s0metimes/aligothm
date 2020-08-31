#include <bits/stdc++.h>
using namespace std;


int n, m;
int parent[50001];
int numOfSet;
//root, degree
vector<int> indegree(50001,-1);

set<int> adj[50001];
queue<int> q;
vector<int> result;
vector<tuple<int,char,int>> opVector;


int find(int node){
    if(node== parent[node])
        return node;
    return parent[node] = find(parent[node]);
}
void unite(int a, int b){
    int root_a =find(a), root_b = find(b);
    if(root_a ==root_b)
        return;
    else
        parent[root_b]= root_a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    numOfSet = n;

    for (int i=0;i<n;i++)
    {
        parent[i]=i;
    }

    while(m--){
        int left, right;
        char match;
        cin >> left >> match >> right;
        if(match =='='){
            unite(left, right);
            numOfSet--;
        }else{
            opVector.push_back(make_tuple(left,match,right));
        }
    }
    
    for(auto x : opVector){
        int root_a = find(get<0>(x)), root_b =find(get<2>(x)); 
        char c = get<1>(x);

        if(indegree[root_a] == -1)
            indegree[root_a] = 0;
        if(indegree[root_b] == -1)
            indegree[root_b] = 0;


        if (c =='>'){ // 싸이클을 지워버리네. 
            if(adj[root_a].insert(root_b).second)
                indegree[root_b]++;
        }else{
            if(adj[root_b].insert(root_a).second)
                indegree[root_a]++;
        }
    }

    for(int i=0; i< n; i++)
        if(indegree[i]==0) 
            q.push(i);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        result.push_back(cur);
        for(auto i = adj[cur].begin() ; i != adj[cur].end();i++){
            int nxt = *i;
            indegree[nxt]--;
            if(indegree[nxt] == 0)
                q.push(nxt);
        }
    }

    if(numOfSet != result.size())
        cout<< "inconsistent";
    else if(numOfSet == result.size())
        cout<< "consistent";
    return 0;
}