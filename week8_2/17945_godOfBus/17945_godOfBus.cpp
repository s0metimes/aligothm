
#include<iostream>
#include<utility>
#include<math.h>
using namespace std;
pair<int,int> ans;
int main(){
    int A,B; scanf("%d %d", &A, &B);
    //x^2 2ax b
    //(-A +- root a^2-1B)
    ans.first = (-A- sqrt(pow(A,2)-B));
    ans.second = (-A+ sqrt(pow(A,2)-B));
    if (ans.first == ans.second)
        printf("%d", ans.second);
    else
        printf("%d %d", ans.first, ans.second);

    return 0;
}
