#include"denglu.h"
#include"administrator.h"
#include"teacher.h"


void teacher_login()
{

	int i=1;
	while(i<=3)
	{
		int id;
		char passwd[20];
		system("clear");
		printf("\n\n\n\n\n\n\n\t\t\t\t\t\033[32m--------------------------------------\n");
		printf("\t\t\t\t\t\t请输入您的id号:");
		scanf("%d",&id);
		printf("\t\t\t\t\t\t请输入您的密码:");
		printf("\033[8m");
		scanf("%s",passwd);
		printf("\033[0m\n");
		Psth head=read_file();
		if(head==NULL||head->next==NULL)
		{
			printf("\t\t\t\t\t\t\033[32m系统无用户\n");
                        printf("\t\t\t\t\t--------------------------------------\033[0m\n");
			sleep(2);
                        return ;
		}


		Psth p=head->next;
		while(p!=NULL)
		{
			if(strcmp(p->data.passwd,passwd)==0 && id==p->data.id)
			{
				printf("\t\t\t\t\t\t\033[32m请按任意键登录\n");
				printf("\t\t\t\t\t--------------------------------------\033[0m\n");
				getchar();
				getchar();
				teacher_func(head,p);
				return ;
			}
			p=p->next;
		}
		printf("\t\t\t\t\t\033[32m您输入的用户名或者密码有误,请重新输入\n");
		printf("\t\t\t\t\t--------------------------------------\033[0m\n");
		i++;
		sleep(2);
	}
	while(i>3)
	{
		delay();
		return ;
	}



}
void delay1()
{
	int i;
	for(i=10;i>=0;i--)
	{
		system("clear");
		printf("\t\t\t\t\t三次输入有误，请等待10s\n");
		printf("\n\n\n");
		printf("\t\t\t\t\t\033[32还剩%d\033[0m\n",i);
		printf("\t\t\t\t\t--------------------------------------\033[0m\n");
		sleep(1);
	}
}
void teacher_func(Psth head,Psth p)
{
	while(1)
	{
		system("clear");
		printf("\n\n\n\n\n\n");
		system("tput setf 6");
		printf("\t\t\t\t\t****************欢迎 %s 登陆****************\n\n",p->data.name);
		system("tput setb 7");
		system("tput setf 4");
		printf("\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
		printf("\t\t\t\t\t@                                          @\n");
		system("tput setf 1");
		printf("\t\t\t\t\t@    1添加学生信息                         @\n");
		system("tput setf 5");
		printf("\t\t\t\t\t@    2录入学生成绩                         @\n");
		system("tput setf 2");
		printf("\t\t\t\t\t@    3查找学生                             @\n");
		system("tput setf 3");
		printf("\t\t\t\t\t@    4修改学生信息                         @\n");
		system("tput setf 5");
		printf("\t\t\t\t\t@    5修改教师登陆密码                     @\n");
		system("tput setf 6");
		printf("\t\t\t\t\t@    6查看学生排名                         @\n");
		system("tput setf 2");
		printf("\t\t\t\t\t@    7删除学生                             @\n");
		system("tput setf 1");
		printf("\t\t\t\t\t@    8辞职申请                             @\n");
		system("tput setf 5");
		printf("\t\t\t\t\t@    9返回上一级                           @\n");
		system("tput setf 3");
		printf("\t\t\t\t\t@    10注销                                @\n");
		system("tput setf 4");
		printf("\t\t\t\t\t@                                          @\n");
		system("tput setf 4");
		printf("\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\033[0m\n");
		printf("\t\t\t\t\t\033[32m请输入您的选择:\033[0m");
		int key;
		scanf("%d",&key);
		switch(key)
		{	
			case 1:
				system("clear");
				add_student(p);
				break;
			case 2:
				system("clear");
				add_score(p);
				show_student();
				break;
			case 3:
				system("clear");
				look_up_student();
				break;
			case 4:
				system("clear");
				alter_student(p);
				break;
			case 5:
				{
					system("clear");
					printf("\n\n\n\n\n\t\t\t\t\t\033[32m--------------------------------------\n");
					char passwd[20];
					printf("\t\t\t\t\t请输入您的新密码:");
					scanf("%s",passwd);
					strcpy(p->data.passwd,passwd);
					write_file(head);
					printf("\t\t\t\t\t修改成功,请重新登陆\n");
					printf("\t\t\t\t\t--------------------------------------\033[0m\n");
					printf("\t\t\t\t\t\033[32m请按任意键继续\033[0m");
					getchar();
					getchar();
				}
				return ;
				break;
			case 6:
				system("clear");
				sort_student();
				show_student();
				break;
			case 7:
				system("clear");	
				delete_student(p);
				sort_student();
				break;
			case 8:
				system("clear");
				quit_apply(head,p);
				break;
			case 9:
				return ;
			case 10:
				exit(0);
		}
		printf("\t\t\t\t\t\t\033[32m请按任意键继续\033[0m");
		getchar();
		getchar();
	}
}
//添加学生
void add_student(Psth p)
{
	char a[20]="supervisor";
	Pstu head=read_student();
	if(strcmp(p->data.subject,a)==0)
	{
		if(head==NULL)
		{
			head=(Pstu)malloc(sizeof(STU));
			head->next=NULL;
		}
		Pstu q=NULL;
		printf("\n\n\n\n\n\n\t\t\t\t\t\033[32m-----------------------------------\n");
		Pstu temp=(Pstu)malloc(sizeof(STU));
		while(1)
		{
			printf("\t\t\t\t\t请输入您要添加的学生id:");
			int id;
			scanf("%d",&id);
			q=search_student(id);
			if(q==NULL)
			{
				temp->data.id=id;
				break;
			}
			else
			{
				printf("\t\t\t\t\tid已存在，请重新输入\n");
			}

		}
		printf("\t\t\t\t\t请输入您要添加的学生的name：");
		scanf("%s",temp->data.name);
		printf("\t\t\t\t\t请输入您要添加的学生的passwd：");
		scanf("%s",temp->data.passwd);

		temp->data.chinese=0;
		temp->data.math=0;
		temp->data.english=0;
		temp->data.chm=0;
		temp->next=head->next;
		head->next=temp;
		printf("\t\t\t\t\t添加成功\n");
		write_student(head);
		printf("\t\t\t\t\t-----------------------------------\033[0m\n");
		sort_student();
		show_student();
	}
	else
	{
		printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\033[32m-------------------------------------------\n\n");
		printf("\t\t\t\t\t\t您的权限不够\n");
		printf("\n\t\t\t\t\t-------------------------------------------\033[0m\n\n");
	}
	return ;
}
//删除学生
void delete_student(Psth p)
{
	char a[20]="supervisor";
	if(strcmp(p->data.subject,a)==0)
	{
		Pstu head=read_student();
		if(head==NULL||head->next==NULL)
		{
			printf("\t\t\t\t\t\t系统无用户\n");
			return ;
		}
		int id;
		printf("\n\n\n\n\n\t\t\t\t\t\033[32m------------------------------------------------------\n");
		printf("\t\t\t\t\t\t请输入您要删除的学生的id号:");
		scanf("%d",&id);
		Pstu p=head,q;
		q=p->next;
		while(q!=NULL)
		{
			if(q->data.id==id)
			{
				p->next=q->next;
				free(q);
				q=NULL;
				write_student(head);
				printf("\t\t\t\t\t\t\033[32m删除成功\n");
				printf("\t\t\t\t\t------------------------------------------------------\033[0m\n");
				return ;
			}
			p=p->next;
			q=q->next;
		}

	}
	else
	{
		printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\033[32m-------------------------------------------\n\n");
		printf("\t\t\t\t\t\t您的权限不够\n");
		printf("\n\t\t\t\t\t-------------------------------------------\033[0m\n\n");
	}
	return ;
}



//读文件
Pstu read_student()
{
	FILE *fp;
	if((fp=fopen("student.txt","r"))==NULL)
	{
		printf("\t\t\t\t\t\t\033[32m系统无用户\n");
		return NULL;
	}
	Pstu head=(Pstu)malloc(sizeof(STU));
	head->next=NULL;
	Pstu temp=(Pstu)malloc(sizeof(STU));
	while((fscanf(fp,"%d\t%d\t%s\t%s\t%lf\t%lf\t%lf\t%lf\t%lf\n",&temp->raking,&temp->data.id,temp->data.name,temp->data.passwd,&temp->data.chinese,&temp->data.math,&temp->data.english,&temp->data.chm,&temp->data.score))>0)
	{
		temp->next=head->next;
		head->next=temp;
		temp=NULL;
		temp=(Pstu)malloc(sizeof(STU));
	}
	free(temp);
	temp=NULL;
	fclose(fp);
	return head;
}
//写文件
void write_student(Pstu head)
{
	FILE *fp;
	if((fp=fopen("student.txt","w"))==NULL)
	{
		printf("\t\t\t\t\t\t系统无用户\n");
		return ;
	}

	if(head==NULL||head->next==NULL)
	{
		printf("\t\t\t\t\t\t系统无用户\n");
		return ;
	}
	head=head->next;
	while(head!=NULL)
	{
		fprintf(fp,"%d\t%d\t%s\t%s\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\n",head->raking,head->data.id,head->data.name,head->data.passwd,head->data.chinese,head->data.math,head->data.english,head->data.chm,head->data.score);
		head=head->next;
	}
	fclose(fp);
}

//查找学生成员
Pstu search_student(int id)
{
	Pstu head=read_student();
	if(head==NULL||head->next==NULL)
	{
		printf("\t\t\t\t\t\t系统无用户\n");
		return NULL;
	}
	Pstu p=head->next;
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
//查看学生成绩
void show_student()
{
	Pstu head=read_student();
	if(head==NULL||head->next==NULL)
	{
		printf("\t\t\t\t\t\t系统无用户\n");
		return ;
	}
	printf("\n\n\n\n\n\t\t\t\t\t\033[32m---------------------------------------------------------------------\n");
	printf("\t\t\t\t\traking\tid\tname\tpasswd\tchinese\tmath\tenglish\tchm\tscore\n");
	head=head->next;
	while(head!=NULL)
	{
		printf("\t\t\t\t\t%d\t%d\t%s\t%s\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\n",head->raking,head->data.id,head->data.name,head->data.passwd,head->data.chinese,head->data.math,head->data.english,head->data.chm,head->data.score);
		head=head->next;
	}
	printf("\t\t\t\t\t---------------------------------------------------------------------\033[0m\n");
	return ;
}
//学生排名
void sort_student()
{
	Pstu head=read_student();
	if(head!=NULL)
	{
		Pstu r=head->next;
		int n=0;
		while(r!=NULL)
		{   
			r->data.score=r->data.chinese+r->data.math+r->data.english+r->data.chm;
			r=r->next;
			n++;
		}
		int i,j;
		Pstu p,w,MAX;
		Pstu temp=(Pstu)malloc(sizeof(STU));
		p=head->next;
		for(i=0;i<n-1;i++)
		{
			MAX=p;
			w=p->next;
			for(j=i+1;j<n;j++)
			{
				if(MAX->data.score >  w->data.score)
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

		for(i=1;i<=n;i++)
		{
			r->raking=n+1-i;
			r=r->next;
		}
		write_student(head);
	}
	return ;
}
void add_score(Psth p)
{

	printf("\n\n\n\n\n\t\t\t\t\t\033[32m------------------------------------------------\n");
	printf("\t\t\t\t\t\t请输入您要录入的学科的名称:");
	char b[20];
	char a1[20]="chinese";
	char b1[20]="math";
	char c1[20]="english";
	char d1[20]="chm";
	scanf("%s",b);
	if(strcmp(p->data.subject,b)==0)
	{
		printf("\t\t\t\t\t\t您要录入的学生的id：");
		int id;
		scanf("%d",&id);

		Pstu head2=read_student();
		Pstu temp=head2->next;
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
				double a;
				printf("\t\t\t\t\t\t请输入您要录入的成绩:");
				scanf("%lf",&a);
				if(strcmp(p->data.subject,a1)==0)
				{
					temp->data.chinese=a;
				}
				else
					if(strcmp(p->data.subject,b1)==0)
					{
						temp->data.math=a;
					}
					else
						if(strcmp(p->data.subject,c1)==0)
						{
							temp->data.english=a;
						}
						else
							if(strcmp(p->data.subject,d1)==0)
							{
								temp->data.chm=a;
							}
				write_student(head2);

				printf("\t\t\t\t\t\t录入成功\n");
				printf("\t\t\t\t\t------------------------------------------------\033[0m\n");


			}
	}
	else
		if(strcmp(p->data.subject,b)!=0)
		{
			printf("\t\t\t\t\t\t权限不足\n");
			printf("\t\t\t\t\t------------------------------------------------\033[0m\n");
			return ;
		}
}
void quit_apply(Psth head,Psth p)
{
	int a;
	printf("\n\n\n\n\n\t\t\t\t\t\033[32m------------------------------------------------\n");
	printf("\n\n\t\t\t\t\t\t辞职请输入1:");
	scanf("%d",&a);
	p->data.i=a;
	write_file(head);
	printf("\t\t\t\t\t------------------------------------------------\033[0m\n");
	return ;
}
void look_up_student()
{
	printf("\n\n\n\n\n\n\t\t\t\t\t\033[32m---------------------------------------------------------------------\n");
	printf("\t\t\t\t\t请输入您要查找的学生的id:");
	int id;
	scanf("%d",&id);
	Pstu q=search_student(id);
	if(q==NULL)
	{
		printf("\t\t\t\t\t您输入的id不存在，请重新输入\n");
	}
	else
	{
		printf("\t\t\t\t\traking\tid\tname\tpasswd\tchinese\tmath\tenglish\tchm\tscore\n");
		printf("\t\t\t\t\t%d\t%d\t%s\t%s\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\n",q->raking,q->data.id,q->data.name,q->data.passwd,q->data.chinese,q->data.math,q->data.english,q->data.chm,q->data.score);
		printf("\t\t\t\t\t---------------------------------------------------------------------\033[0m\n");
	}
}
void alter_student(Psth p)
{
	char d[20]="supervisor";
	if(strcmp(p->data.subject,d)==0)
	{

		printf("\n\n\n\n\n\t\t\t\t\t\033[32m------------------------------------------------------\n");
		printf("\t\t\t\t\t\t您要修改的学生的id：");
		int id;
		scanf("%d",&id);

		Pstu head=read_student();
		if(head!=NULL)
		{
			Pstu temp=head->next;
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
					char b1[20];        
					char a1[20];
					int c;
					printf("\t\t\t\t\t\t请输入您要修改的项目名称(name):");
					scanf("%s",a1);
					if(strcmp(a,a1)==0)
					{  
						printf("\t\t\t\t\t\t请输入您要修改的名字:");
						scanf("%s",b1);
						strcpy(temp->data.name,b1);
						printf("\t\t\t\t\t\t修改成功\n");
						printf("\t\t\t\t\t------------------------------------------------------\033[0m\n");
						write_student(head);
						show_student();

					}
					else
						if(strcmp(a,a1)!=0)
						{ 

							printf("\t\t\t\t\t\t您的输入有误，请重新输入\n");
							printf("\t\t\t\t\t------------------------------------------------------\033[0m\n");
							show_student();
							printf("\t\t\t\t\t\t请按任意键继续\n");

						}
				}
		}
	}

	else
	{
		printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\033[32m------------------------------------------------\n\n");
		printf("\t\t\t\t\t\t您的权限不足\n\n");
		printf("\t\t\t\t\t------------------------------------------------\033[0m\n");
	}

	return ;
}

