#include <stdio.h>
#include <stdlib.h>

#define friend_num 2

void min_calculator(int m, int M, int arr[]);    // ģ���� ������ �Ÿ��� �ּڰ� ��� & ���

int main(void)
{
    int house[friend_num]={4,5};
    int min=9999, max=-9999;
    int my_house;
    int i, len;

    for(i=0; i<friend_num; i++)
    {
        if(min>house[i]) min=house[i];          // ģ���� �߿� ���� ���� ���� ã��
        if(max<house[i]) max=house[i];          // ģ���� �߿� ���� ū ���� ã��
    }

    min_calculator(min, max, house);             // ģ���� ���� �Ÿ��� �ּڰ� ����ؼ� ��ġ ���

    return 0;
}


void min_calculator(int m, int M, int arr[])
{
    int sum[10]={0}, i, j, sum_min=99999;       // ���� ũ�⸸ŭ�� �迭�� �ʱ�ȭ �ȵ�. -> 10���� ����. �ִ�ũ��

    for(i=m; i<=M; i++)             // ģ���� ���� �ּڰ� ~ �ִ� ���̿� ��ġ�� �� �ּڰ��� ���� �� 
        for(j=0; j<friend_num; j++)
            sum[i]+=abs(arr[j]-i);     // sum �迭�� �� ���ڿ��� ģ�� ��������� �Ÿ��� �� ���ؼ� �ֱ�

    for(i=m; i<=M; i++)
        if(sum[i]<sum_min)      // �Ÿ� �ּڰ� ���ϱ�
            sum_min=sum[i];

    for(i=m; i<=M; i++)
        if(sum[i]==sum_min) printf("%d ", i);         // �Ÿ��� �ּ� �� ���� ���� ���� �� ��� ��� ���
}