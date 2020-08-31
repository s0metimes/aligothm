#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000

int parent[MAX], cnt[MAX];

int find(int node){
    if(node == parent[node])
        return node;
    return parent[node] = find(parent[node]);
}

void unite(int a,int b){
    int root_a = find(a);
    int root_b = find(b);
    if(root_a != root_b){
        parent[root_b] = root_a;
        cnt[root_a] += cnt[root_b];    
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i< MAX; i++){
        parent[i]=i;
        cnt[i] =1;
    }

    int N;
    cin >> N;

    char type;
    int a,b,c;

    int* numOfElement = new int[MAX];
    fill(numOfElement,numOfElement+MAX,1);

    while(N--){
        cin >> type;
        if(type ==  'I'){
            cin >> a >> b;
            unite(a,b);
        } // 어떤 로봇의 부품이 몇 개인가? 
        else if (type =='Q'){
            cin >> c;
            cout<< cnt[find(c)] <<'\n';
        }       
    }
    return 0;
}