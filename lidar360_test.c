// 1월 8일 수업 중 문제
// 라이다센서 문제
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define PI 3.14159265358979323846

// 라이다 센서에서 모의로 입력된 거리값 360개 중
// 가장 가까운 장애물의 거리와 방향(각도)를 찾아 출력한다. 

// 1번 오리지널 (성공)
/*
int main(void)
{

    srand(time(NULL));// rand 쓸 때 주의하기 이걸 써야 진짜 난수 


    double ridar_input[361];
    int i = 0;
    int data = 0;
    double min =0;
    int min_index = 0;
    data = rand() % 500;

    for(i=0;i<360;i++)
    {

        data = data + ((rand() % 21) - 10);
        if(data <= 0)
        {
            data = 5;
        }

        else if(data > 500)
        {
            data = 500;
        }
        ridar_input[i] = data;
        //printf("%.1lf ", ridar_input[i]);
    }
    printf("\n");

    min = ridar_input[0];  //초기값 초기화

    for(i=1;i<360;i++)
    {
        if(ridar_input[i] < min)
        {
            min = ridar_input[i];
            min_index = i;
        }
    }
    printf("%.1lf ", ridar_input[359]);
    printf("최소거리 min : %.1lf\n", min);
    printf("최소 거리 방향 : %d도\n", min_index);
    
    return 0;

}
*/
//2번 과제, 1번 과제에서 데이터를 1초간 저장하고, 360개의 데이터를 heap 에 할당해서 사용해보자. 메모리 영역 반환까지
//메모리를 동적 할당으로 바꿔보기 
// 초당으로 저장해보기 ex) 10hz면 1초에 10번 진동, 즉 360 * 10 으로 3600개의 데이터 저장
//int 는 4바이트 360도면 1440 byte인데, 10hz면 14400byte가 필요해질 것이다. 
//만약 20hz면 28800 byte? 

/*
int main(void)
{

    srand(time(NULL));// rand 쓸 때 주의하기 이걸 써야 진짜 난수 


    double *ridar_input;  //포인터 변수 생성
    int i = 0;
    int data = 0;
    double min =0;
    int min_index = 0;
    ridar_input = (double *)malloc(361 * sizeof(double));
    if(ridar_input == NULL)
    {
        printf("메모리가 부족합니다!\n");
        exit(1);
    }

    data = rand() % 500;

    for(i=0;i<360;i++)
    {

        data = data + ((rand() % 21) - 10);
        if(data <= 0)
        {
            data = 5;
        }

        else if(data > 500)
        {
            data = 500;
        }
        ridar_input[i] = data;
        //printf("%.1lf ", ridar_input[i]);
    }
    printf("\n");

    min = ridar_input[0];  //초기값 초기화

    for(i=1;i<360;i++)
    {
        if(ridar_input[i] < min)
        {
            min = ridar_input[i];
            min_index = i;
        }
    }
    printf("마지막 값 : %.1lf \n", ridar_input[359]);
    printf("최소거리 min : %.1lf\n", min);
    printf("최소 거리 방향 : %d도\n", min_index);

    free(ridar_input);
    
    return 0;

}

*/

//위 코드에서 hz개념만 추가해보기, 이중배열을 써서, 10hz로 동작할 때, 1초에 10번 값을 출력하는걸 보여주기 

int main(void)
{

    srand(time(NULL));// rand 쓸 때 주의하기 이걸 써야 진짜 난수 


    double *ridar_input;  //포인터 변수 생성
    int i = 0, j = 0;
    int data = 0;
    int hz = 10;  //주파수

    printf("\n%dhz로 동작시작\n", hz);
    for(j=0; j<hz; j++)
    {
        printf("%d/%d 동작\n", j+1, hz);
        double min =0;
        int min_index = 0;
        ridar_input = (double *)malloc(361 * sizeof(double));
        if(ridar_input == NULL)
        {
            printf("메모리가 부족합니다!\n");
            exit(1);
        }
        else
        {
            printf("메모리가 할당되었습니다!\n");
        }

        data = rand() % 500;

        for(i=0;i<360;i++)
        {

            data = data + ((rand() % 21) - 10);
            if(data <= 0)
            {
                data = 5;
            }

            else if(data > 500)
            {
                data = 500;
            }
            ridar_input[i] = data;
            //printf("%.1lf ", ridar_input[i]);
        }

        min = ridar_input[0];  //초기값 초기화

        for(i=1;i<360;i++)
        {
            if(ridar_input[i] < min)
            {
                min = ridar_input[i];
                min_index = i;
            }
        }
        printf("최소거리 min : %.1lf\n", min);
        printf("최소 거리 방향 : %d도\n", min_index);

        free(ridar_input);
    }  //맨 앞 for문 hz 구현하기 위해서 
    return 0;

}