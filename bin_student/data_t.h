#ifndef __DATA_T_H__
#define __DATA_T_H__
typedef struct data_s{
  char id[20];
  char name[32];
  int grade;
} data_t;

void showData(const data_t data);
#endif