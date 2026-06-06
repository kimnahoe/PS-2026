#include <stdio.h>
#include <stdlib.h>

int pick(int *arr, int n, int *bucket, int m, int toPick, int *a, int k) {
	int i, last_index, smallest;
	int ret, sum=0, max, count=0;

	if(toPick == 0) {
		for(i=0; i<m; i++) {
			if(arr[bucket[i]] == 1)
				sum += a[i];
			//printf("%d ", sum); 
		}
		
		return sum==k?1:0;
	}

	last_index = m - toPick - 1;

	for(i=0; i<n; i++) {
		bucket[last_index+1] = i;
		count += pick(arr, n, bucket, m, toPick - 1, a, k);
			
	}
	return count;
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
