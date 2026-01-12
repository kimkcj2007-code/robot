int main(void)
{

    FILE *fp;
    int ch;
    char list[1000];
    fp = fopen("log.txt", "r");  //이거는 내 워크스페이스에 불러올 때 이렇게 쓰는거고,
    // 다른 곳에 위치한 파일을 가져올때는 경로를 그대로 가져와야 한다. 
    // 리눅스에서 / 기호는 $로 대신될 수 있다. 달러표시
    if(fp == NULL)
    {
        printf("파일이 열리지 않았습니다");
        return 1;

    }
    printf("파일이 열렸습니다.\n");


    fgets(list, sizeof(1000), fp);
    
    printf("%s", list);


    fclose(fp);