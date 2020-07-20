#include<stdio.h>
#define _USE_MATH_DEFINES
#include<math.h>

int main(int argc, char **argv) {
    double input;
    
    scanf("%lf", &input);
    
    printf("%.6f\n", input*input * M_PI);
    printf("%.6f\n", input*input + input*input);

    return 0;
}