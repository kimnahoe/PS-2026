#include <stdio.h>
#include <stdlib.h>

int one_memo(int n, int *m) {
	int i, ret;
	int count=0;

	if(m[n] != 0) //no same
		return m[n];

	if(n == 1) //end
		return count;

	ret = 0;
	for(i=n; i>=1; i--) {
		if(n%3==0)
			n/=3;
		else if(n%2==0)
			n/=2;
		else
			n-=1;
		ret = ret + one_memo(i, m);
		count++;
	}
	
	m[n] = ret;
	
	return ret;
	
}

int main() {
	int n,i;
	int *M;

	scanf("%d", &n);
	M = (int*)malloc(sizeof(int)*(n+1));
	
	for(i=0; i<n+1; i++)
		M[i] = 0;
	printf("%d\n", one_memo(n, M));

	free(M);

	return 0;
}
