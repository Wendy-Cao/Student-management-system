#include"denglu.h"
#include"student.h"
#include"teacher.h"
#include<unistd.h>
void student_login()
{
    int i=1;
	int id;
    while(i<=3)
	{
	char passwd[20];
	system("clear");
	printf("\n\n\n\n\n\n\t\t\t\t\t\033[32m----------------------------------------------\n");
	printf("\t\t\t\t\t\t请输入您的id号：");
	scanf("%d",&id);
	printf("\t\t\t\t\t\t请输入您的密码：");
	printf("\033[8m");
	scanf("%s",passwd);
	printf("\033[0m\n");
	Pstu head=read_student();
	if(head==NULL||head->next==NULL)
	{
		printf("\t\t\t\t\t\t\033[32m系统无用户\033[0m\n");
		printf("\t\t\t\t\t\033[32m----------------------------------------------\033[0m\n");
		sleep(2);
		return ;
	}
	Pstu p=head->next;
	while(p!=NULL)
	{
		if(strcmp(p->data.passwd,passwd)==0 && id==p->data.id)
		{

			student_func(head,p);
			return ;
		}
		p=p->next;
	}
	
		printf("\t\t\t\t\t\t\033[32m您输入的用户名或者密码有误,请重新输入\n");
		printf("\t\t\t\t\t----------------------------------------------\033[0m\n");
		i++;
		sleep(2);
	}
	while(i>3)
	{
	delay3();
	return denglu();
	}
}
void delay3()
{
	int i;
	for(i=10;i>=0;i--)
	{
		system("clear");
		printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\033[32m------------------------------------------------------\n\n");
		printf("\t\t\t\t\t\t三次输入错误，请等待10s");
		printf("\n\n\n");
		printf("\t\t\t\t\t\t还剩%ds\n\n",i);
		printf("\t\t\t\t\t------------------------------------------------------\033[0m\n\n");
		sleep(1);
	}
}

void student_func(Pstu head,Pstu p)
{
	while(1)
	{
		system("clear");

		printf("\n\n\n\n\n\n\n\n");
		system("tput setf 6");
		printf("\t\t\t\t\t\t************欢迎 %s 登陆************\n\n",p->data.name);
		system("tput setb 7");
		system("tput setf 4");
		printf("\t\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
		system("tput setf 4");
		printf("\t\t\t\t\t\t@                                  @\n");
		system("tput setf 3");
		printf("\t\t\t\t\t\t@ 1查看成绩                        @\n");
		system("tput setf 1");
		printf("\t\t\t\t\t\t@                                  @\n");
		system("tput setf 5");
		printf("\t\t\t\t\t\t@ 2修改密码                        @\n");
		system("tput setf 1");
		printf("\t\t\t\t\t\t@                                  @\n");
		system("tput setf 6");
		printf("\t\t\t\t\t\t@ 3查看排名                        @\n");
		system("tput setf 1");
		printf("\t\t\t\t\t\t@                                  @\n");
		system("tput setf 5");
		printf("\t\t\t\t\t\t@ 4返回上一级                      @\n");
		system("tput setf 3");
		printf("\t\t\t\t\t\t@                                  @\n");
		system("tput setf 3");
		printf("\t\t\t\t\t\t@ 5注销                            @\n");
		system("tput setf 1");
		printf("\t\t\t\t\t\t@                                  @\n");
		system("tput setf 4");
		printf("\t\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\033[0m\n");
		system("tput setf 6");
		printf("\t\t\t\t\t\t请输入您的选择:\033[0m");
		int key;
		scanf("%d",&key);
		switch(key)
		{
			case 1:
				{
					system("clear");
					printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\033[32m-------------------------------------------\n\n");
					printf("\t\t\t\t\tchinese\tmath\tenglish\tchm\tscore\n");
					printf("\t\t\t\t\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\n",p->data.chinese,p->data.math,p->data.english,p->data.chm,p->data.score);
					printf("\n\t\t\t\t\t-------------------------------------------\033[0m\n\n");
				}
				break;
			case 2:
				{
					system("clear");
					printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\033[32m-------------------------------------------\n\n");
					char passwd[20];
					printf("\t\t\t\t\t\t请输入您要修改的密码:");
					scanf("%s",passwd);
					strcpy(p->data.passwd,passwd);
					write_student(head);
					printf("\t\t\t\t\t\t修改成功,请重新登陆\n");
					printf("\n\t\t\t\t\t-------------------------------------------\033[0m\n\n");
					printf("\t\t\t\t\t\t\033[32m请按任意键继续\033[03m\n");
					getchar();
					getchar();
				}
				return ;
			case 3:
				{
					system("clear");
					printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\033[32m-------------------------------------------\n\n");
					printf("\t\t\t\t\t\t您的排名是:  ");
					printf("第%d名",p->raking);
					printf("\n\t\t\t\t\t-------------------------------------------\033[0m\n\n");
				}
				break;
			case 4:
				return ;
			case 5:
				exit(0);
			default :
				system("clear");
				printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\033[32m-------------------------------------------\n\n");
				printf("\t\t\t\t\t\t您的输入有误，请重新输入\n");
				printf("\n\t\t\t\t\t-------------------------------------------\033[0m\n\n");
				break;
		}
		printf("\t\t\t\t\t\033[32m请输入任意键继续\033[0m\n");
		getchar();
		getchar();
	}
}
