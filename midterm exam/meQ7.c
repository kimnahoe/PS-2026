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
		return sum==key?1:0;
	}
	
	lastIndex = bucketSize - k - 1;

	for (i = 0; i <= lastIndex; i++)
		sum += item[bucket[i]]; //중간 중간 확인해주기
		
	if(sum > key) //가지치기 sum보다 많으면 그냥 바로 탈락
		return 0;
	else if(sum == key) //가지치기 sum 같으면 바로 성공
		return 1;

	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex];

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
	
	int *bucket=(int*)malloc(sizeof(int)*k); //1만 다 뽑는 경우 요소가 가장 많음 즉, k만큼 뽑기 가능
	int *arr=(int*)malloc(sizeof(int)*n);
	
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);
	
	printf("%d", pick(arr, n, bucket, k, k, k));
		
	free(arr);
	free(bucket);
	
	return 0;
}
