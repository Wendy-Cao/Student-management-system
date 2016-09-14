#ifndef TEACHER_LOGIN_H
#define TEACHER_LOGIN_H
#include"administrator.h"
struct DATA1
{
int id;
char name[20];
char passwd[20];
double chinese;
double math;
double english;
double chm;
double score;
};
typedef struct student 
{
int raking;
struct DATA1 data;
struct student * next;
}STU,* Pstu;

void teacher_login();
void delay1();
void teacher_func(Psth head,Psth p);
void add_student(Psth p);
Pstu read_student();
void write_student(Pstu head);
void show_student();
Pstu search_student(int id);
void sort_student();
void delete_student(Psth p);
void add_score(Psth p);
void quit_apply(Psth head,Psth p);
void look_up_student();
void alter_student(Psth p);
#endif
