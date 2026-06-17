#include <stdio.h>
#include <stdlib.h>
//backpointer 활용하기

int start1(int n, int *M, int *bp) {
	int min=10000000;
	int ret=0;
	
	
	if(M[n] != 0)
		return M[n];
		
	if(n == 1)
		return 0;
	else {		
		if(n%3==0) {
			ret = start1(n/3, M, bp) + 1;
			if(ret<min) {
				min=ret;
				bp[n]=n/3;
			}
		}
		if(n%2==0) {
			ret = start1(n/2, M, bp) + 1;
			if(ret<min) {
				min=ret;
				bp[n]=n/2;
			}
			
		}
		if(n != 1) {
			ret = start1(n-1, M, bp) + 1;
			if(ret<min) {
				min=ret;
				bp[n]=n-1;
			}
		}
			
		M[n] = min;
				
		return min;
	}
}

int main() {
	int n,i;
	int *M, *bp;

	scanf("%d", &n);
	
	M = (int*)malloc(sizeof(int)*(n+1));
	bp = (int*)malloc(sizeof(int)*(n+1));

	for(i=0; i<=n; i++) {
    	M[i] = -1;
    	bp[i] = 0;
    }

	printf("%d\n", start1(n, M, bp));
	
	int num=n;
	
	while(1) {
		printf("%d ", num);
		if(num == 1)
			break;
		num=bp[num];
	}

	free(M);

	return 0;
}
