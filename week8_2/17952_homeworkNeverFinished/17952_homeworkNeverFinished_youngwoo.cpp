#include <stdio.h>
#include <stack>
#include <utility>
#define Pii pair<int, int> // score, remain time>
using namespace std;

stack<Pii> st;
int main(int argc, char const *argv[])
{
    int N, result = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        int doHwAdd;
        scanf("%d", &doHwAdd);
        if(doHwAdd) {
            int score, time;
            scanf("%d %d", &score, &time);
            if(time == 1) result += score;
            else st.push(make_pair(score, time-1));
        } else {
            if(!st.empty()) {
                Pii top  = st.top();
                st.pop();
                top.second--;
                if(top.second == 0) result += top.first;
                else st.push(top);    
            } else { /* do nothing */}
        }
    }

    printf("%d\n", result);

    return 0;
}