#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#define PI 3.14159265358979323846
int main(void)
{

    double r, W, error_L, error_R, L;  //입력 변수
    // 바퀴 반지름 r, 트랙폭 W, 좌우 바퀴 오차율 error_L,R
    double r_R, r_L;//좌우 유효 반지름
    double Rc;//곡률반경
    double delta;  //편류각
    double d_drift; //최종 편류거리
    const double g = 9.81;  //중력가속도 (상수값)
    //안전계수, 설계마진은 실제 기업에선 따로 계산해서 사용한다. 
    printf("입력 )\n");
    printf("바퀴 반지름 r: ");
    scanf("%lf", &r);
    printf("트랙폭 W: ");
    scanf("%lf", &W);
    printf("왼쪽 바퀴 오차율: ");
    scanf("%lf", &error_L);
    printf("오른쪽 바퀴 오차율: ");
    scanf("%lf", &error_R);
    printf("목표 주행거리: ");
    scanf("%lf", &L);

    //SF = 2.0;  //안전계수 지금은 고정값으로
    //DM = 1.2;  //설계마진 지금은 고정값으로

    r_L = r*(1+error_L);
    r_R = r*(1+error_R);


    Rc = (W / 2.0) * (r_L + r_R) / (r_R - r_L);
    double delta_radian = L / Rc;
    delta = delta_radian * 180 / PI;  //디그리 값
    d_drift = Rc*(1-cos(delta_radian)); //cos함수는 라디안 값을 사용함

    printf("\n 출력 \n");
    printf("좌/우 바퀴 반경 : %.4lf m / %.4lf m\n", r_L, r_R);

    printf("곡률반경 Rc : %.2lf m\n", Rc);
    printf("편규각 delta : %.2lf deg\n", delta);
    printf("편류거리 d_drift : %.2lf m\n", d_drift);
    return 0;
}

int clip(int x, int min, int max)
{
    if(x < min) return min;
    if(x > max) return max;
    return x;
}  // 클립함수 만들어서 사용하기