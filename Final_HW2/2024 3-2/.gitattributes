#include <stdio.h>
#include <stdlib.h>

int pick(int *item, int itemSize, int* bucket, int bucketSize, int k)
{
	int i, lastIndex, smallest;
	int count=0;
	if (k == 0) {
		return 1;
	}
	lastIndex = bucketSize - k - 1;

	for (i = 0; i < itemSize; i++) {
		int flag = 0;
			if (lastIndex >= 0 && i == bucket[lastIndex]) //현재 선택하려는 인덱스 i가 bucket안에 있으면 뽑지 말아라 continue
				flag = 1; //bucket안에 인덱스 번호가 들어감
		if (flag == 1) continue; //밑에 수행하지 말고 계속 반복문 실행 

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
