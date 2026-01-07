// 1월 7일 수업 
// 문자열 연산 함수, 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define PI 3.14159265358979323846
// gcc filename.c -o filename -lm  //터미널 창에서 컴파일(실행준비)
// ./filename  //터미널 창에서 실행

int str_length(char *str);  //strlen(문자열 길이 함수 구현)
char str_ncopy(char *str1, char *str2, int num);  //strncpy 구현하기 (n)
char str_copy(char *str1, char *str2); //strcpy 구현하기
char str_cat(char *str1, char *str2);  //strcat 구현하기
int str_cmp(char *str1, char *str2);  // strcmp 비교함수 구현하기
int str_ncmp(char *str1, char *str2, int num);  // strncmp 비교함수 (n)
int main(void)
{   
    /*
    char str1[80] = "strawberry";  //str1이라고 하는 배열 생성
    char str2[80] = "apple";  //str2라는 배열 생성
    char *ps1 = "banana"; //ps1은 바나나의 주소를 저장한다. 
    char *ps2 = str2;  //ps2는 apple의 주소를 저장한다. 

    strcpy(str1, str2); //str1에 str2를 복사 
    // 이러면 apple 과 null문자가 저장된다 apple\0 널문자도 포함해서 복사한다. 

    return 0;
    */
    /*
    char str1[80], str2[80];
    char *resp;

    printf("2개의 과일 이름 입력 : ");
    scanf("%s%s", str1, str2);
    if(strlen(str1) > strlen(str2))
        resp = str1;
    else
        resp = str2;
    printf("이름이 긴 과일은 : %s\n", resp );

    return 0;
    */

    /* 
    //마무리 연습문제 strlen 함수 구현 
    char str1[80], str2[80];
    char *resp;
    int len;

    printf("2개의 과일 이름 입력 : ");
    scanf("%s%s", str1, str2);
    //len = str_length(str1);
    //printf("%d\n", len);
    if(str_length(str1) > str_length(str2))
    {
        resp = str1;
    }
    else
    {
        resp = str2;
    }
    printf("이름이 긴 과일은 : %s\n", resp );

    return 0;
    */

    /*
    // 마무리 연습문제 strncpy 구현 (strncpy)
    // 마무리 연습문제 strcpy 구현 (strcpy)
    char str[20] = "mango cake";
    char str2[20] = "banana";
    //str_ncopy(str, "apple pie", 5);
    //printf("%s\n", str);
    str_copy(str, str2);
    printf("%s\n", str);
    return 0;
    */

    // 마무리 연습문제 strcat 구현하기
    /*
    char str[80] = "straw";

    str_cat(str, "berry");
    printf("%s\n", str);
    str_cat(str, "cake");
    printf("%s\n", str);
    
    return 0;
    */
    
    //마무리연습 strcmp 구현하기
    char str1[80] = "pear";
    char str2[80] = "peach";  //peeaa, peaz 비교해보기
    if(str_cmp(str1, str2) > 0)
    {
        printf("사전에 나중에 나오는 과일 이름 : ");
        printf("%s\n", str1);
    }
    else
    {
        printf("사전에 나중에 나오는 과일 이름 : ");
        printf("%s\n", str2);
    }
    return 0;
}
int str_length(char *str)  //strlen(문자열 길이 함수)
{
    int length = 0;
    while(*str != '\0')
    {   
        length ++;  //길이 세기
        str++;  //배열의 다음요소로 넘어가기 (다음주소)
    }
    return length;

}
char str_ncopy(char *str1, char *str2, int num)  //strncpy 구현하기
{
    for(int i=0;i<num;i++)
    {
        str1[i] = str2[i];
    }

    return *str1;
}
char str_copy(char *str1, char *str2)  //strcpy 구현하기
{
    int length = 0;
    int length2 = 0;
    int i = 0;
    while(*str2 != '\0')
    {   
        str1[i] = *str2;
        i ++;
        str2++;
    }
    str1[i] = '\0';
    return *str1;
}
char str_cat(char *str1, char *str2)  //strcat 구현하기
{
    int i = 0, j = 0;
    int length = 0;
    while(str1[i] != '\0')
    {   
        i++; //길이 세기
        length ++;
    }
    while(str2[j] != '\0')
    {
        str1[j+i] = str2[j];
        j++;
    }
    str1[j+i] = '\0';
    return *str1;
}

int str_cmp(char *str1, char *str2)  // strcmp 비교함수 구현하기
{   
    int i = 0;
    int result = 0;
    while(str1[i] == str2[i])
    {
        i++;
    }
    printf("비교되는 위치 : %c\n", str1[i]);
    if( str1[i] > str2[i])
    {
        result = 1;
    }
    else if(str1[i]<str2[i])
    {
        result = -1;
    }
    return result;
}

int str_ncmp(char *str1, char *str2, int num)  // strncmp 비교함수 (n)
{
    int i = 0;
    int result = 0;
    for (i=0; i < num; i++)
    {
        if( str1[i] > str2[i])
        {
            result = 1;
            break;
        }
        else if(str1[i]<str2[i])
        {
            result = -1;
            break;
        }
    }
    return result;
}