#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"

Node *head = NULL;
int checkStatus = 0;

void insertFirst(Data data)
{
    // tao 1 node p
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = data;

    // tro p toi head cu
    p->next = head;

    // tro head toi head moi
    head = p;
}

// xoa phan tu dau tien
void deleteFirst()
{

    // luu tham chieu toi p
    Node *p = head;

    // danh dau next toi p la first
    head = head->next;
}

void delLList()
{
    for (Node *p = head; p != NULL; p = p->next)
    {
        deleteFirst();
    }
}

void print()
{
    for (Node *p = head; p != NULL; p = p->next)
    {
        printf("\n%s - %s - %d\n", p->data.user, p->data.pass, p->data.status);
    }
}

int search(char user[])
{
    // ban dau tim tu node dau tien
    Node *p = head;

    // neu llist rong
    if (head == NULL)
        return 0;

    // duyet qua llist
    while (strcmp(p->data.user, user) != 0)
    {
        // neu day la node cuoi
        if (p->next == NULL)
            return 0;
        else // di chuyen toi node ke tiep
            p = p->next;
    }

    // neu tim thay tra ve node hien tai
    return 1;
}

int checkUser(char user[])
{
    // check xem user da ton tai chua
    // duyet qua tat ca cac node
    for (Node *p = head; p != NULL; p = p->next)
    {
        if (search(user) == 0)
        { // user chua ton tai
            return 0;
        }
    }
    return 1; // user da ton tai
}

void writeFile()
{
    FILE *fin;
    if ((fin = fopen("account.txt", "w")) == NULL)
    {
        printf("\nCannot write file acconut.txt\n");
        exit(0);
    }
    else
    {
        for (Node *p = head; p != NULL; p = p->next)
        {
            fprintf(fin, "%s %s %d\n", p->data.user, p->data.pass, p->data.status);
        }
    }
    fclose(fin);
}

void funRegister(char user[], char pass[])
{
    Data data;
    strcpy(data.user, user);
    strcpy(data.pass, pass);
    data.status = 1;
    insertFirst(data);
    printf("\nSuccessful registration\n");
}

void funSignIn(char user[], char pass[])
{
    int dem = 0;
    for (Node *p = head; p != NULL; p = p->next)
    {
        if (strcmp(p->data.user, user) == 0)
        {
            if (p->data.status == 0)
            {
                printf("\nAccount is blocked\n");
                break;
            }
            else
            {
                printf("\nPass: ");
                scanf("%s", pass);
                fflush(stdin);
                if (strcmp(p->data.pass, pass) == 0)
                {
                    printf("\nHello %s\n", user);
                    checkStatus = 1;
                    break;
                }
                else
                {
                    dem++;
                    printf("\nPassword is incorrect\n");
                    while (dem < 3)
                    {
                        printf("\nPass: ");
                        scanf("%s", pass);
                        fflush(stdin);
                        if (strcmp(p->data.pass, pass) == 0)
                        {
                            printf("\nHello %s\n", user);
                            checkStatus = 1;
                            break;
                        }
                        else
                        {
                            dem++;
                            printf("\nPassword is incorrect\n");
                        }
                    }

                    if (dem == 3)
                    {
                        printf("\nPassword is incorrect. Account is blocked\n");
                        p->data.status = 0;
                        checkStatus = 0;
                        break;
                    }
                }
            }
        }
    }
}

void funSearch(char user[])
{
    if (checkStatus == 0)
    {
        printf("\nAccount is not sign in\n");
    }
    else
    {
        if (checkUser(user) == 0)
        { // user chua ton tai
            printf("\nCannot find account\n");
        }
        else
        {
            for (Node *p = head; p != NULL; p = p->next)
            {
                if (strcmp(p->data.user, user) == 0)
                {
                    if (p->data.status == 1)
                    {
                        printf("\nAccount is active\n");
                        break;
                    }
                    else
                    {
                        printf("\nAccount is blocked\n");
                        break;
                    }
                }
            }
        }
    }
}

void funSignOut(char user[])
{
    if (checkStatus == 0)
    {
        printf("\nAccount is not sign in\n");
    }
    else
    {
        if (checkUser(user) == 0)
        { // user chua ton tai
            printf("\nCannot find account\n");
        }
        else
        {
            for (Node *p = head; p != NULL; p = p->next)
            {
                if (strcmp(p->data.user, user) == 0)
                {
                    printf("\nGoodbye %s\n", user);
                    checkStatus = 0;
                    break;
                }
            }
        }
    }
}
