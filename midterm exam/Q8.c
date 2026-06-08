#include <stdio.h>
#include <stdlib.h>

int pick(int *item, int itemSize, int* bucket, int bucketSize, int k, int s)
{
	int i, lastIndex, smallest;
	int sum=0, count=0;
	
	if (k == 0) {
		for(i=0; i<bucketSize-1; i++) {
			if(item[bucket[i]] != item[bucket[i+1]])
				sum+=item[bucket[i]];
			else
				return 0;
		}
		sum+=item[bucket[i]];
		return sum==s?1:0;
	}
	lastIndex = bucketSize - k - 1;
	smallest = 0;
	for (i = smallest; i < itemSize; i++) {
		bucket[lastIndex + 1] = i;
		count += pick(item, itemSize, bucket, bucketSize, k - 1, s);
	}
	return count;
}


int main(void)
{
	int N, K, S, i;
	int *arr;
	int *bucket;

	scanf("%d", &N); //length
	scanf("%d", &K); //until K
	scanf("%d", &S); //total sum

	arr = (int*)malloc(sizeof(int)*N);
	bucket = (int*)malloc(sizeof(int)*N);
	
	for(int i=0; i<K; i++)
		arr[i]=i+1;

	printf("%d", pick(arr, K, bucket, N, N, S)); //use item not use item

	free(arr);
	free(bucket);
	
	return 0;
}
