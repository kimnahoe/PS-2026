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
	
	bucket[0]=0;	
	printf("%d", pick(arr, n, bucket, n/2-1, n/2-1, sum)); //불필요한 계산 할 필요X 첫 번째 수와 그게 안나왔을 때랑 비교하면 똑같음
	//60 90, 90 60 둘 다 return 값이 같은데 굳이 2번 계산 할 필요X

	free(bucket);
	free(arr);

	return 0;
}

