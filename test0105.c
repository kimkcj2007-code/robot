// 12월 31일 수업 + 1월 5일 수업
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define PI 3.14159265358979323846
// gcc filename.c -o filename -lm  //터미널 창에서 컴파일(실행준비)
// ./filename  //터미널 창에서 실행

void swap(int* pa, int* pb);
int(main)(void)
{   
    /*
    int a;
    double b;
    char c;

    printf("int형 변수의 주소 : %u\n", &a);
    printf("double형 변수의 주소 : %u\n", &b);
    printf("char형 변수의 주소 : %u\n", &c);
    
    return 0;
    */

    /*
    int a;
    int *pa; //포인터 선언

    pa = &a;
    *pa = 10;

    printf("포인터로 a 값 출력 : %d\n", *pa); //100번지 의 값 
    // (100번지 안에 있는 값)
    //printf("포인터로 a 값 출력 : %d\n", pa);
    printf("변수명으로 a 값 출력 : %d\n", a);
    return 0;
    */

    /*
    int a = 10, b = 15, total;  //a주소 100번지, b주소 200번지, total 주소 300번지로 가정
    double avg; //avg 주소값 400으로 가정
    int *pa, *pb; // 500, 600번지 가정
    int *pt = &total;  // 700번지로 가정하고, 그 값이 300번지의 값(300번지가 가리키는 값)이라 함
    double *pg = &avg;  // 800번지로 가정하고, 그 값이 400번지의 값(400번지가 가리키는 값)이라 함

    pa = &a;  //a의 주소가 pa에 담김
    pb = &b;  //b의 주소가 pb에 담김

    *pt = *pa + *pb;
    *pg = *pt / 2.0;  //pt가 가리키는 값 

    //printf("테스트값 : %d\n", total);  //값 출력해보기
    printf("두 정수의 값 : %d, %d\n", *pa, *pb);  //pa가 가리키는 주소안의 값
    printf("두 정수의 합 : %d\n", *pt);  //pt에 있는 주소값(그 위치)의 값
    printf("두 정수의 평균 : %.1lf\n", *pg); // pg에 있는 주소값(그 위치)의 값
    //

    return 0;
    */

    /*
    char ch;
    int in;
    double db;

    char *pc = *&ch;
    int *pi = &in;
    double *pd = &db;
    
    printf("char형 변수의 주소 크기 : %d\n", sizeof(&ch));
    printf("int형 변수의 주소 크기 : %d\n", sizeof(&in));
    printf("double형 변수의 주소 크기 : %d\n", sizeof(&db));

    printf("char * 포인터의 크기 : %d\n", sizeof(pc));
    printf("int * 포인터의 크기 : %d\n", sizeof(pi));
    printf("double * 포인터의 크기 : %d\n", sizeof(pd));

    printf("char * 포인터가 가리키는 변수의 크기 : %d\n", sizeof(*pc));
    printf("int * 포인터가 가리키는 변수의 크기 : %d\n", sizeof(*pi));
    printf("double * 포인터가 가리키는 변수의 크기 : %d\n", sizeof(*pd));

    return 0;
    */
    /*
    int a = 10;
    int *p = &a;
    //double *pd;  //형 통일 과제 1번 2번 3번 문제
    int *pd;  // double이었던 변수형을 int로 통일하고
    pd = p;
    //pd = p;  //3번
    //printf("%d\n", *(int *)pd); //3번
    //pd = (double *)p;  //2번
    //(int *)pd = p;  //1번
    //printf("%lf\n", *pd);  //2번
    //printf("%d\n", *pd);  //1번
    printf("%d\n", *pd);  //%f였던 것을 %d로 변경하니까 값이 제대로 나온다.
    // pd가 사용한 영역이 double형태일 때 8바이트를 사용하다보니, 4바이트를 사용하던 값을 가져와서 이상한 값 나옴
    
    //2번이 안되는 이유? 결국 들어가있는 값은 int형인데 double로 읽어봤자 의미가 없다. 
    //결국, 출력할 때 타입을 맞춰줘야 출력이 될 것이다. (형변환은 3번만 가능)
    return 0;
    */

    /*
    int a = 10, b = 20 ;
    //swap(&a, &b); 포인터 사용했을 때, 
    swap(&a,&b);
    printf("a:%d, b:%d\n",a,b);
    return 0;
    */

    /*
    int ary[3];
    int *pa = ary;  //pa를 배열명처럼 사용하더라 
    int i;

    *pa = 10;
    *(pa + 1) = 20;
    pa[2] = pa[0] + pa[1];

    for(i=0;i<3;i++)
    {
        printf("%5d", pa[i]);
    }
    printf("\n");
    return 0;
    */

    /*
    int ary[3] = {10, 20, 30};
    int *pa = ary;
    int i;

    printf("배열의 값 : ");
    for(i=0;i<3;i++)
    {
        printf("%d ", *pa);
        printf("%u ", pa);  //확인하고 싶은 값
        pa++;
    }
    printf("\n");

    return 0;
    */

    int ary[5] = {10, 20, 30, 40, 50};
    int *pa = ary;
    int *pb = pa +3;


    printf("pa : %u\n", pa);
    printf("pb : %u\n", pb);

    pa++;
    printf("pb - pa : %u\n", pb-pa);
    printf("앞에 있는 배열 요소의 값 출력 : ");
    if(pa < pb) printf("%d\n", *pa);
    else printf("%d\n", *pb);

    return 0;
}
void swap(int* pa, int* pb)  //9.2 포인터 없이 두 변수의 값 바꾸는 함수 (포인터 사용했을 때)
{
    int temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}
void swap2(int x, int y)//9.2 포인터 없이 두 변수의 값 바꾸는 함수(포인터 쓰지 않고)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
    return;
}   // 쉽게 되지 않는다. 메인 함수에서 a와 b값이 바뀌지 않기 때문에 여기서 바꾸는건 의미가 없었다. 