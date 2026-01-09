// 1월 9일 수업 구조체
// *****************구조체***********************
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define PI 3.14159265358979323846


// 구조체 선언 실습 코드
/*

struct student
{
    int num;
    double grade;
};
int main(void)
{
    struct student s1;

    s1.num = 2;
    s1.grade = 2.7;

    printf("학번 : %d\n", s1.num);
    printf("학점 : %.1lf\n", s1.grade);

    return 0;
}
*/

//구조체 변수의 크기 (패딩바이트 줄이기)
/* 
struct student2
{
    char ch1;
    char ch2;
    char ch3;
    short num;
    int score;
    double grade;
}; 
int main(void)
{
    struct student2 s1;  //틀 찍어내기 만약 구조체 크기 구하고 싶으면 틀인 s1의 크기를 측정하면 된다. 

    int num1 = 0;

    s1.num = 2; 
    s1.grade = 2.7;
    
    num1 = sizeof(s1);
    printf("크기는 : %d\n", num1);
    printf("학번 : %d\n", s1.num);
    printf("학점 : %.1lf\n", s1.grade);

    return 0;
}
*/


//예제 17-2 다양한 구조체 멤버
/*
struct profile
{
    char name[20];
    int age;
    double height;
    char *intro;
};

int main(void)
{
    struct profile yuni;
    strcpy(yuni.name, "서하윤");
    yuni.age = 17;
    yuni.height = 164.5;

    int num1;
    int i = 0;
    printf("자기소개 공간을 직접 할당하면 1, 아니면 0을 입력하세요 : ");
    scanf("%d", &i );
    getchar();  //개행문자 없애기
    if(i==1)
    {
        printf("자기소개를 얼마나 넣을지 입력하시오 : ");
        scanf("%d", &num1 );
        getchar();
        yuni.intro = (char *)malloc(num1);
        printf("자기소개 : ");
        fgets(yuni.intro, num1, stdin);
        
    }
    else if(i==0)
    {
        printf("(80 이하로 입력하세요)");
        yuni.intro = (char *)malloc(80*sizeof(char));
        printf("자기소개 : ");
        fgets(yuni.intro, 80, stdin);
    }

    printf("이름 : %s\n", yuni.name);
    printf("나이 : %d\n", yuni.age);
    printf("키 : %.1lf\n", yuni.height);
    printf("자기소개 : %s\n", yuni.intro);

    free(yuni.intro);

    return 0;
}
*/

/*
//
struct profile
{
    int age;
    double height;
};

struct student
{
    struct profile pf;
    int id;
    double grade;
};

int main(void)
{
    struct student yuni;

    yuni.pf.age = 17;
    yuni.pf.height = 164.5;
    yuni.id = 315;
    yuni.grade = 4.3;

    printf("나이 : %d\n", yuni.pf.age);
    printf("키 : %.1lf\n", yuni.pf.height);
    printf("학번 : %.d\n", yuni.id);
    printf("학점 : %.1lf\n", yuni.grade);

    return 0;
}

*/
/*
struct vision
{
    double left;
    double right;
};
struct vision exchange (struct vision robot);//함수 선언
struct vision exchange_re (struct vision robot);
int main(void)
{
    struct vision robot;

    printf("시력 입력 : ");
    scanf("%lf%lf", &(robot.left),&(robot.right));
    robot = exchange(robot);
    printf("바뀐 시력 : %.1lf  %.1lf\n", robot.left, robot.right);
    robot = exchange(robot);
    printf("다시 바뀐 시력 : %.1lf  %.1lf\n", robot.left, robot.right);
    return 0;
}
struct vision exchange (struct vision robot)
{
    double temp;

    temp = robot.left;
    robot.left = robot.right;
    robot.right = temp;

    return robot;
}

struct vision exchange_re (struct vision robot)
{
    double temp;

    temp = robot.left;
    robot.left = robot.right;
    robot.right = temp;

    return robot;
}

*/

//자기 참조 구조체 
//예제 17-9 자기 참조 구조체로 list 만들기

/*
struct list
{
    int num;
    struct list *next;
};

int main(void)
{
    struct list a = {10, 0}, b= {20, 0}, c = {30, 0};
    struct list *head = &a, *current;

    a.next = &b;
    b.next = &c;

    printf("head -> num : %d\n", head->num);
    printf("head->next->num : %d\n", head->next->num);

    printf("list all : ");
    current = head;
    while(current != NULL)
    {
        printf("%d ", current ->num);
        current = current->next;
    }
    printf("\n");

    return 0;
}
*/
/*
int main(void)
{
    int num[10];

    for(int i = 0; i<10;i++)
    {
        scanf("%d", &num[i]);
    }

    printf("%d", num[5]);
    
}

*/

/*
// tydef를 사용한 (자료)형 재정의
//아래의 기본 방법으로 꼭 쓰자. 구조체를 쓸때 기본으로 써주자 
typedef struct
{
    int num;
    double grade;
}Student;
// 이게 재정의 기본방법

//thpedef struct student SStudent;  
// 이게 재정의 방법 두번째 


void print_data(Student *ps);

int main(void)
{
    Student s1 = {315, 4.2};
    print_data(&s1);

    return 0;
}

void print_data(Student *ps)
{
    printf("학번 : %d\n", ps -> num);
    printf("학점 : %.1lf\n", ps->grade);
}

*/


