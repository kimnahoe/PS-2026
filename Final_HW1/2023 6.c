#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int make_number(int *items, int m, char *s)
{
	int number = 0;
	int i;
	int len=strlen(s);
	
	for(i=0; i<len; i++)
		number = number*10 + items[s[i]-'A']+1;
		
	return number;
}

int pick(int* bucket, int bucketSize, int k, char *str1, char *str2)
{
	int i, lastIndex, smallest;
	int sum, ret, max;
	sum=ret=max=0;
	
	if (k == 0) {
		//for (i = 0; i < bucketSize; i++)
			//printf("%d %c ", bucket[i]+1, 'A'+i);
		sum = make_number(bucket, bucketSize, str1)+make_number(bucket, bucketSize, str2);
		//printf("number = %d\n", sum);
		return sum;
	}
	lastIndex = bucketSize - k - 1;
	smallest = 0;
	for (i = smallest; i < bucketSize; i++) {
		int j = 0; int flag = 0;
		for (j = 0; j <= lastIndex; j++)
			if (bucket[j] == i)
				flag = 1;
		if (flag == 1) continue;
		bucket[lastIndex + 1] = i;
		ret = pick(bucket, bucketSize, k - 1, str1, str2);
		if(max<ret)
			max=ret;
	}
	return max;
}


int main(void)
{
	char str1[6];
	char str2[6];
	
	scanf("%s", str1);
	scanf("%s", str2);

	int *bucket=(int*)malloc(sizeof(int)*5);
	
	printf("%d", pick(bucket, 5, 5, str1, str2));
	
	free(bucket);
	
	return 0;
}
