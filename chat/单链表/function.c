#include "function.h"

//比较两个字符串是否相同
int my_strcmp(char *p1, char *p2)
{
    int i;
    while (*p1 != '\0')
    {
        while (*p1 == *p2)
        {
            p1++;
            p2++;
            if (*p1 == '\0' || *p2 == '\0')
                break;
        }
        if (*p2 == '\0' && *p1 != '\0')
        {
            i = 1;
            break;
        }
        else if (*p2 == '\0' && *p1 == '\0')
        {
            i = 0;
            break;
        }
        else if (*p2 != '\0' && *p1 == '\0')
        {
            return -1;
            break;
        }
        else if (*p1 != '\0' && *p1 != '\0')
        {
            i = -2;
            break;
        }
    }
    return i;
}

//复制值
char *my_strcpy(char *dest, char *src)
{
    char *p, *q;
    p = dest;
    q = src;
    while (*q != '\0')
    {
        *p = *q;
        p++;
        q++;
    }
    *p = *q;
    return dest;
}

//长度
int my_strlen(const char *s)
{
    int len = 0;
    while (*s != '\0')
    {
        s++;
        len++;
    }
    return len;
}

//页面
void page()
{
    printf("\n                     通讯录                           \n");
    printf("*****************************************************\n");
    printf("----------------- 1.添加用户 ------------------------\n");
    printf("----------------- 2.查看用户 ------------------------\n");
    printf("----------------- 3.搜索用户 ------------------------\n");
    printf("----------------- 4.删除用户 ------------------------\n");
    printf("----------------- 5.修改用户 ------------------------\n");
    printf("----------------- 6.退    出 ------------------------\n");
    printf("*****************************************************\n");
    printf("\n");
    printf("请输入想要操作的序号:");
}

directory *present_list()
{
    directory *head = NULL;
    head = (directory *)malloc(sizeof(directory) * MAX); //每个存放通讯信息的指针都开辟一个空间
    head->next = NULL;
    return head;
}

//对通讯录信息按照姓名字母排序
void sorting(directory *head)
{
    int i = 0, j = 0, n = 0;
    directory *p = head;
    while (p->next != NULL)
    {
        p = p->next;
        n++;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            p = head;
            while (p->next->next != NULL)
            {
                p = p->next;
                if (p->name[0] >= p->next->name[0])
                {
                    directory *tmp = (directory *)malloc(sizeof(directory));
                    tmp->next = NULL;
                    my_strcpy(tmp->name, p->name);
                    my_strcpy(tmp->sex, p->sex);
                    tmp->age = p->age;
                    tmp->number = p->number;
                    my_strcpy(p->name, p->next->name);
                    my_strcpy(p->sex, p->next->sex);
                    p->age = p->next->age;
                    p->number = p->next->number;
                    my_strcpy(p->next->name, tmp->name);
                    my_strcpy(p->next->sex, tmp->sex);
                    p->next->age = tmp->age;
                    p->next->number = tmp->number;
                    free(tmp);
                    tmp = NULL;
                }
            }
            /*
             if(p -> name[0] >= p -> next -> name[0])
             {
                 directory *tmp = (directory *)malloc(sizeof(directory));
                 tmp  = p -> next;
                 p -> next = tmp -> next;
                 tmp -> next = q -> next;
             }
             */
        }
    }
}

//添加用户
void addusr(directory *head)
{
    int i = 1;
    int n = 0;
    char choice;
    directory *p = head;
    directory *(tmp) = (directory *)malloc(sizeof(directory));
    tmp->next = NULL;
    directory *q = tmp;
    printf("是否添加新用户信息(y/n):");
    while (1 == i)
    {
        scanf(" %c", &choice);
        switch (choice)
        {
        case 'y':
        case 'Y':
            printf("请录入通讯对象信息\n");
            printf("请输入称呼:");
            scanf("%s", q->name);
            printf("请输入性别:");
            scanf("%s", q->sex);
            printf("请输入年龄:");
            scanf("%d", &q->age);
            printf("请输入电话号码:");
            scanf("%ld", &q->number);
            while (p->next != NULL)
            {
                p = p->next;
            }
            q->next = p->next;
            p->next = q;

            if ((q->number) / 10000000000 == 1)
            {
                printf("通讯信息录入成功!");
            }
            else if ((q->number) / 10000000000 != 1)
            {
                p->next = NULL;
                free(q);
                q->next = NULL;
                printf("信息录入失败！");
                printf("请按回车键返回通讯录页面!\n");
                i = 0;
                getchar();
                break;
            }
            q = q->next;
            q = (directory *)malloc(sizeof(directory));
            printf("请选择是否继续输入(y/n):");
            break;
        case 'n':
        case 'N':
            printf("请按回车返回通讯录主页面!\n");
            i = 0;
            getchar();
            break;
        default:
            printf("输入错误!\n");
            printf("请按回车键返回通讯录主页面\n");

            i = 0;
            getchar();
            break;
        }
    }
}

