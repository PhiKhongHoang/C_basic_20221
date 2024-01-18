#ifndef __LL_H__
#define __LL_H__

typedef struct
{
    char user[30];
    char pass[30];
    int status;
} Data;

typedef struct node
{
    Data data;
    struct node *next;
} Node;

void insertFirst(Data data);
void deleteFirst();
void delLList();
void print();
int search(char user[]);
int checkUser(char user[]);
void funRegister(char user[], char pass[]);
void funSignIn(char user[], char pass[]);
void funSearch(char user[]);
void funSignOut(char user[]);
void writeFile();

#endif