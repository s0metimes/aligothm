#include <stdio.h>

int main(int argc, char const *argv[])
{
    int sum, multi;
    scanf("%d %d", &sum, &multi);
    if(multi < 0) {
        int one, two;
        for(one = -1; ; one--) {
            two = -sum*2 - one;
            if(one*two == multi) {
                printf("%d %d\n", one, two);
                break;
            }
        }
    } else if(multi > 0) {  // 두근의 부호 같음
        int one, two;
        if(sum > 0) {   // 두근의 합이 음수
            for(one = -1; ; one--) { // one : 음수근 
                two = -sum*2 - one;
                if(one*two == multi) {
                    if(one < two) printf("%d %d\n", one, two);
                    else if(two < one) printf("%d %d\n", two, one);
                    else printf("%d\n", one);
                    break;
                }
            }
        } else if(sum < 0) { // 두근의 합이 양수
            for(one = 1; ; one++) { //  one : 양수근 
                two = -sum*2 - one;
                if(one*two == multi) {
                    if(one < two) printf("%d %d\n", one, two);
                    else if(two < one) printf("%d %d\n", two, one);
                    else printf("%d\n", one);
                    break;
                }
            }
        } else {/* do nothing */}
    } else {
        if(sum == 0) printf("0\n");
        else if(sum < 0) printf("0 %d\n", -sum*2);
        else  printf("%d 0\n", -sum*2);
    }
    return 0;
}
