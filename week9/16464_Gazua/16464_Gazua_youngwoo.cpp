#include <stdio.h>

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    while(N--) {
        int K, n;
        bool flag = false;
        scanf("%d", &K);
        for(n = 2; n*(n+1)/2 <= K; n++) {
            // 카드의 갯수 = O(log N)
            // 카드 갯수가 많아진다는 의미는 적은 카드들의 합이기 때문에
            // 가장 많은 카드의 갯수로 K를 표현하려면 1부터 n-1
            // 일단, 가장 적은 카드로 표현하든, 많은 카드로 표현하든
            // 표현할 수 있으면 Gazua를 외치기 위해 flag를 true로 바꿔주고 break
            // n개가 짝수일경우, n/2번째 수를 a 라고 가정했을때, n개의 수의 합은 n*a + n/2 = K
            // a-(n-1) a-(n-2) a-(n-3) ... a-1 a a+1 a+2 ... a+(n-1) a+n 
            // n개가 홀수일경우, n/2번째 수를 a 라고 가정했을때, n개의 수의 합은 n*a = K
            // a-(n-1) a-(n-2) ...a-2 a-1 a a+1 a+2 ... a+(n-2) a+(n-1)
            if((n % 2 == 0 && (K-n/2) % n == 0) || (n % 2 == 1 && K % n == 0)) {
                flag = true;
                break;
            }
        }
        if(flag) printf("Gazua\n");
        else printf("GoHanGang\n");
    }
    return 0;
}