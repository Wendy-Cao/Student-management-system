
#include"administrator.h"
#include"teacher.h"
#include"student.h"
#include"denglu.h"
void denglu(int key)
{
	while(1)
	{
		system("clear");
		printf("\n\n\n\n\n\n\n\n\n");
		system("tput setb 7");
		system("tput setf 4");
		printf("\t\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
		printf("\t\t\t\t\t\t@                                    @\n");
		system("tput setf 1");		
		printf("\t\t\t\t\t\t@    1管理员登陆                     @\n");
		system("tput setf 2");
		printf("\t\t\t\t\t\t@                                    @\n");
		printf("\t\t\t\t\t\t@    2教师登陆                       @\n");
		system("tput setf 3");
		printf("\t\t\t\t\t\t@                                    @\n");
		printf("\t\t\t\t\t\t@    3学生登陆                       @\n");
		system("tput setf 6");
		printf("\t\t\t\t\t\t@                                    @\n");
		printf("\t\t\t\t\t\t@    4退出                           @\n");
		system("tput setf 4");
		printf("\t\t\t\t\t\t@                                    @\n");
		printf("\t\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\033[0m\n");
		system("tput setf 6");
		printf("\t\t\t\t\t\t请输入您的选择:\033[0m");
		int key;
		scanf("%d",&key);
		printf("\n");
		switch(key)
		{
			case 1:
				system("clear");
				adm_login();
				break;
			case 2:
				teacher_login();
				break;
			case 3:
				student_login();
				break;
			case 4:
				exit (0);
			default :
				printf("\t\t\t\t\t\t\033[32m输入有误，请重新输入\033[0m\n");
				break;
		}
	}
}
