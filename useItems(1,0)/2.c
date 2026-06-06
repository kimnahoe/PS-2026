#include <stdio.h>
#include <stdlib.h>
//선택한 원소들이 k보다 크면서 뽑힌 개수가 가장 적은경우
int pick(int *arr, int n, int *bucket, int m, int toPick, int *a, int k) {
	int i, last_index, smallest;
	int ret, sum=0;
	int itemcount=0;
	int min=100000;
	
	if(toPick == 0) {
		for(i=0; i<m; i++) {
			if(arr[bucket[i]] == 1) {
				sum += a[i];
				itemcount++;
			}
		}
		if(sum >= k)
			return itemcount;
		return 100000;
	}

	last_index = m - toPick - 1;

	for(i=0; i<n; i++) {
		bucket[last_index+1] = i;
		ret = pick(arr, n, bucket, m, toPick -1, a, k); //itemcount
		if(ret<min)
			min=ret;
	}
	
	return min;
}

int main() {
	int N, K, i;
	int *arr;
	int *bucket;
	int items[2] = {0, 1};

	scanf("%d", &N);
	scanf("%d", &K);

	arr = (int*)malloc(sizeof(int)*N);
	bucket = (int*)malloc(sizeof(int)*N);
	
	for(i=0; i<N; i++) 
		scanf("%d", &arr[i]);

	printf("%d", pick(items, 2, bucket, N, N, arr, K)); //use item not use item

	free(arr);
	free(bucket);
	
	return 0;
}
