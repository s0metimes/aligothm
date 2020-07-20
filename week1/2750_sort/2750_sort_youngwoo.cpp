#include <stdio.h>
#define MAX 1000

int arr[MAX+1];
int more[MAX+1];
int less[MAX+1];

void quick_sort(int* arr, int start, int end);

int main(int argc, char const *argv[]){
    int n, x, i;

    scanf("%d", &n);
    for(i = 0; i < n; i++) 
        scanf("%d", &arr[i]);

    quick_sort(arr, 0, n-1);
    for(i = 0; i < n; i++)
        printf("%d\n", arr[i]);
    return 0;
}

void quick_sort(int* arr, int start, int end) {
    if(end <= start)
        return;

    int pivot = arr[end];
    int size_more = 0;
    int size_less = 0;
    int s = start;
    int i;
    for(i = start; i < end; i++) {
        if(pivot >= arr[i])
            less[size_less++] = arr[i];
        else
            more[size_more++] = arr[i];
    }

    // printMandL(size_less, size_more);

    for(i = 0; i < size_less; i++, s++) // n
        arr[s] = less[i];

    arr[s++] = pivot;

    for(int k = 0; k < size_more; k++,s++)  // n
        arr[s] = more[k];

    quick_sort(arr, start, start+size_less-1); // logn ~
    quick_sort(arr, start+size_less+1, end);
}
