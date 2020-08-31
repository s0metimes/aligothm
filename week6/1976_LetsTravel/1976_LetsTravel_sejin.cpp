#include <iostream>
using namespace std;

int parent[200];
int find(int x)
{
    if (x == parent[x])
        return x;
    else
        return parent[x] = find(parent[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    parent[x] = y;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i < 201; i++)
    {
        parent[i] = i;
    }

    int n, m;
    cin >> n;
    cin >> m;

    for(int i= 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {   
            int x;
            cin >>x;
            if(x == 1)
                unite(i+1,j+1);
        }
    }
    int* dest= new int[m];
    for(int i = 0; i <m;i++)
    {
        cin >> dest[i];
    }
    for(int i =0; i< m-1; i++)
    {
        if(find(dest[i])!=find(dest[i+1])){
            cout << "NO"<<'\n';
            return 0;
        }       
    }
    cout << "YES" << '\n';
    return 0;
}