#include <stdio.h>

int arr[31];
/* 
문제 해결 방법 
    배열을 만들어서, 입력받은 index의 값을 바꿔준다. 
    default 값으로 0을 주고, 과제를 제출한 사람은 1로 변경해준다.
*/ 

int main(int argc, char const *argv[])
{
    int i, num;
    for(i = 0; i < 28; i++) {
        scanf("%d", &num);
        arr[num] = 1;
    }

    for(i = 1; i <= 30; i++)
        if(!arr[i]) printf("%d\n", arr[i]);

    return 0;
}

