// 12월 31일 수업2 + 1월 5일 수업
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define PI 3.14159265358979323846
// gcc filename.c -o filename -lm  //터미널 창에서 컴파일(실행준비)
// ./filename  //터미널 창에서 실행

// (12.30) 히스테리시스 배터리 잔량코드 
/*
int main(void)
{   

    // 히스테리시스 배터리 잔량 코드 작성
    int bat_num;
    int N;  
    double battery[100];
    int warning = 0; // 0: OFF, 1: ON
    printf("히스테리시스 경보 시스템\n");

    printf("배터리 잔량 데이터 개수 입력하시오: ");
    scanf("%d", &bat_num);

    int bat[bat_num+1];

    printf("배터리 잔량을 입력하시오(%%): \n");
    for(int i=0; i<bat_num;i++)
    {
        printf("%d번째 잔량: ", i);
        scanf("%d", &bat[i]);
    }
    if(bat[0]<=30)
    {
        printf("초기 상태: 경고 = ON\n");
        warning = 1;
    }
    else if(bat[0]>=35)
    {
        printf("초기 상태: 경고 = OFF\n");
        warning = 0;
    }

    for(int j=1; j<bat_num;j++)
    {
        if((warning == 1)&& bat[j]>=35)
        {
            warning = 0;
            printf("%d단계 잔량: %d 경고 상태: OFF\n", j, bat[j]);
        }
        else if((warning == 0)&& (bat[j]<=30))
        {
            warning = 1;
            printf("%d단계 잔량: %d 경고 상태: ON\n", j, bat[j]);
        }
        else
        {
            if(warning == 0)
            {
                printf("%d단계 잔량: %d 경고 상태: OFF 유지\n", j, bat[j]);
            }
            else if(warning == 1)
            {
                printf("%d단계 잔량: %d 경고 상태: ON 유지\n", j, bat[j]);
            }
        }
    }


    return 0;
}
*/ //히스테리시스 배터리 잔량코드

// 강의자료 1-2 IR센서 반사값 임계치 분류기
int threshold_class(int a, int b, int thres);
int main(void)
{
    int N, threshold;
    int black_count = 0;
    printf("적외선 센서 개수 입력: ");
    scanf("%d", &N);

    int value[N];
    for(int i=0;i<N;i++)
    {   
        printf("센서 값 입력: ");
        scanf("%d", &value[i]);
    }
    printf("임계값 입력: ");
    scanf("%d", &threshold);

    printf("label = ");
    for(int j = 0;j<N;j++)
    {
        black_count += threshold_class(j, value[j], threshold);
    }
    printf("\n");
    printf("black_count = %d\n", black_count);
    return 0;
}

int threshold_class(int x, int y, int thres)
{
    // x는 배열 몇번째인지, y는 배열요소
    int a, b = 0;
    int black =0;
    if(y > thres)
    {
        b = 1;
        printf("%d ", b);
        black = 1;
    }
    else if(y <= thres)
    {
        b = 0;
        printf("%d ", b);
        black = 0;
    }

    return black; 
}