#include<iostream>
#include<vector>
#include<stack>
#define max(a,b) (a>b)?(a):(b)
using namespace std;

int N, MAX;

vector<vector<int>> rotate(vector<vector<int>> key) {
	int m = key.size();
	vector<vector<int>> temp(m, vector<int>(m, 0));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			temp[i][j] = key[m - j - 1][i];
	return temp;
}

void run(vector<vector<int>> graph, int cnt) {
	if (cnt == 5) {
		int maxtmp = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j<N; j++)
				maxtmp = max(maxtmp, graph[i][j]);
		MAX = max(maxtmp, MAX);
		return;
	}
	stack<int> col[21];
	vector<vector<int>> rGraph;
	vector<vector<int>> tmp;
	//DOWN
	rGraph = graph; // no rotation
	for (int j = 0; j < N; j++)
		for (int i = 0; i < N; i++)
			if (graph[i][j] != 0)
				col[j].push(graph[i][j]);
	tmp.assign(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		int idx = N - 1;
		while (!col[i].empty()) {
			int top = col[i].top();
			col[i].pop();
			if (col[i].empty())
				tmp[idx--][i] = top;
			else if (top == col[i].top()) {
				col[i].pop();
				tmp[idx--][i] = top * 2;
			}
			else
				tmp[idx--][i] = top;
		}
	}
	run(tmp, cnt+1);
	//LEFT
	for(int i = 0;i<N; i++)
		while(!col[i].empty())
			col[i].pop();
	rGraph.clear();
	rGraph = rotate(graph); // 1 rotation
	for (int j = 0; j < N; j++)
		for (int i = 0; i < N; i++)
			if (rGraph[i][j] != 0)
				col[j].push(rGraph[i][j]);
	tmp.clear();
	tmp.assign(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		int idx = N - 1;
		while (!col[i].empty()) {
			int top = col[i].top();
			col[i].pop();
			if (col[i].empty())
				tmp[idx--][i] = top;
			else if (top == col[i].top()) {
				col[i].pop();
				tmp[idx--][i] = top * 2;
			}
			else
				tmp[idx--][i] = top;
		}
	}
	run(tmp, cnt+1);
	//UP
	for (int i = 0; i<N; i++)
		while (!col[i].empty())
			col[i].pop();
	rGraph.clear();
	rGraph = rotate(rotate(graph)); // 2 rotation
	for (int j = 0; j < N; j++)
		for (int i = 0; i < N; i++)
			if (rGraph[i][j] != 0)
				col[j].push(rGraph[i][j]);
	tmp.clear();
	tmp.assign(N, vector<int>(N, 0));
	for(int i = 0; i < N; i++) {
		int idx = N - 1;
		while (!col[i].empty()) {
			int top = col[i].top();
			col[i].pop();
			if (col[i].empty())
				tmp[idx--][i] = top;
			else if (top == col[i].top()) {
				col[i].pop();
				tmp[idx--][i] = top * 2;
			}
			else
				tmp[idx--][i] = top;
		}
	}
	run(tmp, cnt+1);
	//RIGHT
	for (int i = 0; i<N; i++)
		while (!col[i].empty())
			col[i].pop();
	rGraph.clear();
	rGraph = rotate(rotate(rotate(graph))); // 3 rotation
	for (int j = 0; j < N; j++)
		for (int i = 0; i < N; i++)
			if (rGraph[i][j] != 0)
				col[j].push(rGraph[i][j]);
	tmp.clear();
	tmp.assign(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		int idx = N - 1;
		while (!col[i].empty()) {
			int top = col[i].top();
			col[i].pop();
			if (col[i].empty())
				tmp[idx--][i] = top;
			else if (top == col[i].top()) {
				col[i].pop();
				tmp[idx--][i] = top * 2;
			}
			else
				tmp[idx--][i] = top;
		}
	}
	run(tmp, cnt+1);
}

int main() {
	int num;
	scanf("%d", &N);
	vector<vector<int>> arr;
	for (int i = 0; i < N; i++) {
		vector<int> row;
		for (int j = 0; j < N; j++) {
			scanf("%d", &num);
			row.push_back(num);
		}
		arr.push_back(row);
	}
	run(arr, 0);
	printf("%d\n", MAX);
}
