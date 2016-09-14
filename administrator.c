#include"denglu.h"
#include"administrator.h"
//#include<time.h>
void adm_login()
{
	int i=1;
	while(i<=3)
	{
		char *name="123";
		char *passwd="123";
		char name1[20];
		char passwd1[20];
		char yan[20];
		system("clear");
		printf("\n\n\n\n\n\n\t\t\t\t\t\033[32m----------------------------------------------\n");
		printf("\t\t\t\t\t\t请输入用户名:");
		scanf("%s",name1);
		printf("\t\t\t\t\t\t请输入密码:");
		printf("\033[8m");
		scanf("%s",passwd1);
		printf("\033[0m\n");
		//			char * y=yzm();
		//	printf("\t\t\t\t\t\t验证码：");
		//	scanf("%s",yan);


		//	if(strcmp(y,yan)==0)
		//	{
		if(strcmp(name,name1)==0 && strcmp(passwd,passwd1)==0)
		{   
			Psth p=NULL,head=read_file();
			if(head!=NULL)
			{
				p=head->next;
				while(p!=NULL)
				{
					if(p->data.i != 1 )
					{
						p=p->next;
					}
					else
						if(p->data.i==1)
						{
							printf("\t\t\t\t\t\t\033[32m学号为%d的老师申请辞职\033[0m\n",p->data.id);
							break;
						}
				}
			}
			printf("\t\t\t\t\t\t\033[32m请按任意键登录\n");
			printf("\t\t\t\t\t-----------------------------------------------\033[0m\n");
			getchar();
			getchar();
			adm_func(name);
		}

		printf("\t\t\t\t\t\t\033[32m用户名或密码错误，请重新输入\033[0m\n");
		printf("\t\t\t\t\t\033[32m----------------------------------------------\n");
		sleep(2);
		i++;
	}
	while(i>3)
	{
		//	printf("\t\t\t\t\t\t\033[32m用户名或密码错误，请重新输入\033[0m\n");
		//  printf("\t\t\t\t\t\033[32m----------------------------------------------\n");
		sleep(2);
		delay();
		return ;
	}
	/*	else
		{
		printf("您输入的验证码有误\n");
		}*/
	}
	void delay()
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

	/*
	   char * yzm()
	   {
	   char a[27]="abcdefghijklmnopqrstuvwxyz";
	   int i,j;
	   printf("\t\t\t\t\t验证码：");
	   char output[4];
	   srand((int)time(0));
	   for(i=0;i<4;i++)
	   {
	   j=rand()%26;
	   printf("a[%d]=%p\n",j,&a[j]);
	   output[i]=a[j];
	   printf("output[%d]=%p\n",i,&output[i]);

	   }
	   printf("\n");
	//	for(i=0;i<9;i++)
	//	{
	printf("%s",output);
	//	}
	char * b=output;
	printf("\n");
	return b;
	}
	 */
	void adm_func(char *name)
	{
		while(1)
		{
			system("clear");
			printf("\n\n\n\n\n");
			system("tput setf 6");
			printf("\t\t\t\t\t**************欢迎 %s 登陆**************\n\n",name);
			system("tput setb 7");
			system("tput setf 4");
			printf("\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
			printf("\t\t\t\t\t@                                       @\n");
			system("tput setf 1");		
			printf("\t\t\t\t\t@    1 查看所有教师信息                 @\n");
			system("tput setf 2");
			printf("\t\t\t\t\t@    2 添加教师                         @\n");
			system("tput setf 6");
			printf("\t\t\t\t\t@    3 修改教师信息                     @\n");
			system("tput setf 3");
			printf("\t\t\t\t\t@    4 删除教师                         @\n");
			system("tput setf 4");
			printf("\t\t\t\t\t@    5 查找教师                         @\n");
			system("tput setf 5");
			printf("\t\t\t\t\t@    6 返回上一层                       @\n");
			system("tput setf 6");
			printf("\t\t\t\t\t@    7 退出                             @\n");
			system("tput setf 4");
			printf("\t\t\t\t\t@                                       @\n");
			printf("\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\033[0m\n");
			int key;
			printf("\t\t\t\t\t\033[32m请输入您的选择：\033[0m");
			scanf("%d",&key);
			switch(key)
			{
				case 1:
					system("clear");
					printf("\n\n\n\n\n\n\t\t\t\t\t\033[32m------------------------------------------------------\033[0m\n");
					sort_teacher();
					show();
					printf("\n\n\t\t\t\t\t\033[32m------------------------------------------------------\033[0m\n");
					break;
				case 2:
					system("clear");
					printf("\n\n\n\n\n\n\t\t\t\t\t\033[32m------------------------------------------------------\n");
					add_teacher();
					sort_teacher();
					printf("\t\t\t\t\t------------------------------------------------------\033[0m\n");
					show();

					break;
				case 3:
					system("clear");
					printf("\033[32m\n\n\n\t\t\t\t\t------------------------------------------------------\n");
					alter_teacher();
					printf("\t\t\t\t\t\033[32m------------------------------------------------------\033[0m\n");
					sort_teacher();
					show();

					break;
				case 4:
					system("clear");
					printf("\n\n\n\n\n\t\t\t\t\t\033[32m------------------------------------------------------\n");
					delete_teacher();
					printf("\t\t\t\t\t------------------------------------------------------\033[0m\n");
					sort_teacher();
					show();
					break;
				case 5:	
					system("clear");
					look_up();
					break;
				case 6:
					return denglu();
				case 7:
					exit(0);
				default :
					printf("\t\t\t\t\t\t\033[32m输入有误，请重新输入\033[0m\n");
					break;
			}
			printf("\t\t\t\t\t\033[32m请按任意键继续\033[0m");
			getchar();
			getchar();
		}
	}
	//添加教师成员
	void add_teacher()
	{
		Psth head=read_file();
		if(head==NULL)
		{
			head=(Psth)malloc(sizeof(STH));
			head->next=NULL;
		}
		Psth p=NULL;
		Psth temp=(Psth)malloc(sizeof(STH));

		while(1)
		{
			int id;
			printf("\t\t\t\t\t\t请输入您要添加的id:");
			scanf("%d",&id);
			p=search_teacher(id);
			if(p==NULL)
			{
				temp->data.id=id;
				break;
			}
			else
			{
				printf("\t\t\t\t\t\t您要添加的id已存在，请重新输入\n");

			}
		}
		printf("\t\t\t\t\t\t请输入您要添加的name:");
		scanf("%s",temp->data.name);
		printf("\t\t\t\t\t\t请输入您要添加的passwd:");
		scanf("%s",temp->data.passwd);
		printf("\t\t\t\t\t\t请输入您要添加的subject:");
		scanf("%s",temp->data.subject);
		temp->next=head->next;
		head->next=temp;

		printf("\t\t\t\t\t\t添加成功\n");


		write_file(head);
		return ;
	}
	void delete_teacher()
	{
		Psth head=read_file();
		if(head==NULL||head->next==NULL)
		{
			printf("\t\t\t\t\t\t\033[32m系统无用户\03[0m\n");
			return ;
		}
		int id;

		printf("\t\t\t\t\t\t请输入您要删除的老师的id号:");
		scanf("%d",&id);
		Psth p=head,q;
		q=p->next;
		while(q!=NULL)
		{
			if(q->data.id==id)
			{
				p->next=q->next;
				free(q);
				q=NULL;
				write_file(head);
				printf("\t\t\t\t\t\t删除成功\n");

				return ;
			}
			p=p->next;
			q=q->next;
		}

	}
	//查找教师成员
	Psth search_teacher(int id)
	{
		Psth head=read_file();
		if(head==NULL||head->next==NULL)
		{
			printf("\t\t\t\t\t\t\033[32m系统无用户\n");
			return NULL;
		}
		Psth p=head->next;
		while(p!=NULL)
		{
			if(p->data.id==id)
			{
				return p;
			}

			p=p->next;
		}
		return p;
	}

	//写文件
	void write_file(Psth head)
	{
		FILE *fp;
		if((fp=fopen("teacher.txt","w"))==NULL)
		{
			printf("\t\t\t\t\t\033[32mopen failed\033[0m\n");
			return ;
		}
		if(head==NULL||head->next==NULL)
		{
			printf("\t\t\t\t\t\t\033[32m系统无用户\033[0m\n");
			return ;
		}
		head=head->next;
		while(head!=NULL)
		{
			fprintf(fp,"%d\t%d\t%s\t%s\t%s\n",head->data.i,head->data.id,head->data.name,head->data.passwd,head->data.subject);
			head=head->next;
		}
		fclose(fp);
	}

	//读文件
	Psth read_file()
	{
		FILE *fp;
		if((fp=fopen("teacher.txt","r"))==NULL)
		{
			printf("\t\t\t\t\t\t\033[32m系统无用户\n");
			return NULL;
		}
		Psth head=(Psth)malloc(sizeof(STH));
		head->next=NULL;
		Psth temp=(Psth)malloc(sizeof(STH));
		while((fscanf(fp,"%d\t%d\t%s\t%s\t%s\n",&temp->data.i,&temp->data.id,temp->data.name,temp->data.passwd,temp->data.subject))>0)
		{
			temp->next=head->next;
			head->next=temp;
			temp=NULL;
			temp=(Psth)malloc(sizeof(STH));
		}
		free(temp);
		temp=NULL;
		fclose(fp);
		return head;
	}
	//显示链表
	void show()
	{
		Psth head=read_file();
		if(head!=NULL)
		{
			if(head==NULL||head->next==NULL)
			{
				printf("\t\t\t\t\t\t\033[32m系统无用户\033[03m\n");
				return ;
			}

			printf("\033[32m\n\n\t\t\t\t\t------------------------------------------------------\n");
			printf("\t\t\t\t\t\tid\tname\tpasswd\tsubject\n");
			Psth p=head->next;
			while(p!=NULL)
			{
				printf("\t\t\t\t\t\t%d\t%s\t%s\t%s\n",p->data.id,p->data.name,p->data.passwd,p->data.subject);
				p=p->next;
			}
			printf("\t\t\t\t\t------------------------------------------------------\033[0m\n");
		}
		return ;
	}
	void alter_teacher()
	{

		printf("\t\t\t\t\t\t您要修改的老师的id：");
		int id;
		scanf("%d",&id);

		Psth head=read_file();
		if(head!=NULL)
		{
			Psth temp=head->next;
			while(temp!=NULL)
			{
				if(temp->data.id==id)
				{

					break;
				}
				temp=temp->next;
			}
			if(temp==NULL)
			{
				printf("\t\t\t\t\t\t您输入的id不存在，请重新输入\n");
			}
			else
				if(temp!=NULL)
				{    

					char a[20]="name";
					char b[20]="subject";
					char c[20]="id";
					char a1[20];
					char b1[20];        
					printf("\t\t\t\t\t\t请输入您要修改的项目名称name或subject:");
					scanf("%s",a1);
					if(strcmp(a,a1)==0)
					{  
						printf("\t\t\t\t\t\t请输入您要修改的名字:");
						scanf("%s",b1);
						strcpy(temp->data.name,b1);
						write_file(head);

						printf("\t\t\t\t\t\t修改成功\n");


					}
					else
						if(strcmp(b,a1)==0)
						{ 

							printf("\t\t\t\t\t\t请输入您要修改的科目:");
							scanf("%s",b1);
							strcpy(temp->data.subject,b1);
							write_file(head);
							printf("\t\t\t\t\t\t修改成功\n");


						}
				}
		}
		return ;
	}
	void sort_teacher()
	{
		Psth head=read_file();
		if(head!=NULL)
		{
			Psth r=head->next;
			int n=0;
			while(r!=NULL)
			{
				r=r->next;
				n++;
			}
			int i,j;
			Psth p,w,MAX;
			Psth temp=(Psth)malloc(sizeof(STH));
			p=head->next;
			for(i=0;i<n-1;i++)
			{
				MAX=p;
				w=p->next;
				for(j=i+1;j<n;j++)
				{
					if(MAX->data.id <  w->data.id)
					{
						MAX=w;
					}
					w=w->next;
				}
				if(MAX!=p)
				{
					temp->data=MAX->data;
					MAX->data=p->data;
					p->data=temp->data;
				}
				p=p->next;
			}
			free(temp);
			temp=NULL;
			r=head->next;
			write_file(head);
		}
	}

	void look_up()
	{
		printf("\n\n\n\n\n\t\t\t\t\t\033[32m----------------------------------------\n");
		printf("\t\t\t\t\t请输入您要查找的教师id：");
		int id;
		Psth p=NULL;
		scanf("%d",&id);
		p=search_teacher(id);
		if(p==NULL)
		{
			printf("\t\t\t\t\t查无此人\n");
		}
		else
		{
			printf("\t\t\t\t\tid\tname\tpasswd\tsubject\n");
			printf("\t\t\t\t\t%d\t%s\t%s\t%s\n",p->data.id,p->data.name,p->data.passwd,p->data.subject);
		}

		printf("\t\t\t\t\t----------------------------------------\033[0m\n");
		return ;
	}
