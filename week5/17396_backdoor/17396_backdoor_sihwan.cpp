#include <stdio.h>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>

#define MAXN 100005
#define INF 1LL << 60

using namespace std;

vector<pair<int, long long> > weights[MAXN];
priority_queue<pair<long long, int> > pq;
long long dist[MAXN];
int A[MAXN];

void pushAdjs(int k, long long path)
{
    //printf(">>>>> pushed \n");
    for (int i = 0; i < weights[k].size(); i++)
    {
        int to = weights[k][i].first;
        long long weight = weights[k][i].second;

        if (dist[k] != INF && dist[to] > path + weight)
        {
            dist[to] = path + weight;
            pq.push(make_pair(-dist[to], to));
            //printf("from: %d, to: %d, weight: %d\n", k, to, weight);
        }
    }
}

void dijkstra(int k)
{
    int i = 1;

    // 집어 넣음
    pushAdjs(k, 0);

    while (!pq.empty())
    {
        //printf("-------step%d-------\n", i++);
        int to = pq.top().second;
        long long path = -pq.top().first;
        //printf("to: %d, path: %d\n", to, path);
        pq.pop();
        // 와 이거 if 문 한줄이 영향 존나 많이 주네;;; 
        // 시발 이거 안넣으면 시간초과남;; 뭐지???
        // 이거 진짜 존나 이해안되네;; 아니 애초에 정렬될 때 INF 들은 밑으로 가는거 아닌가;;?
        // INF 가 아닌데 다른 경우도 있는건가?? 그래서 중복이 발생??
        // 아 시발 존나 빡치면서 어려운데 욕만 나오네 ㅅㅂ;; 이런건 디버깅 어케하냐?? 시발...
        if(dist[to] != path) continue;
        pushAdjs(to, path);
        //printf(">>>>>> dist[%d]: %d\n\n", to, dist[to]);
    }
}

int main(void)
{
    int N; // 분기점의 개수
    int M; // 분기점 연결선 개수
    int a, b, i, j, max;
    long long t;

    scanf("%d %d", &N, &M);
    for(i = 0; i < N; i++) scanf("%d", &A[i]);
    A[N-1] = 0;
    for(i = 0; i < M; i++) {
        scanf("%d %d %lld", &a, &b, &t);
        // 이거 조건문 잘못 달았다고 틀렸다;; 시발;; 하긴 이건 틀린만해
        if(!A[a] && !A[b]) {
            weights[a].push_back(make_pair(b, t));
            weights[b].push_back(make_pair(a, t));
        }
    }
    
    // initialize
    j = N; while (j--) dist[j] = INF;
    dist[0] = 0;
    
    dijkstra(0);

    if(dist[N-1] == INF)
        printf("-1\n");
    else
        printf("%lld\n", dist[N-1]);

    return 0;
}