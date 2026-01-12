// 1월 12일 수업 구조체
// *******************파일 읽어오기*********************
// ******파일 읽기 과제 중요하다 문제 확인하자*********************
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define PI 3.14159265358979323846

/*
int main(void)
{
    FILE *fp;

    fp = fopen("a.txt", "r");  //이거는 내 워크스페이스에 불러올 때 이렇게 쓰는거고,
    // 다른 곳에 위치한 파일을 가져올때는 경로를 그대로 가져와야 한다. 
    // 리눅스에서 / 기호는 $로 대신될 수 있다. 달러표시
    if(fp == NULL)
    {
        printf("파일이 열리지 않았습니다");
        return 1;

    }
    printf("파일이 열렸습니다.\n");
    fclose(fp);

    return 0;
}
*/
/*
int main(void)
{
    FILE *fp;
    int ch;

    fp = fopen("a.txt", "r");  //이거는 내 워크스페이스에 불러올 때 이렇게 쓰는거고,
    // 다른 곳에 위치한 파일을 가져올때는 경로를 그대로 가져와야 한다. 
    // 리눅스에서 / 기호는 $로 대신될 수 있다. 달러표시
    if(fp == NULL)
    {
        printf("파일이 열리지 않았습니다");
        return 1;

    }
    while(1)
    {
        ch = fgetc(fp);
        if(ch==EOF)
        {
            break;
        }
        putchar(ch);
    }
    fclose(fp);

    return 0;
}
    */

/*
int main(void)
{
    FILE *fp;

    char str[] = "apple";
    int i;

    fp = fopen("c.txt", "a");
    if(fp == NULL)
    {
        printf("파일을 만들지 못했습니다.\n");
        return 1;
    }
    printf("파일을 열었습니다.\n");
    i = 0;

    while(str[i] != '\0')
    {
        fputc(str[i], fp);
        i++;
    }
    fputc('\n', fp);
    fclose(fp);
    printf("파일에 입력, 저장되었습니다.\n");

    return 0;
}
*/

/*
int main(void)
{
    int ch;

    while(1)
    {
        ch = getchar(); //"문자"를 받는 함수
        if(ch == EOF)
        {
            break;
        }
        putchar(ch);
    }
    return 0;
}

*/

/*
int main(void)
{
    int ch;
    while(1)
    {
        ch = fgetc(stdin);
        if(ch == EOF)
        {
            break;
        }
        fputc(ch, stdout);
    }

    return 0;
}
*/

//***************중요한 문제 *************************
//******************문제******************* 

//log.txt 파일을 읽어서, 에러가 몇회인지, 어떤 에러인지 알려주는 프로그램을 작성하라
//문자열로 접근해야 한다. 

/*
int main(void)
{

    FILE *fp;
    int ch;
    char list[30][100];
    int count = 0;
    int count_s = 0, count_m = 0, count_b=0;
    int count_error = 0;
    fp = fopen("log.txt", "r");  //이거는 내 워크스페이스에 불러올 때 이렇게 쓰는거고,
    // 다른 곳에 위치한 파일을 가져올때는 경로를 그대로 가져와야 한다. 
    // 리눅스에서 / 기호는 $로 대신될 수 있다. 달러표시
    if(fp == NULL)
    {
        printf("파일이 열리지 않았습니다");
        return 1;

    }
    printf("파일이 열렸습니다.\n");

    //fgets를 두번 호출하면, 두번 읽는거다
    //이건 if문이나 while문같은 조건문에 들어가도 마찬가지다. 
    for(int i=0; i<30; i++)
    {
        if(fgets(list[i], sizeof(list[0]),fp)==NULL)  
        {
            break; 
        }
        count++;

    }
    for(int i=0; i<count; i++)
    {
        printf("%s\n", list[i]);
    }
    //printf("%s", list);

    
    for(int i=0; i<count; i++)
    {
        if(strstr(list[i],"Sensor failed"))
        {
            count_s++;
        }
        if(strstr(list[i],"Motor overload"))
        {
            count_m++;
        }
        if(strstr(list[i],"Low battery"))
        {
            count_b++;
        }
        if(strstr(list[i],"ERROR"))
        {
            count_error++;
        }
    }
    
    printf("에러 개수: %d\n", count_error);
    printf("모터에러: %d, 센서에러: %d\n", count_m, count_s);
    printf("배터리 경고: %d\n", count_b);
    fclose(fp);

    return 0;
}
*/

