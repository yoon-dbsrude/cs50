#include <stdio.h>

int main()
{
    int n, m, i, j;
    int box[101];
    int cnt[101]={0};
    int cnt_max=-1;

    scanf("%d %d", &n, &m);         // ���� n, ���� m�� ��
    for(i=0; i<n; i++)             // ���� x, ���� y
        scanf("%d", &box[i]);

    for(i=0; i<n; i++)             // �Է¹��� ���ڵ� ���� ���ؼ� �����ʿ� ���� ���� ���� ����
    {                              // �������� ���� ������ ���� = ���ϰŸ�
        for(j=i+1; j<n; j++)       
            if(box[j]<box[i])   cnt[i]++;
        if(cnt_max<cnt[i])  cnt_max=cnt[i];      // ���ϰŸ�(cnt_max) �� �ִ� ã��
    }

    printf("���� ū ���ϰŸ� : %d", cnt_max);


}
