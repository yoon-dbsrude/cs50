#include <stdio.h>

int main(void)
{
    int num[5]={7,1,9,2,1};
    int i, j, tmp, min, index;


    for(i=0; i<5; i++)
    {
        min=999;
        for(j=i; j<5; j++)
           if(min>num[j])
           {
                min=num[j];  // ÃÖ¼Ú°ª Ã£±â
                index=j;
           }

        tmp=num[index];
        num[index]=num[i];
        num[i]=tmp;
    }

    for(i=0; i<5; i++)
        printf("%d", num[i]);

    return 0;
}
