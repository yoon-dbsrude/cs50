#include <stdio.h>

int main()
{
	int a[5] = { 3,1,2,1,1 };
	int b[5] = { 1,1,1,2,3 };

	int i, j;
	int check[10] = { 0 };   // a, b 배열에 입력되는 수는 모두 한 자리 숫자라 가정

	for (i = 0; i < 5; i++)
		check[a[i]]++;            // a 배열에 있는 숫자들 index 에 그 개수만큼 저장됨 

	for (i = 0; i < 5; i++)
		check[b[i]]--;            // b 배열에 있는 숫자들 index에 그 개수만큼 뺌

	for (i = 0; i < 10; i++)
		if (check[i] != 0)       // check 배열이 모두 0이 아닌 경우 -> a, b 배열에 다른 숫자가 있음
		{
			printf("False\n");
			return -1;
		}

	printf("True\n");          // check 배열이 모두 0인 경우 -> a, b 배열 같음
	return 0;
}
