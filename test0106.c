// 1월 6일 수업
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define PI 3.14159265358979323846
// gcc filename.c -o filename -lm  //터미널 창에서 컴파일(실행준비)
// ./filename  //터미널 창에서 실행

void print_ary(int *pa, int size);
void input_ary(double *pa, int size); 
double find_max(double *pa, int size);
void print_month(int *mp, int size);  //배열 포인터 마무리문제 함수
void my_gets(char *str, int size);
int main(void)
{   
    // 크기가 다른 배열 출력하는 함수 예제 10-6
    /*
    int ary1[5] = {10, 20, 30, 40, 50};
    int ary2[7] = {10, 20, 30, 40 ,50, 60, 70};

    print_ary(ary1, 5);
    printf("\n");
    print_ary(ary2, 7);

    return 0;
    */
    //배열에 값을 입력하는 함수 10-7
    /*
    double ary[5];
    double max;
    int size = sizeof(ary) / sizeof(ary[0]);

    input_ary(ary, size);
    max = find_max(ary, size);
    printf("배열의 최댓값 : %.1lf\n", max);

    return 0;
    */

    // 포인터, 배열 마무리 문제 (교재에 없음 사진 확인) 
    /*
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int size = sizeof(month) / sizeof(month[0]);  // 12 입력 대신 사이즈 구하기
    print_month(month, size);  //추가로 size 입력 추가
    return 0;

    */

    // 아스키 코드 대문자를 소문자로 변경코드 
    /*
    char small, cap = 'G';

    if((cap>='A')&&(cap <= 'Z'))
    {
        small = cap + ('a' - 'A');

    }
    printf("대문자 : %c\n", cap);
    printf("소문자 : %c\n", small);
    
    return 0;
    */

    // scanf 함수를 사용한 문자 입력 예제 11-2
    /*
    char ch1, ch2;
    //scanf("%c%c", &ch1, &ch2);
    scanf(" %c %c", &ch1, &ch2);  //%c앞에 공백(또는 \t 또는 \n)을 추가하면? 
    //
    printf("[%c%c]", ch1, ch2);

    return 0;
    */

    //scnaf 함수가 문자를 입력하는 과정 (버퍼 개념) 예제 11-4
    /*
    char ch;
    int i;

    for(i=0;i<3;i++)
    {
        scanf("%c", &ch);  //tiger을 입력하면, i=1부턴 입력을 안받는다. 
        printf("%c", ch);
    }

    printf("\n");
    return 0;
    */

    //getchar 함수를 사용한 문자열 입력 예제 11-6
    
    /*
    char str[7];
    my_gets(str, sizeof(str));
    printf("입력한 문자열 : %s\n", str);
    printf("%d\n", str[5]);
    printf("%d\n", str[6]);
    return 0;
    */

    // 입력 버퍼 지우기 예제 11-7
    /*
    int num, grade;
    char grade2;

    printf("학번 입력 : ");
    scanf("%d", &num);
    //getchar();  //이걸 지워보기 (버퍼 지우는 코드)
    
    printf("학점 입력 : ");
    scanf(" %c", &grade2);  //위에 getchar이 없을 때 scanf써서 해결하기@@(띄어쓰기 + %c)@@
    //grade = getchar(); //위에 겟차 지워본 상태에서 고쳐보기
    printf("학번 : %d, 학점 : %c", num, grade2);

    return 0;
    */
    // 문자열 상수가 주소라는 증거 예제 12-1
    /*
    printf("apple이 저장된 시작 주소 값 : %p\n", "apple");
    printf("두 번째 문자의 주소 값 : %p\n","apple"+1 );
    printf("첫 번째 문자 : %c\n",*"apple" );
    printf("두 번째 문자 : %c\n",*("apple"+1) );
    printf("배열로 표현한 세번째 문자 : %c\n","apple"[2] );
    return 0;
    */
    // 포인터로 문자열을 사용하는 방법 예제 12-2
    /*
    char *dessert = "apple";

    printf("오늘 후식은 %s입니다.\n", dessert);  //%s는 처음부터 null문자까지 계속 읽는다.
    dessert = "banana";  //dessert는 포인터 변수이므로, banana 주소를 저장한다. 
    printf("내일 후식은 %s입니다.\n", dessert);  

    return 0;
    */
    // scanf 함수를 사용한 문자열 입력 예제 12-3 
    // scanf는 공백을 입력받지 못한다. 공백에서 끊어서 받는다. 
    // 그래서 scanf가 다시 나오자, 버퍼에 남아있던 jam을 입력받고 따로 키보드 입력을 받지 않는것 
    /*
    char str[80];

    printf("문자열 입력 : ");
    scanf("%s", str);
    printf("첫 번째 단어 : %s\n", str);
    scanf("%s", str);
    printf("버퍼에 남아 있는 두 번째 단어 : %s\n", str);

    return 0;
    */
    // gets 함수로 한줄의 문자열 입력 예제 12-4
    /*
    char str[80];
    printf("공백이 포함된 문자열 입력 : ");
    gets(str);
    printf("입력한 문자열은 %s 입니다.", str);
    return 0;
    */
    
    //fgets 함수의 문자열 입력 방법 (개행문자까지 저장되는 fgets)
    /*
    char str[80];

    printf("공백이 필요한 문자열 입력 : ");
    fgets(str, sizeof(str), stdin);  //개행 문자까지 저장해버려서 줄바꿈이 맘대로 되어버림
    // 여기서 중요한건 저장되어버린 개행 문자를 어떻게 없앨지! (꼭 해야하는건 아님)

    str[strlen(str)-1] = '\0';//@@저장된 개행 문자를 강제로 널문자로 바꿔버리기 @@

    printf("입력된 문자열은 %s입니다\n", str);

    return 0;
    */

    // 개행 문자로 인해 gets 함수가 입력을 못하는 경우
    /*
    int age;
    char name[20];

    printf("나이 입력 : ");
    scanf("%d", &age);  //여기서 버퍼에 개행문자가 남아버린다. 
    // 해결하기 위한 첫번째 방법  gets를 위에서 써서 버퍼를 해소해준다. 
    //getchar();  //이걸로 버퍼에 있는 찌꺼기를 날려버리기 
    printf("이름 입력 : ");
    //gets(name);  //여기서 버퍼에 남아있던 개행문자(null로 대체됨)이 입력된다. 
    // 해결하기 위한 코드
    scanf(" %s", name); //또는 이렇게 gets 대신 띄어쓰기 + %s 를 사용한 scanf를 써도 된다.
    printf("나이 : %d, 이름 : %s\n", age, name);

    return 0;
    */
    //문자열 출력하는 puts와 fputs 함수 
    /*
    char str[80] = "apple juice";
    char *ps = "banana";

    puts(str);
    fputs(ps, stdout);
    puts("milk");

    return 0;
    */
    //문자열 문제
    // 고려해야 할 점: scanf. gets, fgets puts, fputs, 개행문제 처리(삭제)
    // 개행 문자를 포함하는가? 줄바꿈을 하는가? 등을 잘 생각해보자 

    char ani[20];
    char why[80];
    printf("좋아하는 동물 : ");
    scanf("%s", ani);
    printf("좋아하는 이유 : ");
    getchar();  //추가한 줄 버퍼에 남은 개행문자를 이걸로 처리했다. 
    fgets(why, sizeof(why), stdin);//fgets는 개행문자를 포함하므로 맨앞에 개행문자가 들어가고, 그 뒤에 널문자가 들어간다. 
    printf("%s is %s", ani, why);
    //printf("%d", why[0]);  //getchar()로 버퍼해소하지 않았을 때, why맨앞자리에는 개행문자가 들어간다. 

    return 0;



}   

void print_ary(int *pa, int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d ", pa[i]);
    }
}

void input_ary(double *pa, int size)
{
    int i;

    printf("%d개의 실수값 입력 : ", size);
    for(i=0;i<size;i++)
    {
        scanf("%lf",pa+i);
    }
}
double find_max(double *pa, int size)
{
    double max;
    int i;

    max = pa[0];
    for(i=0;i<size;i++)
    {
        if(pa[i] > max) max = pa[i];
    }
    return max;
}

void print_month(int *mp, int size)  //배열 포인터 마무리문제 함수
{
    int i;
    int j = 0;
    for(i=0;i<size;i++)
    {
        printf("%5d", mp[i]);
        j++;
        if(j==5) // 이거 대신 if(i % 5 == 0)을 사용하는 방법도 있다
        {
            printf("\n");
            j = 0;
        }
    }
}

void my_gets(char *str, int size)
{
    int ch;
    int i = 0;
    
    ch = getchar();
    while((ch != '\n') && (i < size -1 ))
    {
        str[i] = ch;
        i++;
        ch = getchar();
        printf("1");

    }
    str[i] = '\0';
}