// 중요한 문제2 
//**********************문제2 ***********************************
// IPV4 는 두줄이 한줄? 
// 문제1 핑 요청횟수 세기 ping이 총 몇번 감지 되었는지
// 문제2 가장 많은 ping을 요청한 주소는 무엇인지 검출하기
// 문제3 시간대별 ping 요청 횟수 및 가장 잦은 IP(주소는)?


// 문제1은 간단
// 문제2번은 배열을 특정 위치부터 읽을 방법이 필요하다. 그리고 중복을 제거해야 함 
// 그리고 중복을 제거한 값들을, 기존의 배열과 비교해야 할 것 같다.  
//***********매우 복잡하게 짜버렸다. 기회가 되면 나중에 다시 짜보는게 좋을 것 같다******

/*
//문제 1, 문제2 한꺼번에 구현한 코드 

int main(void)
{

    FILE *fp;
    int ch;
    char list[150][1000];
    char copy_list[150][1000]; //배열을 복사해서 

    int count = 0;
    int call_ping = 0, max_ping = 0, v4_ping=0;
    int count_error = 0;
    fp = fopen("fast.log", "r");  //이거는 내 워크스페이스에 불러올 때 이렇게 쓰는거고,
    // 다른 곳에 위치한 파일을 가져올때는 경로를 그대로 가져와야 한다. 
    // 리눅스에서 / 기호는 $로 대신될 수 있다. 달러표시
    if(fp == NULL)
    {
        printf("파일이 열리지 않았습니다");
        return 1;

    }
    printf("파일이 열렸습니다.\n");

    //fgets를 두번 호출하면, 두번 읽는거다
    //이건 if문이나 while문같은 조건문에 들어가도 마찬가지다. 
    for(int i=0; i<150; i++)
    {
        if(fgets(list[i], sizeof(list[0]),fp)==NULL)  
        {
            break; 
        }
        if(strstr(list[i],"Ping"))
        {
            call_ping++;
        }
        if(strstr(list[i],"{ICMP}"))
        {
            v4_ping++;
        }
        count++;  //데이터 개수 
    }
    for(int j=0;j<count;j++)
    {
        char *p1 = strstr(list[j]," fe");
        char *p2 = strstr(list[j]," ->");
        if(p1==NULL)
        {
            p1 = strstr(list[j],"192");
            int len = p2 - p1;
            strncpy(copy_list[j], p1, len-2);

        }
        else
        {
            int len = p2 - p1;
            strncpy(copy_list[j], p1, len-4);
        }
        //printf("%s\n", copy_list[j]);
    }
    
    char del_list[100][1000]; //중복을 제거한 배열
    int cnt = 0;

    for(int i=0;i<count;i++)
    {   
        int tri = 0;

        for(int j=0;j<cnt;j++)
        {
            if(strcmp(copy_list[i], del_list[j])== 0)//문자열 비교 같다면 작동 (0반환)
            {// 주소가 담긴 문자열과, 중복을 제거한 문자열을 비교하겠다. 같으면 0반환
                tri = 1;
                break;
            }
        }

        if(tri == 0)
        {   
            strcpy(del_list[cnt], copy_list[i]);
            printf("%s\n", del_list[cnt]);
            cnt++;
        }
    }

    int cnt1[cnt];
    for(int i=0; i<cnt; i++)
    {
        cnt1[i] = 0;
    }
    
    for(int i=0; i<cnt; i++)
    {
        for(int j=0;j<count;j++)
        {
            if(strcmp(copy_list[j], del_list[i]) == 0)  //같다면? 
            {
                cnt1[i] = cnt1[i] + 1;
            }
        }
        printf("%d번 주소 중복횟수 : %d\n",i+1, cnt1[i]);
    }
    int max = 0, max_cnt = 0;
    max = cnt1[0];
    for(int i=1; i<cnt; i++)
    {
        if(cnt1[i]>max)
        {
            max = cnt1[i];
            max_cnt = i;
        }
    }

    v4_ping = v4_ping / 2;
    printf("\n총 데이터 개수: %d\n", (count));
    printf("Ping 감지 횟수: %d\n", call_ping);
    printf("IPV4 중복 제거 ping 감지 횟수: %d\n", (call_ping - v4_ping));

    printf("가장 많은 ping을 요청한 주소: %s\n", del_list[max_cnt]);

    
    fclose(fp);

    return 0;
}

*/

