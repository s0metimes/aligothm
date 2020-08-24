#include<stdio.h>
#include<functional>
#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
#define pii pair<int,int>
#define INF 987654321
using namespace std;

vector<pii> arr[20005];
priority_queue<pii, vector<pii>, greater<pii>> pq;
int dist[20005];

int main()
{
	int v, e;
	scanf("%d %d", &v, &e);
	int a, b, w, k;
	scanf("%d", &k);
	for (int i = 0; i < e; i++)
	{
		scanf("%d %d %d", &a, &b, &w);
		bool flag = 0;
		for (int i = 0; i < arr[a].size(); i++)
		{
			if (arr[a][i].first == b) {
				arr[a][i].second = min(arr[a][i].second, w);
				flag = 1;
			}
		}
		if (flag == 0)
			arr[a].push_back({ b,w });
	}
	
	for (int i = 1; i <= v; i++)
		dist[i] = INF;

	pq.push({ 0,k });
	dist[k] = 0;
	while (!pq.empty())
	{
		int now = pq.top().second;
		int nowdist = pq.top().first;
		pq.pop();
		for (pair<int, int> next : arr[now])
		{
			if (dist[next.first] >= nowdist + next.second) {
				dist[next.first] = nowdist + next.second;
				pq.push({ dist[next.first] , next.first });
			}
		}
	}
	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}
}