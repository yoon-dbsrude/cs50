#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 9

const int SCORE_GRADE[N]={95,90,85,80,75,70,65,60,0};
const char CHAR_GRADE[N][3]={"A+","A","B+","B","C+","C","D+","D","F"};

void print_scoretable();
int input_score();
int rescore(int);
void print_grade(int);


int main()
{
    print_scoretable();     // ���� ���̺� ���

    
    while(1)
    {
        int student_score = input_score();          // ���� �Է�
        if(student_score==-1)   return 0;

        print_grade(student_score);              // ���� ���
    }
}


void print_scoretable()         // ���� ���̺� ���
{
    int i;
    puts("���� ���α׷�");
    puts("���Ḧ ���ϸ� \"-1\"�� �Է�\n");
    puts("[����  ���̺�]");
    printf("���� : ");
    for(i=0; i<9; i++)
        printf("%-6d", SCORE_GRADE[i]);

    printf("\n���� : ");
    for(i=0; i<9; i++)
        printf("%-6s", CHAR_GRADE[i]);

    printf("\n");
}


int input_score()           // �л� ���� �Է�
{
    int score;
    printf("������ �Է��ϼ��� (0 ~ 100) : ");
    scanf("%d", &score);

    if(score>=0 && score<=100)
        return score;
    else
        return -1;
} 


void print_grade(int student_score)      // ���� ���
{
    char grade[3];
    int i;

    for(i=0; i<N; i++)
    {       
        if(student_score==100)  student_score=95;
        else if(student_score<60)   student_score=0;
        else if (student_score%5!=0)    student_score=rescore(student_score);     // %5 ������ �ִ� ��� ���� ����
        if(student_score!=SCORE_GRADE[i])   continue;
        strcpy(grade, CHAR_GRADE[i]);
    }
    printf("������ %s �Դϴ�.\n", grade);
}


int rescore(int num)        // ���� ���� �Լ� 
{
    int re_num;
    
    if(num%5!=0)    re_num=num-(num%5);
    return re_num;
}
