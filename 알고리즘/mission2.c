#include <stdio.h>
#include <stdlib.h>

#define friend_num 2

void min_calculator(int m, int M, int arr[]);    // 친구집 까지의 거리의 최솟값 계산 & 출력

int main(void)
{
    int house[friend_num]={4,5};
    int min=9999, max=-9999;
    int my_house;
    int i, len;

    for(i=0; i<friend_num; i++)
    {
        if(min>house[i]) min=house[i];          // 친구집 중에 제일 작은 숫자 찾기
        if(max<house[i]) max=house[i];          // 친구집 중에 제일 큰 숫자 찾기
    }

    min_calculator(min, max, house);             // 친구집 까지 거리의 최솟값 계산해서 위치 출력

    return 0;
}


void min_calculator(int m, int M, int arr[])
{
    int sum[10]={0}, i, j, sum_min=99999;       // 변수 크기만큼의 배열은 초기화 안됨. -> 10으로 잡음. 최대크기

    for(i=m; i<=M; i++)             // 친구집 숫자 최솟값 ~ 최댓값 사이에 위치할 때 최솟값이 나올 것 
        for(j=0; j<friend_num; j++)
            sum[i]+=abs(arr[j]-i);     // sum 배열에 각 숫자에서 친구 집들까지의 거리의 합 구해서 넣기

    for(i=m; i<=M; i++)
        if(sum[i]<sum_min)      // 거리 최솟값 구하기
            sum_min=sum[i];

    for(i=m; i<=M; i++)
        if(sum[i]==sum_min) printf("%d ", i);         // 거리가 최소 인 곳이 여러 군데 일 경우 모두 출력
}