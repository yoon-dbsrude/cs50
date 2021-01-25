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
    QUEUE[0]='\0';  // 첫칸에 null

    while(1)
    {
        int i=select();       // 1~4 선택 출력

        switch(i)
        {
            case 1 :    queue_end=insert(queue_first, queue_end);   // =rear 값
                        //printf("front=%d, rear=%d\n", queue_first, queue_end);
                        //display(queue_first, queue_end);        // 지울 것
                        //printf("insert 이후 front=%d, rear=%d\n", queue_first, queue_end);
                        break;

            case 2 :    queue_first=del(queue_first, queue_end);
                        //printf("front=%d, rear=%d\n", queue_first, queue_end);
                        //display(queue_first, queue_end);
                        //printf("del 이후 front=%d, rear=%d\n", queue_first, queue_end);
                        break;

            case 3 :    //printf("front=%d, rear=%d\n", queue_first, queue_end);
                        display(queue_first, queue_end);


                        break;

            case 4 : return 0;
        }
    }
}


int select(void)        // 1~4 선택 출력
{
    int n;
    puts("1. 삽입");
    puts("2. 삭제");
    puts("3. 조회");
    puts("4. 종료");
    printf("입력 : ");
    scanf("%d", &n);

    return n;
}


int insert(int front, int rear)    // 1. 삽입 : rear +1
{
    if((rear-front)==10)    puts("큐가 꽉 찼습니다.");
    else
    {
        int num;
        printf("삽입할 값 : ");
        scanf("%d", &num);// 꽉 찼음

        QUEUE[rear++]=num;   // rear 자리에 숫자 삽입 후 바로 뒷자리에 null
        QUEUE[rear]='\0';
    }
    return rear;
}



int del(int front, int rear)     // 2. 삭제
{
    if(front==rear)    puts("큐가 비었습니다.");
    else
    {
        printf("큐에서 삭제됨 : %d\n", QUEUE[front]);
        QUEUE[front++]='\0';    // front 자리 null로 바꿈 & front는 +1
    }
    return front;
}



void display(int front, int rear)      // 3. 조회
{
    int i=0;
    printf("큐 : ");
    for(i=front; i<rear; i++)
        printf("%d ", QUEUE[i]);
    printf("\n");
}
