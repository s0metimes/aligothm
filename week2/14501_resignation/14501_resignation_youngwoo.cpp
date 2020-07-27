#include <stdio.h>
#define MAX 15
#define TERM(i) sched[i][1]
#define PRICE(i) sched[i][2]

int sched[MAX+1][2];

int days[MAX+1][MAX+1];
 
int main(int argc, char const *argv[])
{
    int max = 0, n, i, j;
    scanf("%d", &n);

    for(i = 1;  i <= n; i++)
        scanf("%d %d", &TERM(i), &PRICE(i));
         
    for(i = 1; i <= n; i++) {
        if(i+TERM(i)-1 > n) continue;
        days[i+TERM(i)-1][i] = PRICE(i);        
    }

    for(i = n; i >= 1; i--) {
        int nowMaxIdx = 1;
        int beforeMaxIdx = 1;
        for(j = 2; j <= n; j++) {
            if(days[i][nowMaxIdx] < days[i][j]) nowMaxIdx = j;
            if(days[i-1][beforeMaxIdx] < days[i-1][j]) beforeMaxIdx = j;
        
        }    
    }

    


    
    return 0;
}
