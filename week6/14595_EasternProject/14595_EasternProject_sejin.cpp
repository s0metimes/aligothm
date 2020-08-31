#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001

int parent[MAX];
int cnt[MAX];
int n,m;
int numOfRoom;


int find(int node){
    if (node > n)
        return -1;
    if (node == parent[node])        
        return node;
    return parent[node] = find(parent[node]);
}

void unite(int a, int b){ 
    int root_a = find(a), root_b = find(b);
    
    for(int i = root_a; i!= root_b; i = find(i+1)){
        parent[i] = root_b;
        cnt[root_b] += cnt[i];
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >>n >> m;

    numOfRoom = 0;
    for (int i= 1; i < MAX; i++){
        parent[i] =i;
        cnt[i] = 1;
    }

    while(m--){
        int x,y;
        cin >> x >> y;
        unite(x,y);
    }

    for(int i= find(1); i!=parent[n]; i = find(i+1)){
        numOfRoom++;
    }
    numOfRoom++;

    cout<< numOfRoom <<endl;
    return 0;
}
