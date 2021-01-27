#include <stdio.h>
#define SIZE 500000

int check[SIZE];                 // 배열 선언. 자동 0으로 초기화

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
    for(i=0; i<lengthOfPartArr; i++)            // 숫자 개수만큼만 돌리면서 나온 숫자는 check 배열에 1 넣기
        check[partArr[i]]++;

    for(i=1; i<n+1; i++)                        // check 배열 숫자 끝까지만 돌리면서 0인 index 찾아 출력
       if(check[i]==0){
            printf("k=%d\n", i);
            break;                              // 0 찾으면 출력하고 바로 나오기
       }
    return 0;
}

