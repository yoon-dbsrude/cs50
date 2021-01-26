#include <stdio.h>
#define SIZE 500000

int check[SIZE];

int main(int arge, char*argv[]) {
    int n;
    int i;

    scanf("%d", &n);

    // 1부터 N의 숫자중 K가 빠진 배열
    int partArr[SIZE];
    int lengthOfPartArr = n-1;

    for(i=0; i < lengthOfPartArr; i++){
        scanf("%d", &partArr[i]);
    }

    // TODO: n과 partArr를 이용하여, K를 구하라
    for(i=0; i<lengthOfPartArr; i++)
        check[partArr[i]]++;

    for(i=1; i<n+1; i++)
       if(check[i]==0){
            printf("k=%d\n", i);
            break;
       }
    return 0;
}

