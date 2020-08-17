#include <stdio.h>

int K, N;
int A[10001];
int MAX;

void binarySearch(long long int st, long long int end)
{
	long long int mid;
	int cnt;

	while (st <= end) 
	{
		mid = (st + end + 1) / 2;
		cnt = 0;
		for (int i = 0; i < K; i++) 
			cnt += A[i] / mid;
		if (cnt >= N) 
		{
			MAX = mid;
			st = mid + 1;
		}
		else end = mid - 1;
	}
}

int main(void)
{
	int fin = 0;
	scanf("%d %d", &K, &N);

	for (int i = 0; i < K; i++) 
	{
		scanf("%d", &A[i]);
		fin = (A[i] > fin) ? A[i] : fin;
	}

	binarySearch(0, fin);
	printf("%d\n", MAX);
}
