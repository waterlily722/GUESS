#include <stdio.h>
#include <string.h>
#include<time.h>

char name[100] ,pas[100],temp[100];
char textstring[100];
int ok = 0;

int login()
{
    int len = 0;
    printf("我已注册过-请输入 0 \n");
    printf("我是新用户-请输入 1 \n");
    printf("请输入账号：\n");
    gets(name);
    printf("请输入密码：\n");
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
    srand((unsigned int)time(NULL));  
    int x = rand() % 1000;  //1000以内的随机值；rand()函数可以用来产生随机数
    int y;
    int t1 = time(NULL);  //记录猜数时间 
    int j = 1;  //记录猜数次数 
    while (1)  //判断输入的数和猜的数的大小
    {
        scanf_s("%d", &y);
        if (x > y)
        {
            j++;	
            printf("猜小了\n");
        }
        else if (x < y)
        {
            j++;	
            printf("猜大了\n");
        }
        else
        {
            j++;	
            printf("恭喜你，猜对了!你一共用了%d次猜对,用时%d秒。\n",j,t2-t1);  
            break;
        }
 
    }
}

void menu()  //目录   
{
    printf("开始游戏-请输入 1\n");
    printf("退出游戏-请输入 0\n");
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
    guess:
    printf("请输入：\n");
    int a;
    scanf("%d", &a);
    switch (a)
    {
        case 1:
        printf("游戏开始！\n请输入你猜的数：\n");
        game();
        break;

        case 0:
        break;
        default:
        printf("选项错误!\n请重新输入：\n");
        goto guess;
    }
    
    return 0;
}
