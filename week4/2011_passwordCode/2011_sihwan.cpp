#include<cstdio>
#define DD 1000000;

int dp[5000];

enum StateType { NORMAL, INONE, INTWO, DONE, ERROR };

int counter(int index, int arr[5000], int size, StateType state) {
    switch(state) 
    {
        case NORMAL:
            if (index >= size)
                return counter(index, arr, size, DONE);

            if (arr[index] == 0)
                return counter(index, arr, size, ERROR);

            if(dp[index] > 0)
                return dp[index];
            
            if(arr[index] >= 1 && arr[index] <= 9)
                dp[index] += counter(index+1, arr, size, NORMAL)%DD;

            if(index+1 < size) {
                if(arr[index] == 1)
                    dp[index] += counter(index+1, arr, size, INONE)%DD;

                if(arr[index] == 2)
                    dp[index] += counter(index+1, arr, size, INTWO)%DD;
            }            
            
            return dp[index]%DD;
            break;
        case INONE:
            if (index >= size)
                return counter(index, arr, size, DONE);
            return counter(index+1, arr, size, NORMAL);
            break;
        case INTWO:
            if (index >= size)
                return counter(index, arr, size, DONE);
            if(arr[index] >= 0 && arr[index] <= 6)
                return counter(index+1, arr, size, NORMAL);
            else
                return counter(index, arr, size, ERROR);
            break;
        case DONE:
            return 1;
            break;
        case ERROR:
            return 0;
            break;
    }
}

int main(void) {
    char inputStr[5000];
    int input, arr[5000], size;
    scanf("%s", inputStr);

    size = 0;
    for(int i = 0; inputStr[i] != '\0'; i++) {
        input = inputStr[i]-'0';
        
        arr[size++] = input;
    }
/*
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("size: %d\n", size);
*/
    if(size == 0) 
        printf("0\n");
    else {
        int result = counter(0, arr, size, NORMAL);
        printf("%d\n", result);
    }

    return 0;
}