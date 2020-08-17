#include<cstdio>

bool isParsed = true;

int counter(int index, int arr[5000], int size)
{
    if(index == size-1)
        return 1;
    else if(index >= size)
        return 1;
    else if(arr[index] == 1) {
        int acc = 0;
        if (index + 1 < size && arr[index + 1] <= 9)
            acc += counter(index + 2, arr, size) % 1000000;

        if (index + 1 < size && arr[index + 1] != 0)
            acc += counter(index + 1, arr, size) % 1000000;

        return acc;
    }
    else if(arr[index] == 2) {
        int acc = 0;
        if(index+1 < size && arr[index+1] <= 6)
            acc += counter(index+2, arr, size)%1000000;
        
        if(index+1 < size && arr[index+1] != 0)
            acc += counter(index+1, arr, size)%1000000;
        
        return acc;
    }
    else if(3 <= arr[index] && arr[index] <= 9) {
        int acc = 0;
        if(index+1 < size && arr[index+1] != 0)
            acc += counter(index+1, arr, size)%1000000;
        
        return acc;
    }
    else {
        isParsed = false;
        return 0;
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
*/
    if(size == 0)
        printf("0\n");
    else {
        int result = counter(0, arr, size);
        if(isParsed)
            printf("%d\n", result);
        else
            printf("0\n");
    }

    return 0;
}