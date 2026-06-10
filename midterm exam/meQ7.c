#include <stdio.h>
#include <stdlib.h>

int pick(int *item, int itemSize, int* bucket, int bucketSize, int k, int key)
{
	int i, lastIndex, smallest;
	int sum = 0;
	int count=0;
	
	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			sum += item[bucket[i]];
		/*if(sum == key) {
			for(i=0; i<bucketSize; i++)
				printf("%d ", item[bucket[i]]);
		}
		printf("\n");
		*/
		return sum==key?1:0;
	}
	
	lastIndex = bucketSize - k - 1; // 가장 최근에 뽑힌 수가 저장된 위치 index

	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex]; // 이부분만 combination과 차이

	for (i = smallest; i < itemSize; i++) {
		bucket[lastIndex + 1] = i;
		count += pick(item, itemSize, bucket, bucketSize, k - 1, key);
	}
	
	return count;
}

int main(void)
{
	int n, k, i;
	scanf("%d", &n);
	scanf("%d", &k);
	
	int *bucket=(int*)malloc(sizeof(int)*n);
	int *arr=(int*)malloc(sizeof(int)*n);
	
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);
		
	printf("%d", pick(arr, k, bucket, k, k, k));
		
	free(arr);
	free(bucket);
	
	return 0;
}
