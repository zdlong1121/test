#ifndef _FUNCTION_
#define _FUNCTION_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 99

//每个通讯成员的信息
struct directory
{
    char name[32]; //称呼
    char sex[10];  //性别
    int age;       //年龄
    long number;   //电话号

    struct directory *next; // next
};
typedef struct directory directory;

int my_strcmp(char *p1, char *p2);//比较字符串是否相同
char *my_strcpy(char *dest,char *src);//复制
int my_strlen(const char *s);//字符串长度
void page();//首页面
directory* present_list();//初始化
void sorting(directory *head);//按首字母排序
void addusr(directory *head);//添加用户信息

void checklist(directory *head);//查看所有信息
void findusr(directory *head);//搜索某个信息
void removeusr(directory *head);//删除信息
void modifyusr(directory *head);//修改信息
//尾插
void InsertTail(directory *head,directory * temp);
#endif
