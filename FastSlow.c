#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	int num;
	int fast;
	int slow=0;
	
	printf("Enter a number for N: ");
	scanf("%d", &num);
	for (int i=1; i<=num; i++){
		slow+= i;
	}
	fast = (num*(num+1))/2;
	
	printf("\nFast: %d", fast);
	printf("\nSlow: %d", slow);
	
	return 0;
}
