#include <stdio.h>
int main() {
    int input, temp;
    scanf("%d", &input);
    for(temp = input-55; temp < input; temp++) {
        int temp2 = temp;
        int temp3 = temp;
        while(temp2 > 0) {
            temp3 += temp2%10;
            temp2 /= 10;
        }
        if(temp3 == input) break;
    }
    if(temp == input) printf("0\n");
    else printf("%d\n", temp);
    
    return 0;
}