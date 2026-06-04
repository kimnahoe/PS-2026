//애초에 함수 보낼 때 초기 함수랑 같이 보내서.. 같은거 있으면 그대로 없으면 계산 수행..?
#include <stdio.h>
#include <stdlib.h>

int one_memo(int n, int* m) {
	int i, ret;

	if (m[n] != 0) //no same
		return m[n];
		
	if (n == 1) //end
		return 1;
		
	if (n % 3 == 0)
		ret = 1 + one_memo(n/3, m);
	else if (n % 2 == 0)
		ret = 1 + one_memo(n/2, m);
	else
		ret = 1 + one_memo(n-1, m);

	m[n] = ret;

	return ret;

}


int main() {
	int n, i;
	int* M, * m2, * m3;
	int max = -1;

	scanf("%d", &n);

	M = (int*)malloc(sizeof(int) * 100);
	for (i = 0; i < n; i++)
		M[i] = 0;
	int mm=one_memo(n, M);

	m2 = (int*)malloc(sizeof(int) * 100);
	for (i = 0; i < n; i++)
		m2[i] = 0;
	int m2c = one_memo(n, m2);

	if (mm < m2c)
		max = m2c;
	else
		max = mm;

	m3 = (int*)malloc(sizeof(int) * 100);
	for (i = 0; i < n; i++)
		m3[i] = 0;
	int m3c = one_memo(n, m3);

	if (mm < m3c)
		max = m3c;
	else
		max = mm;

	printf("%d", max);

	free(M);
	free(m2);
	free(m3);

	return 0;
}
