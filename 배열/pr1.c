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
    print_scoretable();     // 학점 테이블 출력

    
    while(1)
    {
        int student_score = input_score();          // 학점 입력
        if(student_score==999)
        {
            puts("학점 프로그램을 종료합니다.");   
            return 0;
        }
        if(student_score==-1)  continue;

        print_grade(student_score);              // 학점 출력
    }
}


void print_scoretable()         // 학점 테이블 출력
{
    int i;
    puts("학점 프로그램");
    puts("종료를 원하면 \"-1\"을 입력\n");
    puts("[학점  테이블]");
    printf("점수 : ");
    for(i=0; i<9; i++)
        printf("%-6d", SCORE_GRADE[i]);

    printf("\n학점 : ");
    for(i=0; i<9; i++)
        printf("%-6s", CHAR_GRADE[i]);

    printf("\n");
}


int input_score()           // 학생 성적 입력
{
    int score;
    
    printf("성적을 입력하세요 (0 ~ 100) : ");
    scanf("%d", &score);

    if(score==999)   return 999;

    if(score>=0 && score<=100)
        return score;
    else
    {
        printf("**성적을 올바르게 입력하세요. 범위는 0 ~ 100 입니다.\n");      //유효성 체크
        return -1;
    }
} 


void print_grade(int student_score)      // 학점 출력
{
    char grade[3];
    int i;

    for(i=0; i<N; i++)
    {       
        if(student_score==100)  student_score=95;
        else if(student_score<60)   student_score=0;
        else if (student_score%5!=0)    student_score=rescore(student_score);     // %5 나머지 있는 경우 점수 조정
        if(student_score!=SCORE_GRADE[i])   continue;
        strcpy(grade, CHAR_GRADE[i]);
    }
    printf("학점은 %s 입니다.\n", grade);
}


int rescore(int num)        // 점수 조정 함수 
{
    int re_num;
    
    if(num%5!=0)    re_num=num-(num%5);
    return re_num;
}
