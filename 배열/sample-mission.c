#include <cs50.h>         // 문자열을 string 으로 이용하고 싶어서 필요
#include <stdio.h>
#include <string.h>       // 학점 strcpy 쓰기 위해서 필요
#include <stdlib.h>      // atoi (문자열 -> 정수) 사용하기 위해 필요



const int NUMBER_PROBLEM=10;       // 문제 개수를 변수 NUMBER_PROBLEM으로 선언하고 앞으로 이 값을 10으로 고정하겠다
const int ANSWER[NUMBER_PROBLEM]={1,2,3,4,5,1,2,3,4,5};        // 문제 개수만큼의 배열 ANSWER을 생성하고 index 0~9 칸에 정답들로 초기설정

const int NUMBER_GRADE=9;     // 학점 등급은 9개
const int SCORE_GRADE[NUMBER_GRADE]={95,90,85,80,75,70,65,60,0};       // 학점을 나누는 기준 점수를 배열로 입력
const string CHAR_GRADE[NUMBER_GRADE]={"A+", "A", "B+", "B", "C+", "C", "D+", "D", "F"};     // 학점 배열


void print_correct_answer();      // 정답 출력
void print_student_answer();      // 학생 답안 출력

int cal();     // 학생 답안 맞은 개수 계산하는 함수
int total_score();      // 학생 최종 점수 계산하는 함수
void print_grade();        // 학점 출력 함수
int rescore();       // 총점 일의 자리 조정 함수   ex) 76점 -> 75점으로 생각해서 학점 출력하기 위해





// /***** main 시작 ******
int main(int argc, string argv[])  // 실행시키면서 학생답안 10개 입력함. argc: 학생답안개수 +1, 학생답은 argv[1]~argv[10]까지 저장
{
    // ***** 답안 개수 유효성 체크 : 개수가 제대로 입력되었나?
    if(argc != NUMBER_PROBLEM+1 )            // agrc = NUMBER_PROBLEM+1 이면 맞게 입력된 것  argv[0]은 실행파일명 입력됨.
    {
        printf("문제는 10문제입니다. 현재 %d개의 답안을 제출했습니다.\n", argc-1);
        printf("10개의 답안을 제출하세요.");
        return -1;                    // 답안 개수 잘못 입력한 경우라 -1 반환
    }




    // ****** argv[] : string 문자열로 받았기 때문에 문자열 배열 -> 숫자배열로 바꿈.
    // 답안범위 유효성 체크를 할 때 학생 답안을 숫자로 인식하여 1~5 사이인지 묻고 싶어서 문자열->숫자로 변환이 필요함.
    int student_answer[NUMBER_PROBLEM];     // 학생 답안으로 이루어진 숫자배열 student_answer 선언
    for(int i=0; i<NUMBER_PROBLEM; i++)      // student_answer[0]~[9] 에 학생답안 입력
        student_answer[i]=atoi(argv[i+1]);      // atoi : a(문자열) to(->) integer(정수)  변환함수




    // ***** 학생 답안 범위(1~5) 유효성 체크. student_answer에 입력된 학생 답안들은 숫자로 입력되어 있음.
    for(int i=0; i<NUMBER_PROBLEM; i++)
    {
        if(student_answer[i]>=1 && student_answer[i]<=5)       // 학생 답안이 1~5까지 입력되면 다음 i로 넘어가기
            continue;

        else{                // 학생 답안이 범위를 넘어가면 잘못되었다고 출력하고 종료하기
            puts("답의 범위는 1~5입니다. 범위 외의 답안이 있습니다.");
            return -1;
        }
    }





    // ***** 채점 *****
    int CORRECT_ANSWER_CNT=cal(student_answer);         // 학생 답안 맞은 개수를 CORRECT_ANSWER_CNT 변수로 선언 & cal 함수로 계산
    int TOTAL_SCORE=total_score(CORRECT_ANSWER_CNT);    // 위에서 계산한 맞은 개수를 이용해서 총점 계산하는 함수를 TOTAL SCORE로 선언
//    char GRADE=




    // ***** 결과 출력 *****
    puts("----------학점 평가 시작----------");
    printf("정  답 : ");              // 정답 출력 함수 : main 단순하게 두기 위해서 사용
    print_correct_answer();
    printf("학생답 : ");
    print_student_answer(student_answer);   // 학생 답안 출력 함수 : main 단순하게 두기 위해 사용. 학생답안은 main에서만 선언되었기 때문에 같이 넘겨줌.

    printf("정답수 : %d\n", CORRECT_ANSWER_CNT);    // 맞은 개수 출력
    printf("점  수 : %d\n", TOTAL_SCORE);             // 점수 출력
    printf("학  점 : ");      // 학점 출력
    //print_grade();

}  // main 끝





