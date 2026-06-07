#include <stdio.h>
#include <stdlib.h>
//다시 풀어야 됨!!!!!!!!
int start1(int n, int *M) {
	int min=10000000;
	int ret=0;
	
	if(M[n] != 0)
		return M[n];
		
	if(n == 1) {
		printf("1");
		return 0;
	}
	else {
		printf("%d ", n);
		if(n%3==0) {
			ret = start1(n/3, M) + 1;
			if(ret<min)
				min=ret;
		}
		else if(n%2==0) {
			ret = start1(n/2, M) + 1;
			if(ret<min)
				min=ret;
		}
		else {
			ret = start1(n-1, M) + 1;
			if(ret<min)
				min=ret;
		}
		M[n] = ret;
		return min;
	}
}

int main() {
	int n,i;
	int *M;

	scanf("%d", &n);
	
	M = (int*)malloc(sizeof(int)*(n+1));

	for(i=0; i<=n; i++)
    	M[i] = 0;

	printf("\n%d", start1(n, M));

	free(M);

	return 0;
}
