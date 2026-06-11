#include <stdio.h>
#include <stdlib.h>

int start1(int n, int *M, int *bp) {
	int i;
	int count=1;
	int end=-1;
	int index=0;
	int max=-1;
	
	for(i=0; i<n-1; i++) {
		if(M[i]>M[i+1]) {
			bp[index]=count;
			end=i;
			//length=end-count+1
			count=1;
			index++;
		}
			
		else
			count++;
			
	}
	for(i=0; i<index; i++) {
		if(max<bp[i])
			max=bp[i];
	}
	return max;
}

int main() {
	int n,i;
	int *M, *bp, *bucket;

	scanf("%d", &n);
	
	M = (int*)malloc(sizeof(int)*n);
	bp = (int*)malloc(sizeof(int)*n);
	//bucket = (int*)malloc(sizeof(int)*n);

	for(i=0; i<n; i++)
    	scanf("%d", &M[i]);
    for(i=0; i<n; i++)
    	bp[i]=0;

	printf("%d", start1(n, M, bp));
	
	/*int num=n;
	while(1) {
		printf("%d ", num);
		if(num == 1)
			break;
		num=bp[num];
	}
	*/

	free(M);

	return 0;
}
