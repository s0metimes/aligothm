#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int arr[1000001];
int main(){

    int H, x; scanf("%d %d",&H,&x);
    int ans=0;
    for(int i =1; i<= H; i++){
        cin>>arr[i];
    }
    long long mul = 1;
    for(int i =1; i<= H;i++){
        mul =  (mul* x) % 1000000007;
        ans = ans% 1000000007+   (arr[i]*mul) % 1000000007; 
    }
    printf("%d", ans% 1000000007);
    return 0;
}