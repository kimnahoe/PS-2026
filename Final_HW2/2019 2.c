#include <stdio.h>
#include <stdlib.h>

long long h_memo2(int n, long long *m) {
	long long i, ret;

	if(m[n] != 0)
		return m[n];

	if(n == 1 || n == 0)
		return 1;

	ret = 0;
	if(n>1) {
		for(i=1; i<n; i++)
			ret = ret + i * h_memo2(n-i, m);
	}
	
	m[n] = ret;
	
	return ret;
	
}

int main() {
	int n,i;
	long long *M;

	scanf("%d", &n);
	
	M = (long long*)malloc(sizeof(long long)*(n+1));
	
	for(i=0; i<n+1; i++)
		M[i] = 0;
	printf("%lld\n", h_memo2(n, M));

	free(M);

	return 0;
}
