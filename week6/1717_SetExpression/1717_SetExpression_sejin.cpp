#include<iostream>
using namespace std;



int parent[1000001];

int n, m;
int a,b,c;

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

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i=0; i <= n; i++){
        parent[i] = i;
    }

    while(m--){
        cin >> a >> b>> c;

        if(a == 0)
            unite(b,c);
        else{
            if(find(b) ==find(c))
                cout << "yes" <<'\n';
            else 
                cout << "no" <<'\n';
        }
    }

}