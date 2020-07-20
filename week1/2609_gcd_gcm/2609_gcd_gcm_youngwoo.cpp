#include <stdio.h>

int getGCD(int a, int b);

int main(int argc, char const *argv[])
{
    int a, b;
    
    scanf("%d %d", &a, &b);
    
    int GCD = a > b ? getGCD(a, b) : getGCD(b, a);
    int LCM = a * b / GCD;
    
    printf("%d\n%d\n",GCD, LCM);
    return 0;
}

int getGCD(int a, int b) { // a>=b 
    if(b == 0)
        return a;
    else 
        return getGCD(b, a%b);
}


