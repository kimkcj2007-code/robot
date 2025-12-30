#include <stdio.h>
#include <math.h>
// math 함수 사용할 때, 터미널에 gcc 파일명.c -o 파일명 -lm을 쳐서 [컴파일]하고
// ./파일명으로 [실행]하면 결과가 나온다. 
// 아마 한번 껐다 키면 다시 gcc 컴파일부터 해줘야하는걸로 확인됨
int main(void)
{
    printf("Be happy\n");
    printf("MY friend\n");
    /*
    int a=10, b=20, res;

    res = (a>b) ? a : b; //거짓이므로 b 출력
    printf("큰 값 : %d\n", res);
    res = (a<b) ? a : b;  //참이므로 a 출력
    printf("작은 값 : %d\n", res);
    */

    int a = 20, b = 10;
    if(a > 10)
    {
        if(b>=0)
        {
            b=1;

        }
        else
        {
            b = -1;
        }
    }
    printf("a : %d, b : %d\n", a, b);
    
    double x, y;
    printf("실수 x 입력: ");
    scanf("%lf", &x);
    printf("실수 y 입력: ");
    scanf("%lf", &y);

    printf("\n[math.h 함수 예제\n");
    printf("sqrt(x) = %.4lf\n", sqrt(x));//제곱근
    printf("pow(x) = %.4lf\n", pow(x, y)); // 거듭제곱
    printf("sin(x) = %.4lf\n", sin(x));  //sin값 
    printf("cos(x) = %.4lf\n", cos(x));  //cos값
    printf("log(x) = %.4lf\n", log(x));  //log값 
    printf("fabs(x) = %.4lf\n", fabs(x));  //실수 숫자의 절대값(양수)
    return 0;
}


/*
#include <stdio.h>
int main(void)
{
    printf("Be happy\n");
    printf("MY friend\n");

    double N, mass, SF, DM, torque, gear, R, c, g, W;
    double F_min, F_motor;

    SF = 2.0;
    DM = 1.2;
    c = 0.018;
    g = 9.81;


    mass = 200;
    N = 2;
    torque = 0.63;
    gear = 10;

    R = 0.0965;
    W = mass * g;
    F_min = c * W * SF * DM;
    F_motor = (torque * gear) / R * N;

    printf("필요한 최소 견인력 = %.1lf\n", F_min);
    printf("모터가 낼 수 있는 견인력 = %.1lf\n", F_motor);

    if(F_min<=F_motor)
    {
        printf("판정: 만족\n");
    }
    else
    {
        printf("불만족 (더 큰 모터나 감속비가 필요합니다!)\n");
    }
    


    return 0;
}
*/