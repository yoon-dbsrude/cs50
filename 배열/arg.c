#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if(argc==2)             // 추가 입력하는 것은 index 1부터~
    {
        printf("hello, %s\n", argv[1]);
    }
    else
    {
        printf("hello, world\n");a
    }
}


/* 입력  
>>> ./arg.exe yoon             // argc[0]=./arg.exe ,  argc[1]=Yoon
hello, yoon
>>> ./arg.exe
hello, world
*/
