#include <stdio.h>
int main(void)
{

    printf("Be happy\n");
    printf("MY friend\n");
    /////////////////////////////////////////////
    /*
    int a = 10;
    float b = 3.4;
    float c = 3.4567;
    printf("%d\n", a);
    printf("%f\n", b);
    printf("%.1lf\n", c);
    printf("%.10lf\n", c);

    printf("%d과 %d의 합은 %d입니다.\n", 10, 20, 10 + 20);
    printf("%.1lf-%.1lf = %.1lf\n", 3.4, 1.2, 3.4 - 1.2);
    printf("%.1lf\n",1e6);
    printf("%.7lf\n", 3.14e-5);
    printf("%c은 %s입니다.\n", '1', "first");
    printf("%s는 %s입니다.\n", "2", "second");
    int d[a];
    d[0]=0;

    for(int i=0; i<a; i++)
    {
        d[i]= 0+i;

        printf("%d", d[i]);
    }
    printf("\n");
    double da;
    char ch;

    da = 3.5;
    ch = 'A';
    printf("변수 da의 값 = %.1lf\n", da);
    printf("변수 ch의 값 = %c\n", ch);
    char ch1 = 'i';
    printf("문자 %c의 아스키 코드 값 : \n", ch1);

    //unsigned int aa;
    int aa;
    aa = 4294967295;
    printf("%d\n",aa);
    aa = -1;
    printf("%u\n",aa);

    */
    //////////////////////////////////////////
    /*
    char fruit[20] = "strawberry";

    printf("딸기 : %s\n", fruit);
    printf("딸기잼 : %s %s\n",fruit, "jam");
    strcpy(fruit, "banana"); //새로운 문자열 저장 strcpy 함수
    printf("%s\n",fruit);

    int income = 0;
    double tax;
    const double tax_rate = 0.12;

    income = 456;
    tax = income * tax_rate;
    printf("%.1lf\n",tax);
    */
    //////////////////
    /*
    int a;
    scanf("%d", &a);
    int b[a];
    printf("input : %d\n", a);
    for(int i=0; i < a; i++)
    {
        b[i]= 2*i;
        printf("%d ", b[i]);
    }
    */
    ///////////////////////
    /*
    int age;
    double height;

    printf("please age, height : ");
    scanf("%d %lf", &age, &height);
    printf("age: %d, height: %.1lf\n", age, height);
    *////////////////////////////////////////
    /*
    char grade;
    char name[20];

    printf("score : ");
    scanf("%c", &grade);
    printf("name : " );
    scanf("%s", name);
    printf("%s의 학점은 %c 입니다.\n", name, grade);
    /*///////////////////////////////////////////
    /*
    double apple;
    int banana;
    int orange;

    apple = 5.0 / 2.0;
    banana = 5 / 2;
    orange = 5 % 2;

    printf("apple : %.1lf\n", apple);
    printf("banana : %d\n", banana);
    printf("orange : %d\n", orange);
    *//////////////////////////////////////////
    /*
    int a = 30;
    int res;

    //res = (a>b);// 괄호 안 결과값은 0 또는 1이다. 참이면 1 거짓이면 0
    //res = (a <= b); // b가 더 크므로 참 즉 res = 1이 된다. 
    //res = (a < c); // c가 더 크지 않으므로 거짓 즉 값은 0이 된다.  
    //논리연산자 &&(and), ||(or), !(not)
    
    res = (a>10)&&(a<20);
    printf("(a>10) && (a<20) : %d\n", res);
    res = (a<10)||(a>20);
    printf("(a<0) && (a<20) : %d\n", res);
    res = !(a>=30);
    printf("!(a>=30): %d\n", res);
    *////////////////////
    int a = 20,  b = 3;
    double res;

    res = ((double)a) / ((double)b);  //계산값은 6.66....667이다 
    // 위에서 a는 20.0이 될것이고, b는 3.0이 될 것이다
    // 위에서 res에는 6.66....667이 들어간다.
    printf("a = %d, b = %d\n", a, b);  //여기선 기존의 정수값 출력
    printf("a / b 의 결과 : %.10lf\n", res);// 소숫점 자리수 표기값
    //에 따라 6.7이 나오느냐 6.667이 나오느냐 등 값이 달라짐

    a= (int)res;
    printf("(int) %.1lf의 결과 : %d\n", res, a);

    return 0;
}