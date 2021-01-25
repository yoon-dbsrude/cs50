#include <stdio.h>

#define N 11

int QUEUE[N];

int select();
int insert(int, int);
int del(int, int);
void display(int, int);


int main()
{
    int queue_end=0, queue_first=0;
    QUEUE[0]='\0';  // ùĭ�� null

    while(1)
    {
        int i=select();       // 1~4 ���� ���

        switch(i)
        {
            case 1 :    queue_end=insert(queue_first, queue_end);   // =rear ��
                        //printf("front=%d, rear=%d\n", queue_first, queue_end);
                        //display(queue_first, queue_end);        // ���� ��
                        //printf("insert ���� front=%d, rear=%d\n", queue_first, queue_end);
                        break;

            case 2 :    queue_first=del(queue_first, queue_end);
                        //printf("front=%d, rear=%d\n", queue_first, queue_end);
                        //display(queue_first, queue_end);
                        //printf("del ���� front=%d, rear=%d\n", queue_first, queue_end);
                        break;

            case 3 :    //printf("front=%d, rear=%d\n", queue_first, queue_end);
                        display(queue_first, queue_end);


                        break;

            case 4 : return 0;
        }
    }
}


int select(void)        // 1~4 ���� ���
{
    int n;
    puts("1. ����");
    puts("2. ����");
    puts("3. ��ȸ");
    puts("4. ����");
    printf("�Է� : ");
    scanf("%d", &n);

    return n;
}


int insert(int front, int rear)    // 1. ���� : rear +1
{
    if((rear-front)==10)    puts("ť�� �� á���ϴ�.");
    else
    {
        int num;
        printf("������ �� : ");
        scanf("%d", &num);// �� á��

        QUEUE[rear++]=num;   // rear �ڸ��� ���� ���� �� �ٷ� ���ڸ��� null
        QUEUE[rear]='\0';
    }
    return rear;
}



int del(int front, int rear)     // 2. ����
{
    if(front==rear)    puts("ť�� ������ϴ�.");
    else
    {
        printf("ť���� ������ : %d\n", QUEUE[front]);
        QUEUE[front++]='\0';    // front �ڸ� null�� �ٲ� & front�� +1
    }
    return front;
}



void display(int front, int rear)      // 3. ��ȸ
{
    int i=0;
    printf("ť : ");
    for(i=front; i<rear; i++)
        printf("%d ", QUEUE[i]);
    printf("\n");
}
