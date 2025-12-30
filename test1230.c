#include <stdio.h>

int sum(int x, int y);  //두가지 입력 합 함수
int max(int x, int y, int z);  //세가지 입력 최대값 함수
double avg(double x, double y);
double rad_deg(int x, double y); // x가 0이면 rad->deg 1이면 deg->rad
int get_num(void);  //숫자 하나 입력받는 함수
//#define 쓸때는, 상수명 대문자로 사용추천
#define PI 3.14159265358979323846
int main(void)
{   

    /*
    int a =1;

    while (a<10)
    {
        a = a *2;
    }
    printf("a : %d\n", a);

    return 0;
    */
    //////////////////////////////////////////////
    /*
    int i, j, k, l;

    for (i = 0; i < 5; i++)
    {
        for(j=0; j<i+1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for (k = 5; k > 1;k--)
    {
        for(l=1; l < k; l++)
        {
            printf("*");
        }
        printf("\n");
    }

    int ii, jj, kk, ll;
    for (ii=1; ii<10;ii++)
    {
        for(jj=1; jj<10;jj++)
        {
            printf("%d*%d=%d ",ii, jj, ii*jj);

        }
        printf("\n");
    }
    */
    //////////////////////////////////////
    /*
    int i;
    int sum = 0;

    for(i = 1; i <= 10; i++)
    {
        sum += i;
        if(sum > 30) break;  //break는 그 루프 벗어나기

    }
    printf("누적한 값 : %d\n", sum);
    printf("마지막으로 더한 값 : %d\n", i);
    */

    /////////////////////////////////////////////////

    /*

    /////1번 문제 중첩 반복으로 x자 별표 만들기/////
    int i, j;

    for (i = 0; i < 5; i++)
    {
        for(j=0; j<5; j++)
        {
            if((i == j) || ((i+j)==4))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    ///////////////함수 활용 실습 start/////////////////////
    int a = 10, b = 20, c = 25;
    int sum_result, max_result;

    sum_result = sum (a, b);
    max_result = max(a, b, c);

    printf("sum_result : %d\n", sum_result);
    printf("max_result : %d\n", max_result);
    // 2번 문제 두 수의 평균을 구하는 코드 제작 (함수로 구현)

    double q, w;
    printf("두 수의 평균 구하는 코드\n");
    printf("입력1 : ");
    scanf("%lf", &q);
    printf("입력2 : ");
    scanf("%lf", &w);
    printf("평균값 : %.2lf\n", avg(q,w));

    //3번 과제 degree 값을 radian으로 변환하는 코드 (함수)
    //radian 값을 degree값으로 변환하는 코드 (함수)

    int aa;
    double bb;

    printf("\ndegree-radian 변환기\n");
    printf("rad->deg는 0, deg->rad은 1 입력 : ");
    scanf("%d", &aa);
    if(aa == 0)
    {
        printf("radian 값을 입력하시오 : ");
    }
    else if(aa ==1)
    {
        printf("degree 값을 입력하시오 : ");
    }
    scanf("%lf", &bb);

    printf("입력값: %.2lf 변환값: %.2lf\n", bb, rad_deg(aa, bb));
    //////// 함수 활용 실습 end/////////////////


    */

    /////////////////////////
    /*
    int a, b, c, d, e, f, g, h, i, j;

    a = get_num();
    b = get_num();
    c = get_num();
    d = get_num();
    e = get_num();
    f = get_num();
    printf("합 : %d\n", a+b+c+d+e+f);
    */
    ////////////////////////////

    int ary[5];

    ary[0] = 10;
    ary[1] = 20;
    ary[2] = ary[0]+ary[1];
    scanf("%d", &ary[3]);

    printf("%d\n", ary[2]);
    printf("%d\n", ary[3]);
    printf("%d\n", ary[4]);

    return 0;
}

int sum(int x, int y)  //앞에서 함수 선언 해주자 함수가 뒤에 있으므로
{
    int temp;
    temp = x+y;
    return temp;
}

int max(int x, int y, int z)  //또는 함수 자체를 코드 앞에 배치하면 함수 선언 필요없다
{
    int maxnum = x;
    if(y > maxnum)
    {
        maxnum = y;
    }
    if(z > maxnum)
    {
        maxnum = z;
    }
    return maxnum;
}

double avg(double x, double y)
{
    double avg_1 = (x + y) / 2;
    return avg_1;
}
double rad_deg(int x, double y) //x가 0이면 rad->deg 1이면 deg->rad
{
    double result;
    if(x == 0)
    {
        result = y * 180 / PI;
    }
    else if(x == 1)
    {
        result = y / 180 * PI;
    }

    return result;
}

int get_num(void)
{
    int num;

    printf("양수 입력 : ");
    scanf("%d", &num);

    return num;
}