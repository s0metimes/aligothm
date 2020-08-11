#include <stdio.h>
#include <stack>
#include <iostream>
using namespace std;

#define MAX 1001

bool map[MAX][MAX];
bool visited[MAX];

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        int A, B;
        scanf("%d %d", &A, &B);
        map[A][B] = map[B][A] = 1;
    }

    stack<int> st;
    int CNT = 0;
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            CNT++;
            st.push(i);
            visited[i] = 1;
            while (!st.empty())
            {
                int tmp = st.top();
                st.pop();
                for (int j = 1; j <= N; j++)
                {

                    if (map[tmp][j] == 1 && !visited[j])
                    {
                        st.push(j);
                        visited[j] = 1;
                    }
                }
            }
        }
        else
        {
            continue;
        }
    }
    printf("%d", CNT);
}