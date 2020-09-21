#include <stdio.h>
#include <math.h>
#define MAX 1000000
char arr[MAX+1];
char command[10];

long long ctolld(char c) {
    long long trans = 0;
    switch(c) {
        case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
            trans = (c - '0');
            break;
        case 'a':case 'b':case 'c':case 'd':case 'e':case 'f':
            trans = 10 + (c - 'a');
            break;
    }
    return trans;
}
int main(int argc, char const *argv[])
{
    scanf("%s", arr);
    
    int N;
    scanf("%d", &N);
    
    int pos = 0;
    for(int i = 0; i < N; i++) {
        long long value = 0;
        int gap, end;
        scanf("%s", command);
        if(command[0] == 'c') gap = 2;
        else if (command[0] == 'i') gap = 8;
        else if (command[0] == 'l') gap = 16;
        
        end = pos + gap;
        int s = 0;
        for(int p = end-1; p >= pos; p--) 
            value += ctolld(arr[p]) * (long long)pow(16, s++);
        printf("%lld ", value);
        pos = end;
    }
    printf("\n");

    return 0;
}
