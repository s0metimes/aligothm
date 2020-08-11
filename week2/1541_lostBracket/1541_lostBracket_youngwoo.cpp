#include <stdio.h>
#define MAX 50

char form[MAX+1];

int main(int argc, char const *argv[])
{
    int i, len;
    bool afterMinus = false;
    scanf("%s", form);
    
    for(i = 0; form[i] != '\0'; i++) {
        len++;
        if(afterMinus && form[i] == '+') form[i] = '-';
        else if(form[i] == '-') afterMinus = true;
    }
    int sum = 0;
    int num = 0;
    int cnt = 1;
    for(i = len - 1; i >= 0; i--) {
        if(form[i] == '+') {
            sum += num;
            num = 0;
            cnt = 1;
        } else if(form[i] == '-') {
            sum -= num;
            num = 0;
            cnt = 1;
        } else {            
            num += (form[i]-'0') * cnt;
            cnt *= 10;
        }
    }
    sum += num;
    printf("%d\n", sum);
    return 0;
}