//연습 문제 // 성적 처리 프로그램 //
// ********** 버블 스왑 ***************************************
/*
//연습 문제 성적 처리 프로그램 //
typedef struct 
{
    int num;
    char name[20];
    int kor, eng, math;
    int sum;
    double avg;
    char score;
    int rank;

}Student;


int main(void)
{
    int i = 0;
    int j = 0;
    Student s1[5];
    printf("학번, 이름, 점수를 입력하세요\n");

    for(i = 0; i<5; i++)
    {   
        printf("학번 : ");
        scanf("%d", &s1[i].num);
        printf("이름 : ");
        scanf("%s", s1[i].name);
        printf("국어, 영어, 수학 점수 : ");
        scanf("%d %d %d", &s1[i].kor, &s1[i].eng, &s1[i].math);
        s1[i].sum = s1[i].kor + s1[i].eng + s1[i].math;
        s1[i].avg = (s1[i].kor + s1[i].eng + s1[i].math) / 3;
        if(s1[i].avg < 90)
        {
            if(s1[i].avg < 80)
            {
                if(s1[i].avg < 70)
                {
                    s1[i].score = 'F';
                }
                else s1[i].score = 'c';
            }
            else s1[i].score = 'B';
        }
        else s1[i].score = 'A';

        s1[i].rank = 0;
    }

    for(i=0; i<5; i++)
    {
        for(j=0;j<5;j++)
        {
            if(s1[i].avg > s1[j].avg)
            {
                s1[i].rank++;
            }
        }
        printf("%d", s1[i].rank);
    }
    for(i=1; i<5; i++)
    {
        if(s1[i-1].rank == s1[i].rank)
        {
            s1[i-1].rank++;
        }
    }
    printf("\n");


    printf("# 정렬 전 데이터...\n");
    for(i=0;i<5;i++)
    {
        printf("%6d%10s%6d%6d%6d%6d%6.1lf%6c\n",s1[i].num, s1[i].name,
         s1[i].kor, s1[i].eng,s1[i].math,s1[i].sum, s1[i].avg, s1[i].score);
    }
    printf("# 정렬 후 데이터...\n");
    for(i=5;i>0;i--)
    {   
        for(j=0;j<5;j++)
        {
            if(s1[j].rank == (i-1))
            {
                printf("%6d%10s%6d%6d%6d%6d%6.1lf%6c\n",s1[j].num, s1[j].name,
         s1[j].kor, s1[j].eng,s1[j].math,s1[j].sum, s1[j].avg, s1[j].score);
            }           
        }
    }
    return 0;
}

*/

// 로봇 좌표 이동함수 문제
/*
typedef struct
{
    int x;
    int y;
}Position;

void move(Position *p, int dx, int dy) ;

int main(void)
{
    //ps.x = 0, ps.x = 0; //초기위치 0,0 초기화
    Position robot_p;
    robot_p.x = 0, robot_p.y = 0;

    move(&robot_p, 5, 3);
    move(&robot_p, -2, 4);

    printf("로봇 최종 위치 : (%d, %d)\n", robot_p.x, robot_p.y);

    return 0;
}

//여기서 Position *p 는 포인터변수 p가 형태가 Position인 곳을 바라보도록 하겠다. 
void move(Position *p, int dx, int dy)  
{
    p->x += dx;
    p->y += dy;

}

*/

//차동구동 로봇 속도계산 
// *******************꼭 해보기*********************
typedef struct
{
    double left;
    double right;
}WheelSpeed;

typedef struct
{
    double linear;
    double angular;
}RobotSpeed;
RobotSpeed computerspeed(WheelSpeed w, double wheel_radius, double wheel_distance);

int main(void)
{
    printf("데이터를 입력하시오\n");

    RobotSpeed rs;
    WheelSpeed ws;  
    double w_rad, w_dis;
    printf("왼쪽 바퀴 속도(rad/s): ");
    scanf("%lf", &ws.left);
    printf("오른쪽 바퀴 속도(rad/s): ");
    scanf("%lf", &ws.right);
    printf("바퀴 반지름(m): ");
    scanf("%lf", &w_rad);
    printf("바퀴 간 거리(m): ");
    scanf("%lf", &w_dis);

    printf("\n");

    rs = computerspeed(ws, w_rad, w_dis);

    printf("선속도 : %.2lf\n", rs.linear);
    printf("각속도 : %.2lf\n", rs.angular);
}

RobotSpeed computerspeed(WheelSpeed w, double wheel_radius, double wheel_distance)
{

    RobotSpeed spd;

    spd.linear = 0, spd.angular = 0;
    spd.linear = wheel_radius * (w.left+w.right) / 2 ;
    spd.angular = wheel_radius * (w.right - w.left) / wheel_distance;

    return spd;
}