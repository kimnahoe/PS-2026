#include <stdio.h>
#include <stdlib.h>

int pick(int *item, int itemSize, int* bucket, int bucketSize, int k, int total)
{
	int i, lastIndex, smallest;
	int sum=0, ret=0, min=10000000;
	
	if (k == 0) {
		for (i = 0; i < bucketSize; i++) {
			//printf("%d ", item[bucket[i]]);
			sum += item[bucket[i]];
		}
		if(sum+sum > total) //음수 나오는 경우 방지 60 150인 경우, 150 60인 경우
			return sum+sum-total;
		//printf(": %d\n", sum);
		else
			return total-sum-sum;
	}
	
	lastIndex = bucketSize - k - 1; // 가장 최근에 뽑힌 수가 저장된 위치 index

	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1;

	for (i = smallest; i < itemSize; i++) {
		bucket[lastIndex + 1] = i;
		ret = pick(item, itemSize, bucket, bucketSize, k - 1, total);
		if(ret<min)
			min=ret;
	}
	
	return min;
}

int main() {
	int n;
	int *bucket;
	int *arr;
	int sum=0;

	scanf("%d", &n);
	
	bucket = (int*)malloc(sizeof(int)*(n/2));
	arr = (int*)malloc(sizeof(int)*n);
	
	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
		
	printf("%d", pick(arr, n, bucket, n/2, n/2, sum));

	free(bucket);
	free(arr);

	return 0;
}

