#include<stdio.h>

#define NSTU 30

// Initialized with value 0 as this is a global variable.
int isStuAss[NSTU+1];

int main(int argc, char **argv) {
	int input, i;

	for(i = 0; i < 28; i++) {
		scanf("%d", &input);
		isStuAss[input]++;
	}

	for(i = 1; i <= NSTU; i++) {
		if(!isStuAss[i])
			printf("%d\n", i);
	}
	
	return 0;
}
