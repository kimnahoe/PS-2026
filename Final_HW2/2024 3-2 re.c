#include <stdio.h>
#include <stdlib.h>

int pick(int *item, int itemSize, int* bucket, int bucketSize, int k)
{
	int i, lastIndex, smallest;
	int count=0;
	if (k == 0) {
		for (i = 0; i < bucketSize-1; i++) {
			if(item[bucket[i]] == item[bucket[i+1]]) {
				return 0;
			}
		}
		
		return 1;
	}
	lastIndex = bucketSize - k - 1;
	smallest = 0;
	for (i = smallest; i < itemSize; i++) {
		bucket[lastIndex + 1] = i;
		count += pick(item, itemSize, bucket, bucketSize, k - 1);
	}
	return count;
}


int main(void)
{
	int M, N;
	scanf("%d", &M);
	scanf("%d", &N);
	
	int *item=(int*)malloc(sizeof(int)*M);
	for(int i=0; i<M; i++)
		item[i]=i+1;
	int *bucket=(int*)malloc(sizeof(int)*N);
	
	printf("%d", pick(item, M, bucket, N, N));
	
	free(bucket);
	free(item);
	
	return 0;
	
}