//문제 3
//문제 1, 2에서 수정하는 식으로 작성해보자 
// 작성하다가 중단됨 // 추후 마저 작성해보면 좋을 것 같다
int main(void)
{

    FILE *fp;
    int ch;
    char list[150][1000];
    char copy_list[150][1000]; //배열을 복사해서 

    int count = 0;
    int call_ping = 0, max_ping = 0, v4_ping=0;
    int count_error = 0;
    fp = fopen("fast.log", "r");  //이거는 내 워크스페이스에 불러올 때 이렇게 쓰는거고,
    // 다른 곳에 위치한 파일을 가져올때는 경로를 그대로 가져와야 한다. 
    // 리눅스에서 / 기호는 $로 대신될 수 있다. 달러표시
    if(fp == NULL)
    {
        printf("파일이 열리지 않았습니다");
        return 1;

    }
    printf("파일이 열렸습니다.\n");

    //fgets를 두번 호출하면, 두번 읽는거다
    //이건 if문이나 while문같은 조건문에 들어가도 마찬가지다. 
    for(int i=0; i<150; i++)
    {
        if(fgets(list[i], sizeof(list[0]),fp)==NULL)//fgets로 fp에 있는 값을 list[i]에 가져왔다.
        {//저 함수 자체로 가져오기 한번을 진행한거고, 다음 가져오는 포인트는 그 다음 위치에서 진행된다.SS
            break; 
        }
        if(strstr(list[i],"Ping"))
        {
            call_ping++;
        }
        if(strstr(list[i],"{ICMP}"))
        {
            v4_ping++;
        }
        count++;  //데이터 개수 
    }

    for(int j=0;j<count;j++)
    {
        char *p1 = strstr(list[j]," fe");
        char *p2 = strstr(list[j]," ->");
        if(p1==NULL)
        {
            p1 = strstr(list[j],"192");
            int len = p2 - p1;
            strncpy(copy_list[j], p1, len-2);

        }
        else
        {
            int len = p2 - p1;
            strncpy(copy_list[j], p1, len-4);
        }
        //printf("%s\n", copy_list[j]);
    }
    
    char del_list[100][1000]; //중복을 제거한 배열
    int cnt = 0;

    for(int i=0;i<count;i++)
    {   
        int tri = 0;

        for(int j=0;j<cnt;j++)
        {
            if(strcmp(copy_list[i], del_list[j])== 0)//문자열 비교 같다면 작동 (0반환)
            {// 주소가 담긴 문자열과, 중복을 제거한 문자열을 비교하겠다. 같으면 0반환
                tri = 1;
                break;
            }
        }

        if(tri == 0)
        {   
            strcpy(del_list[cnt], copy_list[i]);
            printf("%s\n", del_list[cnt]);
            cnt++;
        }
    }

    int cnt1[cnt];
    for(int i=0; i<cnt; i++)
    {
        cnt1[i] = 0;
    }
    
    for(int i=0; i<cnt; i++)
    {
        for(int j=0;j<count;j++)
        {
            if(strcmp(copy_list[j], del_list[i]) == 0)  //같다면? 
            {
                cnt1[i] = cnt1[i] + 1;
            }
        }
        printf("%d번 주소 중복횟수 : %d\n",i+1, cnt1[i]);
    }
    int max = 0, max_cnt = 0;
    max = cnt1[0];
    for(int i=1; i<cnt; i++)
    {
        if(cnt1[i]>max)
        {
            max = cnt1[i];
            max_cnt = i;
        }
    }

    v4_ping = v4_ping / 2;
    printf("\n총 데이터 개수: %d\n", (count));
    printf("Ping 감지 횟수: %d\n", call_ping);
    printf("IPV4 중복 제거 ping 감지 횟수: %d\n", (call_ping - v4_ping));

    printf("가장 많은 ping을 요청한 주소: %s\n", del_list[max_cnt]);

    
    fclose(fp);

    return 0;
}