#include <stdio.h>
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