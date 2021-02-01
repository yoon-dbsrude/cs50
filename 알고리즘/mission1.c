#include <stdio.h>  // 정렬해서 비교하기


void num_sort(int arr[]);

int main(void)
{
    int a[5]={1,2,3,4,5};
    int b[5]={5,4,3,1,1};
    int i;

    num_sort(a);   // a배열 정렬하기
    num_sort(b);   // b배열 정렬하기

    for(i=0; i<5; i++)   // 정렬된 a, b 배열 비교하기
    {
        if(a[i]==b[i])  continue;
        printf("False");
        return -1;
    }
    printf("True");
    return 0;
}

void num_sort(int arr[])
{
    int i, j, tmp;

    for(i=0; i<4; i++)
        for(j=0; j<4-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
}
