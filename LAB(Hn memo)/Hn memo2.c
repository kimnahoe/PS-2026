#include <stdio.h>
#include <stdlib.h>

int h_memo2(int n, int *m) {
	int i, ret;

	if(m[n] != 0)
		return m[n];

	if(n == 1 || n == 0) 
		return 1;

	ret = 0;
	for(i=0; i<n; i++) {
		ret = ret + h_memo2(i, m) * h_memo2(n-i-1, m);
	}
	
	m[n] = ret;
	
	return ret;
	
}

int main() {
	int n,i;
	int *M;

	n = 5;
	M = (int*)malloc(sizeof(int)*(n+1));
	
	for(i=0; i<n+1; i++)
		M[i] = 0;
	printf("%d\n", h_memo2(n, M));

	free(M);

	return 0;
}
