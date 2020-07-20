#include<stdio.h>
#include<stdlib.h>

#define MAXLEN 100

char inputStr[MAXLEN];

int numOfAtom(char c) {
    if(c == 'H')
        return 1;
    if (c == 'C')
        return 12;
    if (c == 'O')
        return 16;

    return 0;
}

int sumOfAtom(char *str, int *curIndex, char endChar) {
    int sum = 0, tmp, i;

    for(i = *curIndex; str[i] != endChar; i++) {
        if(str[i] == '(') {
            i++;
            tmp = sumOfAtom(str, &i, ')');
        }
        else
            tmp = numOfAtom(str[i]);

        if (str[i + 1] >= '0' && str[i + 1] <= '9')
            sum += tmp * (str[++i] - '0');
        else
            sum += tmp;
    }

    *curIndex = i;
    return sum;
}

int main(int argc, char **argv) {
    int i = 0;
    scanf("%s", inputStr);
    printf("%d\n", sumOfAtom(inputStr, &i, '\0'));

    return 0;
}