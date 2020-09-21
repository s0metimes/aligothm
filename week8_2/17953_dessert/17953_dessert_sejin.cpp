#include<iostream>
using namespace std;

int sati[11][100001]; // 디저트, 날짜 수
int dp[11][100001]; // 디저트 종류, 전날 같은걸 먹었는지, 날짜
int main(){

    // int sati[3][4]; // 디저트, 날짜 수
    // int dp[3][4]; // 디저트 종류, 전날 같은걸 먹었는지, 날짜
    //날짜와 메뉴
    int N, M; scanf("%d %d",&N, &M);
    for (int i = 1; i <= M; i++)
        for(int j = 1; j <= N; j++)
            scanf("%d", &sati[i][j]);
    
    // 어제 먹은 것을 다시 먹을지, 새로운 것을 먹을지 골라야 한다.
    // 전날에 뭘 먹었느냐에 따라서 오늘 값이 달라진다. 전날기준 메뉴별로 최댓값을 만들어 놓고
    // 오늘 어떤 메뉴를 픽하는 계산하는데 참조한다. 

    //i번째 메뉴를 1번째 날에 먹는 경우
    for(int i = 1; i <= M; i++){
        dp[i][1] = sati[i][1];
    }

    //i번째 메뉴를 j번째 날에 먹는 경우 최대값
    for(int j = 2; j <= N; j++){
        for (int i = 1; i <= M; i++){
        
            // 전날 먹은 메뉴들을 순회하면서, 오늘 얻는 만족도를 찾아 최대 만족도를 구한다!
            //같은 메뉴를 고르는 경우 dp[i][j] = dp[i][j-1] +sati[i][j]/2
            // 다른 메뉴를 고르는 경우 dp[i][j] = dp[다른메뉴][j-1] + sati ij
            int max =0;

            for(int  k = 1; k <= M; k++){
                if(k == i){ //전날이랑 같은 거 먹는 경우
                     max =  dp[i][j-1] + sati[i][j]/2 > max ? dp[i][j-1] + sati[i][j]/2 : max;
                }else{// 전날이랑 다른 거 먹는 경우
                    max =  dp[k][j-1] + sati[i][j] > max ? dp[k][j-1] + sati[i][j] : max;
                }
                dp[i][j] = max;
            }
        }
    }

    //마지막 날에 뭘 먹을지에 따라 결정됨. N-1날 뭘 먹든간에 하나 더 먹으면 더 만족스럽다.
    int ans =0;
    for(int i = 1; i <= M; i++){
        ans = dp[i][N] > ans ? dp[i][N] : ans;
    }

    printf("%d", ans);

    return 0;
}