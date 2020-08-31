#include <bits/stdc++.h>
using namespace std;

int parent[1000];
bool isOverMan[1000];
vector<tuple<int,int,int>> edge;


int find(int node){
    if(node == parent[node])
        return node;
    return parent[node] = find(parent[node]);
}

void unite(int a, int b){
    int root_a = find(a), root_b =find(b);
    parent[root_a] = root_b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;

    cin >>n >>m;

    // edge = vector<tuple<int,int,int>>();


    for(int i = 1 ; i < n+1; i++)
    {
        char c;
        cin >> c;
        if (c =='M')
            isOverMan[i]=1;
        else
            isOverMan[i]=0;
        
        parent[i]=i;
    }

    for(int i = 0; i< m; i++){
        int u,v,d;
        cin >>u >>v>>d;
        edge.push_back(tie(d,u,v));
    } 
    sort(edge.begin(),edge.end());
    int ans = 0;
    int u,v, d;

    int selectedEdge = 0;
    for(int i =0; i < m && selectedEdge != n-1; i++){
        u = get<1>(edge[i]);
        v=  get<2>(edge[i]);
        d=  get<0>(edge[i]);

         if(isOverMan[u] != isOverMan[v]){
            int root_u = find(u);
            int root_v = find(v);
            if(root_u != root_v){
                // cout << u <<"and" <<v <<"are united"<<endl;
                unite(u,v); //이제 더해가면서 가중치만 합해볼까
                ans += d;
                selectedEdge ++;
            }
        }
    }
    if(selectedEdge == n-1)
        cout << ans<< '\n';
    else
        cout << -1 << '\n';
    return 0;
}