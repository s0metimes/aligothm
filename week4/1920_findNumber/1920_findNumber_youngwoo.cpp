#include <stdio.h>
#include <algorithm>
#define MAX 100000

using namespace std;

int nums[MAX+1];

int binary_search(int value, int start, int end) {
    int mid;
    while(start <= end) {
        mid = (start+end)/2;
        if(nums[mid] < value) start = mid+1;
        else if(nums[mid] > value) end = mid-1;
        else return 1;
    } 
    return 0;
}

int main(int argc, char const *argv[])
{
    int N, M, i, num;
    scanf("%d", &N);
    
    for(i = 0; i < N; i++) 
        scanf("%d", &nums[i]);

    sort(nums, nums+N);

    scanf("%d", &M);

    for(i = 0; i < M; i++) {
        scanf("%d", &num);
        printf("%d\n", binary_search(num, 0, N-1));
    }

    return 0;
}