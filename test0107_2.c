// 1월 7일 수업 2
// 변수
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define PI 3.14159265358979323846
// gcc filename.c -o filename -lm  //터미널 창에서 컴파일(실행준비)
// ./filename  //터미널 창에서 실행

void assign10(void);
void assign20(void);
// 전역 변수는 메인함수와 다른 함수 *밖* 에서 선언 
int a;  //@@ 전역 변수는 선언만 해도 0으로 초기화해준다.@@ 지역 변수는 자동으로 초기화 안해준다.

void auto_func(void);
void static_func(void);
int *sum(int a, int b);
void swap_ptr(char **ppa, char **ppb);

int main(void)
{
    /*
    printf("함수 호출 전 a 값 :%d\n", a);

    assign10();
    assign20();

    printf("함수 호출 후 a 값 :%d\n", a);

    return 0;
    */

    // 정적 지역 변수
    /*
    int i;
    printf("일반 지역 변수(auto)를 사용한 함수...\n");
    for(i=0;i<3;i++)
    { 
        auto_func();
    }
    printf("정적 지역 변수(static)를 사용한 함수...\n");
    for(i=0;i<3;i++)
    { 
        static_func();
    }
    return 0;
    */
    /*
    // 레지스터 변수
    register int i;
    auto int sum= 0;

    for(i = 1; i <= 10000;i++)
    {
        sum += i;
    }
    printf("%d\n", sum);
    return 0;
    */
    /*
    int *resp;
    resp = sum(10, 20);
    printf("두 정수의 합 : %d\n", *resp);
    return 0;
    */
        
    //2차원 배열 
    /*
    char animal[5][20];
    int i;
    int count;

    count = sizeof(animal) / sizeof(animal[0]);
    for(i=0;i<count;i++)
    {
        scanf("%s", animal[i]);
    }
    for(i=0;i<count;i++)
    {
        printf("%s ", animal[i]);
    }
    return 0;
    */
    /*
    // 3차원 배열 예제 14-5 
    int score[2][3][4] = {
        {{72, 80, 95, 60}, {68, 98, 83, 90}, {75, 72, 84, 90}},
        {{66, 85, 90, 88}, {95, 92, 88, 95}, {43, 72, 56, 75}}
    };
    int i, j, k;

    for(i=0; i<2; i++)
    {
        printf("%d반 점수...\n", i+1);
        for(j=0;j<3;j++)
        {
            for(k=0;k<4;k++)
            {
                printf("%5d", score[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
    */
    /*
    // 포인터 배열
    int ary1[4] = {1, 2, 3, 4};
    int ary2[4] = {11, 12, 13, 14};
    int ary3[4] = {21, 22, 23, 24};
    int *pary[3] = {ary1, ary2, ary3};
    int i, j;

    for (i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%5d", pary[i][j]);
        }
        printf("\n");
    }

    return 0;
    */

    /*
    // 배열의 값 계산하기 문제
    // 문제: 가로세로의 합 구하기
    //초기화된 배열에서 마지막 열의 요소에는 각 행의 합을 저장, 마지막 행 요소에는
    // 각 열의 합을 저장한 후 전체 배열의 값을 출력하라
    int ary1[5][6] = {
        {1, 2, 3, 4, 5}, 
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {}
    };
    int i=0, j=0, k=0;

    /* //기존 내가 짠 코드로 중첩 for문을 3개를 썼다. 
    for(i=0;i<4;i++)
    {
        for(j=0;j<5;j++)
        {
            ary1[i][5] += ary1[i][j]; 
        }
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<4;j++)
        {
            ary1[4][i] += ary1[j][i];
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<5;j++)
        {
            ary1[i][5] += ary1[i][j]; 
        }
    }
    */  //기존 내가 짠 코드로 중첩 for문을 3개를 썼다. 

    // 중첩 for문을 3개나 쓸 필요가 없었다. 
    /*
    for(i=0;i<4;i++)  //for문을 하나로 줄여서 구현하기
    {
        for(j=0;j<5;j++)
        {
            ary1[i][5] += ary1[i][j];  // 마지막 열의 요소에 각 행의 합 
            ary1[4][j] += ary1[i][j];
            ary1[4][5] += ary1[i][j]; 

        }
    }

    for(i=0;i<5;i++)
    {
        for(j=0;j<6;j++)
        {
            printf("%5d", ary1[i][j]);
        }
        printf("\n");
    }
    return 0;
    */

    char *pa = "success";
    char *pb = "failure";

    printf("pa -> %s, pb -> %s\n", pa, pb);
    swap_ptr(&pa, &pb);
    printf("pa -> %s, pb -> %s\n", pa, pb);

    return 0;
}
void assign10(void)
{
    a = 10;
}
void assign20(void)
{
    //int a;  //여기서 재선언해서 지역변수로 
    a = 20;
}

void auto_func(void)
{
    auto int a = 0;

    a++;
    printf("%d\n", a);
}
void static_func(void)
{
    static int a;
    a++;
    printf("%d\n", a);
}
int *sum(int a, int b)
{
    static int res;
    res = a+b;
    return &res;
}

void swap_ptr(char **ppa, char **ppb)
{
    char *pt;

    pt = *ppa;
    *ppa = *ppb;
    *ppb = pt;
}