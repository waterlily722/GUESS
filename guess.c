#include <stdio.h>
#include <string.h>
#include<time.h>

char name[100] ,pas[100],temp[100];
char textstring[100];
int ok = 0;

int login()
{
    int len = 0;
    gets(name);
    gets(pas); 
    strcat(name,pas);//合并字符
    strcat(name,"\n");//添加换行字符
     
    FILE *fp = fopen("user.txt", "r");
    if(NULL == fp)
    {
        printf("failed to open dos.txt\n");
        return 1;
    }

    while(!feof(fp))
    {
        memset(textstring, 0, sizeof(textstring));
        fgets(textstring, sizeof(textstring) - 1, fp); 
        if(strcmp(name,textstring)==0)
        {
           ok=1;
           break;
        }
    }
    
    if(ok)
      printf("登录成功");
    else
      printf("登录失败");
    fclose(fp);

}

void regist(){
    FILE *fp=fopen("user.txt","a");//以写模式("w")打开文件user.txt,如果不存在,会自动创建
    printf("请输入账号：");
    gets(name);
    printf("请输入密码：");
    gets(pas); 
    fputs(name,fp);
    fputs(pas,fp);//将名称和密码以字符串形式写入文件
    fputs("\n",fp);
    fflush(stdin);//清除缓存
    fclose(fp);
}

void game()
{
	//生成一个随机数
	int ret = 0;
	int guess = 0;
	ret = rand()%100+1;//生成随机数  //处于一百取余得到1-99的数，然后+1得到1-100的数
	while (1)
	{
		printf("请猜一个数\n");
		scanf("%d",&guess);
		if (guess > ret)
		{
			printf("你猜大了\n");
		}
		else if (guess < ret)
		{
			printf("你猜小了\n");
		}
		else
		{
		    printf("恭喜你！猜对了\n");
			break;
		}
	}
}

void menu()
{
	printf("*************************\n");
	printf("***  1 play  0 exit   ***\n");
	printf("*************************\n");
}

int main()
{ 
    int input = 0;
    scanf("%d",&input);
    if(input)
       regist();
    else
        login();
    
    menu();
    switch (input)
	{ 
		case 1:
			game();
			//printf("进入游戏\n");
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新选择\n");
	}
	
    return 0;
}
