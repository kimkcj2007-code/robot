#include <stdio.h>
int main(void)
{
    //printf("Be happy\n");
    //printf("MY friend\n");

    double N, mass, SF, DM, torque, gear, R, W;
    double F_min, F_motor;
    const double c = 0.018;  //구름저항계수 (상수값)
    const double g = 9.81;  //중력가속도 (상수값)
    //안전계수, 설계마진은 실제 기업에선 따로 계산해서 사용한다. 

    printf("총 하중(질량): ");
    scanf("%lf", &mass);
    printf("구동바퀴 개수: ");
    scanf("%lf", &N);
    printf("모터 정격 토크: ");
    scanf("%lf", &torque);
    printf("감속비: ");
    scanf("%lf", &gear);
    printf("바퀴 반지름: ");
    scanf("%lf", &R);
    printf("안전계수(1.2~2.0 권장): ");
    scanf("%lf", &SF);
    printf("설계마진(1.2~1.5 권장): ");
    scanf("%lf", &DM);

    //SF = 2.0;  //안전계수 지금은 고정값으로
    //DM = 1.2;  //설계마진 지금은 고정값으로

    W = mass * g;
    F_min = c * W * SF * DM;
    F_motor = (torque * gear / R) * N;

    printf("필요한 최소 견인력 = %.2lf\n", F_min);
    printf("모터가 낼 수 있는 견인력 = %.2lf\n", F_motor);

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