//查看用户
void checklist(directory *head)
{
    int i = 0;
    directory *p = head;
    sorting(head);
    printf("                 通讯录信息                     \n");
    printf("序号.----称呼----性别----年龄-------电话号----------\n");
    while (p->next != NULL)
    {
        if(i == 0)
        {
            printf(" ");
        }
        p = p->next;
        printf("%-7d %-7s %-8s %-9d %-18ld\n ", i + 1, p->name, p->sex, p->age, p->number);
        i++;
    }
    printf("\n-------------------------------------------------\n");
    getchar();
}

//查找用户
void findusr(directory *head)
{
    int choice, id;
    int i = 0;
    int j = 0;
    char find[32];
    directory *p = head;
    sorting(head);
    printf("请选择使用(1.称呼查询)还是(2.序号查询):");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("请输入想要查找的用户备注称呼:");
        scanf("%s", find);
        printf("              想要查找的通讯录信息                  \n");
        printf("序号.----称呼----性别----年龄-------电话号----------\n");
        while (p->next != NULL)
        {
            p = p->next;
            if(i == 0)
            {
                printf(" ");
            }
            i++;
            if (my_strcmp(p->name, find) == 0)
            {
                printf("%-7d %-7s %-8s %-9d %-18ld\n ", i, p->name, p->sex, p->age, p->number);
                j++;
            }
            
        }
        getchar();
        break;
    case 2:
        printf("请输入想要查找的用户序号\n");
        scanf("%d", &id);
        printf("              想要查找的通讯录信息                  \n");
        printf("序号.----称呼----性别----年龄-------电话号----------\n");
        while (p->next != NULL)
        {
            if(i == 0)
            {
                printf(" ");
            }
            p = p->next;
            i++;
            if (i == id)
            {
                printf("%-7d %-7s %-8s %-9d %-18ld\n ", i, p->name, p->sex, p->age, p->number);
                j++;
            }
        }
        getchar();
        break;
    default:
        j = 0;
        break;
    }
    if (j == 0)
    {
        printf("查无此人!\n");
        printf("请按回车建返回通讯录主菜单!\n");
        getchar();
    }
}

//删除用户信息
void removeusr(directory *head)
{
    int n = 1;
    int id;
    int i = 0;
    char choice;
    directory *p = head;
    checklist(head);
    printf("请选择是否要删除信息(y/n):");
    while (1 == n)
    {
        scanf(" %c", &choice); //加空格防止垃圾字符
        switch (choice)
        {
        case 'y':
        case 'Y':
            i = 0;
            p = head;
            printf("请输入想要删除的用户信息的id:");
            scanf("%d", &id);
            while (p->next != NULL)
            {
                i++;
                if (i == id)
                {
                    directory *tmp = p->next;
                    p->next = p->next->next;
                    free(tmp);
                    tmp = NULL;
                }
                p = p->next;
            }
            if (i < id)
            {
                printf("该序号无人!\n");
                break;
            }
            printf("删除后通讯录信息为\n");
            checklist(head);
            printf("请选择是否继续删除(y/n):");
            break;
        case 'n':
        case 'N':
            n = 0;
            printf("请按回车键返回通讯录主页面\n");
            getchar();
            break;
        default:
            n = 0;
            printf("输入错误!\n");
            printf("请按回车键返回通讯录主页面!\n");
            getchar();
            break;
        }
    }
}

//修改用户信息
void modifyusr(directory *head)
{
    int id;
    int i = 0;
    int n = 1;
    char choice;
    directory *p = head;

    checklist(head);
    printf("请选择是否修改信息(y/n):");
    while (1 == n)
    {
        scanf(" %c", &choice);
        switch (choice)
        {
        case 'y':
        case 'Y':
            printf("请选择想要修改的用户信息的id:");
            scanf("%d", &id);
            while (p->next != NULL)
            {
                p = p->next;
                i++;
                if (i == id)
                {
                    directory *tmp = (directory *)malloc(sizeof(directory) * MAX);
                    tmp->next = NULL;
                    printf("请录入修改后通讯对象信息\n");
                    printf("请输入修改后姓名:");
                    scanf("%s", tmp->name);
                    // getchar();
                    printf("请输入修改后性别:");
                    scanf("%s", tmp->sex);
                    // getchar();
                    printf("请输入修改后年龄:");
                    scanf("%d", &tmp->age);
                    printf("请输入修改后电话号码:");
                    scanf("%ld", &tmp->number);
                    my_strcpy(p->name, tmp->name);
                    my_strcpy(p->sex, tmp->sex);
                    p->age = tmp->age;
                    p->number = tmp->number;
                    free(tmp);
                    tmp = NULL;
                }
            }
            printf("请选择是否需要继续删除操作(y/n):");
            break;
        case 'n':
        case 'N':
            n = 0;
            printf("请按回车键返回通讯录主页面\n");
            getchar();
            break;
        default:
            printf("输入错误！\n");
            n = 0;
            printf("请按回车键返回通讯录主页面\n");
            getchar();
            break;
        }
    }
}

//尾插
void InsertTail(directory *head,directory * temp)
{
    directory *list = (directory *)malloc(sizeof(directory));
    list -> next = NULL; 
    my_strcpy(list -> name,temp -> name);
    my_strcpy(list -> sex,temp -> sex);
    list -> age = temp -> age;
    list -> number = temp -> number;
    directory *p = head;
    while( p -> next != NULL )
    {
        p = p->next;
    }
    list -> next = p -> next;
    p -> next = list;
    return;
}

