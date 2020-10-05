#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<queue>
#include<climits>
#define X first
#define Y second
using namespace std;

pair<int,int> vil[3];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int dist[3][100][100];
queue<pair<int,int>> Q[3];

int array_max(vector<int> v) {
    int max = v[0];
    for(int i=0; i<v.size(); i++) if(v[i]>max) max=v[i];
    return max;
}
int main(int argc, char const *argv[])
{
    int R, C;
    cin >> R >> C;
    
    vector<string> board(R);
    
    for (int i = 0; i < R; i++){
        cin >> board[i];
    }
    for(int i = 0; i < R; i++){
        for(int j =0; j < 3; j++){
            fill(dist[j][i], dist[j][i] + C,-1);
        }
    }
    for(int i =0; i< 3; i++){
        int x, y; cin>>x>>y;
        vil[i] = {x-1,y-1};
        Q[i].push(vil[i]);
        dist[i][x-1][y-1] =0;
    }

    for(int i = 0; i < 3; i++){
        queue<pair<int,int>> &q =Q[i];
        while(!q.empty()){
            pair<int,int> cur = q.front(); q.pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X +dx[dir]; int ny = cur.Y + dy[dir];
                if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
                if(board[nx][ny] == '1')continue;
                if(dist[i][nx][ny] != -1)continue;
                q.push({nx,ny});
                dist[i][nx][ny] = dist[i][cur.X][cur.Y] + 1;
            }
        }
    }
    int ans = INT_MAX;
    int tempMax = 0;
    int count = 0;
    for(int i =0; i < R; i++){
        for(int j = 0; j < C; j++){
            //셋 다 방문한 경우, 짧은 거리이면 갱신해주고 같은 거리이면 카운트 올려준다.
            
            if(dist[0][i][j] != -1 &&dist[1][i][j] != -1 && dist[2][i][j] != -1){
                vector<int> v;
                v.push_back(dist[0][i][j]);
                v.push_back(dist[1][i][j]);
                v.push_back(dist[2][i][j]);
                tempMax = array_max(v);
                if(tempMax < ans){
                    ans = tempMax;
                    count = 1;
                }else if(tempMax == ans){
                    count++;
                }else{//tempMax > ans: 걍무시
                    continue;
                }
            }
        }
    }

    if(ans == INT_MAX){
        cout << -1;
    }else{
        cout<< ans<<'\n';
        cout<<count<<'\n';
    }
    return 0;
}
