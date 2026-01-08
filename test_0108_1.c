// 1월 8일 수업 1
// 메모리할당
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define PI 3.14159265358979323846
// gcc filename.c -o filename -lm  //터미널 창에서 컴파일(실행준비)
// ./filename  //터미널 창에서 실행

int main(void)
{   
    /*
    //malloc 함수 사용해보기
    // malloc와 free는 세트로 쓴다고 생각하자. 
    int *pi;
    double *pd;

    pi = (int *)malloc(sizeof(int));
    if(pi == NULL)
    {
        printf("# 메모리가 부족합니다.\n");
        exit(1);
    }
    pd = (double *)malloc(sizeof(double));

    *pi = 10;
    *pd = 3.4;

    printf("정수형으로 사용 : %d\n", *pi);
    printf("실수형으로 사용 : %.1lf\n", *pd);

    free(pi);  //할당했던 값 반환, malloc과 세트다 같이 쓰는 것
    free(pd);  //할당했던 값 반환, malloc과 세트다 같이 쓰는 것

    return 0;
    */

    /*
    // 기타 동적 할당 함수 예제 16-3
    // calloc, realloc 함수를 사용한 양수 입력 
    
    int *pi;
    int size = 5;
    int count = 0;
    int num;
    int i;

    pi = (int*)calloc(size,sizeof(int));
    while(1)
    {
        printf("양수만 입력하세요 => ");
        scanf("%d", &num);
        if(num <= 0) break;
        if(count == size)
        {
            size += 5;
            pi = (int *)realloc(pi, size * sizeof(int));
        }
        pi[count++] = num;
    }
    for(i=0;i<count;i++)
    {
        printf("%5d", pi[i]);
    }
    free(pi);
    printf("\n");
    return 0;
    */

    /*
    // 3개의 문자열을 저장하기 위한 동적 할당
    // 예제 16-4 
    char temp[80];
    char *str[3];
    int i;

    for(i=0;i<3;i++)
    {
        printf("문자열을 입력하세요 : ");
        gets(temp);
        str[i] = (char*)malloc(strlen(temp)+1);
        strcpy(str[i], temp);
    }
    for (i=0;i<3;i++)
    {
        printf("%s\n", str[i]);
    }
    for(i=0;i<3;i++)
    {
        free(str[i]);
    }

    return 0;
    */
}