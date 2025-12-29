#include <stdio.h>
int main(void)
{
    double i_load, vel, R_margin; //R_margin은 5~10프로 정도?
    double Vol, Cap, eta; //eta는 시스템 효율로, 100에 가까울수록 좋음
    const double c = 0.018;  //구름저항계수 (상수값)
    const double g = 9.81;  //중력가속도 (상수값)
    //안전계수, 설계마진은 실제 기업에선 따로 계산해서 사용한다. 

    printf("-----사전 선정 정보-----\n");
    printf("평균전류 [A]: ");
    scanf("%lf", &i_load);
    //if(scanf("%lf", &i_load)!=1) return 1;
    //위 코드는 만약 입력이 제대로 들어오지 않으면 프로그램을 종료하기 위함
    //return 1은 코드를 종료시킨다. 
    printf("평균속도 [km/h]: ");
    scanf("%lf", &vel);
    printf("예비율 R[0~1]: ");
    scanf("%lf", &R_margin);
    printf("공칭전압 [V]: ");
    scanf("%lf", &Vol);
    printf("용량 [Ah]: ");
    scanf("%lf", &Cap);
    printf("시스템 효율 eta[0~1]: ");
    scanf("%lf", &eta);
    // 전압강하, 온도 영향 무시, 평균전류 일정
    ///*
    if (Vol<=0 || Cap <=0 || i_load<=0 || vel<0 || R_margin<0 || 
        R_margin >=1 || eta <=0 || eta > 1)
    {
        printf("입력값 범위를 확인하세요\n");
        return 1;
    }
    //*/
    double E_usable = Vol * Cap * eta * (1-R_margin); //사용 가능 에너지(Wh)
    double P = Vol * i_load / eta;
    double t = E_usable / P;
    double d = vel * t;

    printf("사용 가능 에너지 = %.2lf\n", E_usable);
    printf("런타임 = %.2lf\n", t);
    printf("주행거리(km)= %.2lf\n", d);
    //모터가 주어지고, 런타임 조건이 주어졌을 때, 배터리 선정을 해볼 수 있다
    //ex) MDH100 사용, 런타임 3~4시간 조건, 예비율 0.1, 시스템 효율 95프로

    return 0;  //만약 1을 리턴하면 프로그램이 종료된다. 
}