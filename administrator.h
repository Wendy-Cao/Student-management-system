#ifndef ADM_LOGIN_H
#define ADM_LOGIN_H
struct DATA
{
	int id;
	int i;
	char name[20];
    char passwd[20];
    char subject[20];
};
typedef struct teacher
{   
	struct DATA data;
	struct teacher * next;
}STH,*Psth;
void adm_login();
void delay();
void adm_func(char *name);
void add_teacher();
void delete_teacher();
Psth search_teacher(int id);
void write_file(Psth head);
Psth read_file();
void show();
void alter_teacher();
void sort_teacher();
void look_up();
char * yzm();
#endif
