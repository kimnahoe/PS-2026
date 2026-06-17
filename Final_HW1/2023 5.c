#include <stdio.h>
#include <stdlib.h>

int pick(int itemSize, int* bucket, int bucketSize, int k, int key)
{
	int i, lastIndex, smallest;
	int count, ret;
	count=ret=0;
	
	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			if((bucket[i]+1)%2 == 0)
				count++;
		return count>=key?1:0;
	}
	
	for (i = 0; i < bucketSize; i++) // 1 3 뽑은 경우 2개 짝수 뽑아야 하는데 더이상 뽑을 수 X
		if((bucket[i]+1)%2 == 0)
			count++;
	if(count+k < key) //가지치기
		return 0;
	
	lastIndex = bucketSize - k - 1;

	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1;

	for (i = smallest; i < itemSize; i++) {
		bucket[lastIndex + 1] = i;
		ret += pick(itemSize, bucket, bucketSize, k-1, key);
	}
	
	return ret;
}

int main(void)
{
	int n, m, k;
	int sum = 0;
	scanf("%d", &n); //array count = 1 2 3
	scanf("%d", &m); //bucketSize = 3
	scanf("%d", &k);
	
	int *bucket=(int*)malloc(sizeof(int)*m);
	
	printf("%d", pick(n, bucket, m, m, k));
	
	free(bucket);
	
	return 0;
}
