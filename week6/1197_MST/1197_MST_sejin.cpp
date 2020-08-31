#include <bits/stdc++.h>
using namespace std;

int V, E, A, B, C;
pair<int,pair<int,int>> wee[100001];
int parent[100001];

int find(int x){
    if(x == parent[x])
        return x;
    else
        return parent[x] = find(parent[x]);

}

void unite(int x, int y){
    x = find(x);
    y = find(y);
    parent[x] = y;
}

bool isDiffSet(int a, int b){
    return find (a) != find(b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E;

    for (int i = 1; i < 100001; i++)
    {
        parent[i]=i;
    }
    

    for (int i = 0 ; i <E; i++)
    {
        cin >> A>> B>> C;
        wee[i] =make_pair(C,make_pair(A,B));
    }

    sort(wee,wee+E);
    
    int selected =0;
    int weight = 0;
    for (int i = 0; i < E && selected != V-1; i++)
    {
        if(isDiffSet(wee[i].second.first, wee[i].second.second))
        {
            unite(wee[i].second.first,wee[i].second.second);
            selected++;
            weight += wee[i].first; 
        }else{
            continue;
        }
    }

    cout << weight<< '\n';
    return 0;
}