// **** 정답 출력 *****
void print_correct_answer()
{
    for(int i=0; i<NUMBER_PROBLEM; i++)
        printf("%d\t", ANSWER[i]);
    printf("\n");
}



// ***** 학생 답안 출력 *****
void print_student_answer(int student_answer[])          // 학생 답안 출력
{
    for(int i=0; i<NUMBER_PROBLEM; i++)
        printf("%d\t", student_answer[i]);        //출력할 때 \t 이용해서 간격 띄우기
    printf("\n");
}




// ***** 학생의 답안 중 맞는 것 개수 세는 함수 *****
int cal(int student_answer[])                    // 학생 답안 배열을 가져와서 초기설정 해 놓은 정답 배열과 비교
{
    int correct_answer_cnt=0;         // 학생 답안 개수 변수 선언 & 0으로 초기값 설정

    for(int i=0; i<NUMBER_PROBLEM; i++)
        if(student_answer[i]==ANSWER[i])        // index 0~9까지 i가 돌아가면서 학생답안과 정답을 비교,
            correct_answer_cnt++;           // 옳으면 학생답안 개수 +1씩

    return correct_answer_cnt;        // 학생 답안 맞은 개수를 main 함수에 반환함.

}




// ***** 최종 점수 계산 *****
int total_score(int correct_answer_cnt)            // 학생 답안 맞은 개수는 main에서 받아옴
{
    return 10*correct_answer_cnt;            // 한 문제당 10점이므로 10*맞은 개수를 main에 반환함
}




// ***** 학점 출력 *****
void print_grade(int total_score)
{
    string grade;      // 학점 복사하기 위한 문자열 선언
    int i;

    for(i=0; i<NUMBER_PROBLEM; i++)
    {
        if(total_score==100)  total_score=95;          // 100점인 경우 95점인 걸로 취급
        else if(total_score<60)   total_score=0;      // 60점 미만인 경우 0점으로 취급
        else if (total_score%5!=0)    total_score=rescore(total_score);     // 60~99점 중 5의 배수가 아닌 점수들에서 일의 자리 점수 조정하기
        if(total_score!=SCORE_GRADE[i])     continue;     // 학점 배열 index 0부터 9까지 돌리면서 총점과 다르면 다음으로 넘어가기
        strcpy(grade, CHAR_GRADE[i]);      // 학점 배열에서 해당 학점을 찾으면 grade 배열에 문자열 복사하기
        printf("%d\n", total_score);
        printf("%s", grade);
    }

   // printf("학점은 %s점 입니다.\n", grade);     // 학점 출력하기
}





// ***** 점수 조정 함수 *****       ex) 76점 -> 75점으로 취급해서 학점 찾기
int rescore(int num)        // 총점 넘겨 받아서 일의자리 조정하기
{
    int re_num;

    if(num%5!=0)    re_num=num-(num%5);    // 일의자리를 5로 나누었을 때 나머지가 0이 아니면 -> (총점-나머지)를 총점으로 생각하기
    return re_num;
}
v
