#include <stdio.h>

int main(void)
{
    int num[5]={1,2,7,9,1};
    int i, j;
    
    for(i=0; i<4; i++)
        for(j=0; j<4-i ; j++)    // i=0 �� �� j=3����,  i=1�� �� j=2 ����  i=2�� �� j=1 ���� i=3�� �� j=0 
            if(num[j]>num[j+1])
            {
                int tmp=num[j];
                num[j]=num[j+1];
                num[j+1]=tmp;
            }

    for(i=0; i<5; i++)
        printf("%d", num[i]);

    return 0;
}