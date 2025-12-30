#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#define PI 3.14159265358979323846
int main(void)
{

    double N, mass, SF, DM, torque, gear, R, W, eta;
    double F_min, F_motor;
    double T_tot, F_avail, F_need, sheta_max, grade;
    double c;  //구름저항계수 0.015~0.03
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
    printf("구동 효율(0~1): ");
    scanf("%lf", &eta);
    printf("구름계수 c(예:0.1~0.2): ");
    scanf("%lf", &c);
    printf("안전계수(1.2~2.0 권장): ");
    scanf("%lf", &SF);
    printf("설계마진(1.2~1.5 권장): ");
    scanf("%lf", &DM);

    //SF = 2.0;  //안전계수 지금은 고정값으로
    //DM = 1.2;  //설계마진 지금은 고정값으로

    W = mass * g;
    F_min = c * W * SF * DM;
    F_motor = (torque * gear / R) * N;

    T_tot = N * torque * gear * eta;
    F_avail = T_tot / R;
    double sin_theta = (F_avail / SF - c *mass*g) / (mass * g);
    if (sin_theta < 0.0) sin_theta = 0.0;  //clip함수 대체 값 제한하기
    if (sin_theta > 1.0) sin_theta = 1.0; //clip함수 대체 값 제한하기

    double theta_rad = asin(sin_theta);
    double theta_deg = theta_rad * 180.0 / PI;
    double grade_pct = tan(theta_rad) * 100.0;
    printf("\n필요한 최소 견인력 = %.2lf\n", F_min);
    printf("모터가 낼 수 있는 견인력 = %.2lf\n", F_motor);

    printf("\n[결과]\n");
    printf("총 구동 토크 T_tot : %.2lf N*m\n", T_tot);
    printf("가용 견인력 F_avail : %.2lf N\n", F_avail);
    printf("등판 가능 최대각 : %.2lf deg\n", theta_deg);
    printf("등판율(grade) : %.1lf %%\n", grade_pct);
    printf("(가정: 마찰한계 무시, 구름저항 c 포함, 안전계수 SF 적용)\n");
    return 0;
}

int clip(int x, int min, int max)
{
    if(x < min) return min;
    if(x > max) return max;
    return x;
}  // 클립함수 만들어서 사용하기