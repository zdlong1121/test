#include "function.h"

int main(int argc, char **argv)
{
    int on_off = 1;
    int choice;
    directory *head=NULL;
    head=present_list(head);

    FILE *fp = fopen("list.txt","r");
    if(fp == NULL)
    {
        perror("list.txt");
        return -1;
    }
    directory *temp = (directory*)malloc(sizeof(directory));
    temp -> next = NULL;
    while(1)
    {   
        if(0 == fread(temp -> name,sizeof(temp -> name),1,fp))
        {
            if(feof(fp))
            {
                printf("通讯录加载完成!");
                getchar();
                break;
            }
            perror("read");
            return -1;
        }
        if(0 == fread(temp -> sex,sizeof(temp -> sex),1,fp))
        {
            if(feof(fp))
            {
                printf("通讯录加载完成!");
                getchar();
                break;
            }
            perror("read");
            return -1;
        }
        if(0 == fread(&temp -> age,sizeof(temp -> age),1,fp))
        {
            if(feof(fp))
            {
                printf("通讯录加载完成!");
                getchar();
                break;
            }
            perror("read");
            return -1;
        }
        if(0 == fread(&temp -> number,sizeof(temp -> number),1,fp))
        {
            if(feof(fp))
            {
                printf("通讯录加载完成!");
                getchar();
                break;
            }
            perror("read");
            return -1;
        }
        InsertTail(head,temp);
    }
    free(temp);
    temp = NULL;
    fclose(fp);

    while (on_off == 1)
    {          
        system("clear");   
        page();
        scanf("%d", &choice);
        system("clear");
        switch (choice)
        {

        case 1:
            addusr(head);
            getchar();
            break;
        case 2:
            checklist(head);
            getchar();
            break;
        case 3:
            findusr(head);
            getchar();
            break;
        case 4:
            removeusr(head);
            getchar();
            break;
        case 5:
            modifyusr(head);
            getchar();
            break;
        case 6:
            on_off = 0;
            break;
        default:
            printf("没有这个选项，请重新运行打开通讯录\n");
            on_off = 0;
            break;
        }
    }
    
    FILE *fp1 = fopen("list.txt", "w");
    if (fp1 == NULL)
    {
        perror("fopen");
        return -1;
    }
    directory *q = head -> next;
    int i = 1;
    while (q != NULL)
    {
        if(1 != fwrite(q -> name, sizeof(q -> name), 1, fp1))
        {
            perror("fwrite");
            return -1;
        }
        if(1 != fwrite(q -> sex, sizeof(q -> sex), 1, fp1))
        {
            perror("fwrite");
            return -1;
        }
        if(1 != fwrite(&q -> age, sizeof(q -> age), 1, fp1))
        {
            perror("fwrite");
            return -1;
        }
        if(1 != fwrite(&q -> number, sizeof(q -> number), 1, fp1))
        {
            perror("fwrite");
            return -1;
        }
        q = q -> next;
        printf("第%d条通讯信息保存完成!\n",i);
        i++;
    }
    fclose(fp1);
    
    return 0;
}
