#include <stdio.h>
#include <stdlib.h>

void pick(int *item, int itemSize, int* bucket, int bucketSize, int k, int total)
{
	int i, lastIndex, smallest;
	int sum;
	int count=0;
	
	if (k == 0) {
		sum=0;
		for (i = 0; i < bucketSize; i++) {
			sum+=item[bucket[i]];
			printf("%d ", item[bucket[i]]);
		}
		printf("\n");
		
		return;
		//return(sum==total)?1:0;
	}
	
	lastIndex = bucketSize - k - 1;

	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex];

	for (i = smallest; i < itemSize; i++) {
		bucket[lastIndex + 1] = i;
		pick(item, itemSize, bucket, bucketSize, k - 1, total);
	}
	
}

int main(void)
{
	int n, m, sum = 0;
	scanf("%d", &n);
	scanf("%d", &m);
	
	int *bucket=(int*)malloc(sizeof(int)*m);
	int *array=(int*)malloc(sizeof(int)*n);
	
	for(int i=0; i<n; i++)
		scanf("%d", &array[i]);
	
	for(int i=1; i<=m; i++)
		pick(array, n, bucket, i, i, m); //i만큼 만들기
	
	free(array);
	free(bucket);
	
	return 0;
}
