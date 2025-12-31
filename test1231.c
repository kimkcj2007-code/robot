#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define PI 3.14159265358979323846
// gcc filename.c -o filename -lm  //터미널 창에서 컴파일(실행준비)
// ./filename  //터미널 창에서 실행
int main(void)
{
    //배열 실습
    //배열 

    /*
    int ary[10] = {0,1,2,3,4,5,6,7,8,9};
    char ary2[4] = {'a','b','c','d'};
    
    for(int i=0;i<10;i++)
    {
        printf("%d ", ary[i]);
    }
    printf("\n");
    for(int j=0;j<4;j++)
    {
        printf("%c ", ary2[j]);
    }
    printf("\n");

    int score[5];
    int total = 0;

    for(int k=0; k<5; k++)
    {
        scanf("%d", &score[k]);
    }

    for (int k = 0; k<5; k++)
    {
        total += score[k];
    }
    double avg = total / 5.0;

    for(int k = 0; k<5;k++)
    {
        printf("%5d", score[k]);  //%숫자d는 숫자만큼 공간만들기
    }
    printf("\n");
    printf("평균 : %.1lf\n", avg); 
    */
    ////////////////////////////////
    /*
    char str[80] = "applejam";
    char str2[80] = {'a','p','p','l','e','j','a','m'};

    printf("최초 문자열 : %s\n", str);
    printf("초기화해준 문자열 : %d\n", str2[10]);

    printf("문자열 입력 : ");
    scanf("%s", str);
    printf("입력 후 문자열 : %s\n", str);

    printf("남아있던 [6]칸: %c\n", str[6]);
    /////////////////////////////////////////////
    */
    
    /*
    char str1[80] = "cat";
    char str2[80];
    printf("\n");
    //strcpy(str1, "triger");
    //strcpy(str2, str1);
    //printf("%s, %s\n", str1, str2);

    char str[80];
    printf("문자열 입력 : ");
    fgets(str, sizeof(str),stdin);
    //scanf("%s", str);
    puts("입력된 문자열 : ");
    puts(str);
    
    */
    //////////////////////////
    // 쓰레기값을 보려고 작성해본 코드이며, 5칸으로 했을때는 쓰레기값이
    // 안보일 수 있었다. 50칸으로 늘려본 결과, 값을 주지 않은 칸부터
    // 쓰레기값이 나올 수 있다는것을 확인했다. 
    //char str[50];

    //str[0] = '0';
    //str[1] = 'K';

    //printf("%s\n", str);
    ////////////////////////////
    
    /////////////////////////////////////
    // 랜덤 난수 발생시키기 코드
    /*
    srand(time(NULL));

    int r1 = rand() % 10;  // 0 ~ 9
    // 원리는 10으로 나눴을 때 나머지이므로 0부터 9까지의 값이 나온다.
    int r2 = rand() % 100+1;  // 1 ~100
    // 원리는 100으로 나눴을 때 나머지 + 1이므로 1~100값 나온다.
    int r3 = rand() % 21 - 10;  // -10 ~ 10 
    // 원리는 21로 나눠서 0~20 값이 나오고 여기에 -10을 하여 -10~10 나온다. 

    printf("0~9 랜덤: %d\n", r1);
    printf("1~100 랜덤: %d\n", r2);
    printf("-10~10 랜덤: %d\n", r3);
    */
    //////////////////////////////////////
    //급가속, 급제동 이벤트 카운트 코드 작성
    // 1번 입력 10개 직접입력
    // 2번 입력을 100개 난수로 직접 입력
    // 3번 증감 방향성 고정 ex)만약 처음이 +면 최소 10번까지 증가
    // 만약 감소되기 시작하면 최소 10번 감소

    srand(time(NULL));

    int data[100];
    int delta = 0;
    int count_plus = 0;  //급가속 횟수 변수
    int count_minus = 0;  //급감속 횟수 변수
    //*********1번 조건 코드**********//
    /*
    for(int i=0;i<10;i++)
    {   printf("속도 데이터를 10개 입력하시오 : ");
        scanf("%d", &data[i]);
    }
    for(int j = 1;j < 10;j++)  //1부터 9까지
    {   
        delta = data[j]-data[j-1];
        if(delta >= 10)
        {
            count_plus += 1;
        }
        else if(delta <= -10 )
        {
            count_minus += 1;
        }
    }
    */

    //*********2번 조건 코드**********//
    /*
    for(int i=0;i<100;i++)
    {   
        int r1 = rand() % 101;  //0부터 100까지 
        data[i] = r1;
        printf("%d ", r1);
    }
    printf("\n");
    for(int j = 1;j < 100;j++)  //1부터 9까지
    {   
        delta = data[j]-data[j-1];
        if(delta >= 10)
        {
            count_plus += 1;
        }
        else if(delta <= -10 )
        {
            count_minus += 1;
        }
    }
    printf("급가속 횟수: %d, 급제동 횟수: %d\n",count_plus, count_minus);
    */

    //*********3번 조건 코드**********//
    // 초기값은 0이므로 처음 시작은 반드시 증가식으로 시작한다. 
    // 그리고 최소 10번 이상 유지 후, 값의 증감에 따라 10회 이상 유지하라
    int start_count = 1;
    int count = 0;
    int up_count, down_count = 0;
    int change1 = 0, change2 = 0; //change1가 1이면 플러스 끝
    // change2가 1이면 마이너스 끝
    int a;
    printf("시작\n");
    int r1 = rand() % 1000;
    if(r1>=500)
    {
        r1 = r1 - 300;
    }
    data[0] = r1;
    
    for(int i=1;i<100;i++)
    {   
        if(start_count==1)  //처음 시작인가
        {   
            while(1)
            {   
                int r1 = data[0] + (rand()%40 - 20);  //0부터 100까지
                if((r1-data[i-1]) >= 0)
                {
                    data[i] = r1;
                    printf("%d ", data[i]);
                    count +=1;
                    break;
                }
            }
            if(count > 10)
            {
                change1 = 1;
                start_count = 0;
                count = 0;
            }
        }
        else if(start_count == 0 )  //이제부터 증감 여부에 따라 갈림
        {   
            if(count==0)  //10회 이상 증가하거나 감소했는가
            {   
                int r1 = data[i-1] + (rand()%40 - 20);  //0부터 100까지 난수
                data[i] = r1;
                //printf("%d ", data[i]);
                a = data[i] - data[i-1];

                if((a<0)&&(change1 == 1))//증감 상태가 감소로 변화?
                {   
                    down_count = 1; //감소로 시작하자
                    count = 1;
                    change1 = 0;
                    printf("\n증감 변경 \n");
                }
                else if((a>0)&&(change2 == 1))//증감 상태가 증가로 변화했는가?
                {
                    up_count = 1;  //증가로 시작하자
                    count = 1;
                    change2 = 0;
                    printf("\n증감 변경 \n");
                }
                printf("%d ", data[i]);
            }
            else if(count>=1)  //아직 10회에 도달하지 않았는가
            {
                if(up_count == 1)
                {
                    while(1)
                    {   
                        int r1 = data[i-1] + (rand()%40 - 20);  //0부터 100까지
                        if((r1-data[i-1]) >= 0)
                        {
                            data[i] = r1;
                            printf("%d ", data[i]);
                            count +=1;
                            break;
                        }
                    }
                    if(count > 10)
                    {
                        count = 0;
                        up_count = 0;
                        change1 = 1;
                    }
                }
                else if(down_count == 1)
                {
                    while(1)
                    {   
                        int r1 = data[i-1] + (rand()%40 - 20);  //0부터 100까지
                        if((r1-data[i-1]) <= 0)
                        {
                            data[i] = r1;
                            if(data[i]<0)
                            {
                                data[i]=0;
                            }
                            printf("%d ", data[i]);
                            count +=1;
                            break;
                        }
                    }
                    if(count > 10)
                    {
                        count = 0;
                        down_count = 0;
                        change2 = 1;
                    }
                }
            }
        }

    }
    printf("\n");
    for(int j = 1;j < 100;j++)  //1부터 9까지
    {   
        delta = data[j]-data[j-1];
        if(delta >= 10)
        {
            count_plus += 1;
        }
        else if(delta <= -10 )
        {
            count_minus += 1;
        }
    }
    
    //추가과제 (3번에 추가하라) 지금 이 코드
    // (4) 증감 +- 20까지 제한 (완)
    // (5) 무한 반복하고 속도가 0이 되면 프로그램 종료(미완) 
    // (5번 추가 사항 과제는 배열 사용 안해도 됨)
    return 0;
}