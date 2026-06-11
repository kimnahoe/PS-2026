#include <stdio.h>
#include <stdlib.h>

void pick(int itemSize, int* bucket, int bucketSize, int k)
{
	int i, lastIndex, smallest;
	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%d ", bucket[i] + 1); //뽑은 bucket에 +1을 해주면 된다. bucket은 순서니까
		printf("\n");
		return;
	}
	lastIndex = bucketSize - k - 1;

	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1;

	for (i = smallest; i < itemSize; i++) {
		bucket[lastIndex + 1] = i;
		pick(itemSize, bucket, bucketSize, k - 1);
	}
}



int main(void)
{
	int n, m, sum = 0;
	scanf("%d", &n); //array count = 1 2 3
	scanf("%d", &m); //bucketSize = 3
	
	int *bucket=(int*)malloc(sizeof(int)*m);
	int *array=(int*)malloc(sizeof(int)*n);
	
	pick(n, bucket, m, m);
	
	free(array);
	free(bucket);
	
	return 0;
}
