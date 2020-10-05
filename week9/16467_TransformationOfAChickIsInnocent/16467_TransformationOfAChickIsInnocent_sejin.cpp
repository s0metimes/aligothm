#include<iostream>
#include<vector>

using namespace std;

vector<int> v[11];

int sol(int K, int N){
    if(!v[K].empty())
        return v[K][N];

    vector<int> &_v = v[K];
    for(int i = 0; i < K+1; i++){
        _v.push_back(1);
    }
    for(int i = K+1; i <= N; i++){
        _v.push_back((_v[i-1]+_v[i-(K+1)])%100000007);
    }
    return v[K][N];
}

int main(int argc, char const *argv[])
{
    int T, K, N;

    cin >> T;
    while (T--)
    {
        cin >> K >> N;
        cout<<sol(K,N)<<'\n';
    }
    

    return 0;
}
