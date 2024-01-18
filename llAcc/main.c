#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"

void readFile()
{
    FILE *fin;
    if ((fin = fopen("account.txt", "r")) == NULL)
    {
        printf("\nCannot read file acconut.txt\n");
        exit(0);
    }
    else
    {
        Data data;
        while (fscanf(fin, "%s %s %d\n", data.user, data.pass, &data.status) == 3)
        {
            insertFirst(data);
        }
    }
    fclose(fin);
}

void menu()
{
    char user[30], pass[30];
    int luaChon;
    printf("\nUSER MANAGEMENT PROGRAM\n");
    printf("-----------------------------------\n");
    printf("1. Register\n");
    printf("2. Sign in\n");
    printf("3. Search\n");
    printf("4. Sign out\n");
    printf("Your choice (1-4, other to quit): ");
    scanf("%d", &luaChon);
    while (luaChon >= 1 && luaChon <= 4)
    {
        switch (luaChon)
        {
        case 1:
            delLList();
            print();
            readFile();
            printf("\nUser: ");
            scanf("%s", user);
            fflush(stdin);
            if (checkUser(user) == 1)
            {
                printf("\nAccount existed\n");
            }
            else
            {
                printf("\nPass: ");
                scanf("%s", pass);
                fflush(stdin);
                funRegister(user, pass);
                writeFile();
            }
            break;

        case 2:
            delLList();
            readFile();
            printf("\nUser: ");
            scanf("%s", user);
            fflush(stdin);
            if (checkUser(user) == 0)
            { // user chua ton tai
                printf("\nCannot find account\n");
            }
            else
            {
                funSignIn(user, pass);
                writeFile();
            }
            break;

        case 3:
            // delLList();
            // readFile();
            printf("\nUser: ");
            scanf("%s", user);
            fflush(stdin);
            funSearch(user);
            break;

        case 4:
            // delLList();
            // readFile();
            printf("\nUser: ");
            scanf("%s", user);
            fflush(stdin);
            funSignOut(user);
            break;

        default:
            break;
        }
        printf("Your choice (1-4, other to quit): ");
        scanf("%d", &luaChon);
    }
}

int main()
{
    menu();
    return 0;
}