#include "list.h"
#include "binSearchGrade.h"
#include "binarySearchName.h"
#include <stdio.h>

int main() {
  printf("========== Chuong trinh 1 ==========\n\n");
  data_t aSV1[] = {{"001", "sv1", 20},
                  {"002", "sv2", 15},
                  {"003", "sv3", 10},
                  {"004", "sv4", 5},
                  {"005", "sv5", 0}};

  root_t lst = llInit();

  for (int i = sizeof(aSV1) / sizeof(aSV1[0]) - 1; i >= 0 ; i--)
    lst = llInsertHead(lst, aSV1[i]);

  printf("\n\nPrint all\n");
  llPrint(lst);

  data_t* pStudent = binnarySearchGrade(lst, 10);
  if(pStudent == NULL) printf("Khong tim thay\n");
  else 
    showData(*pStudent);

  lst = llDeleteAll(lst);

  printf("\n\n========== Chuong trinh 2 ==========\n\n");
  data_t aSV2[] = {{"001", "sv1", 2},
                  {"002", "sv2", 4},
                  {"003", "sv3", 6},
                  {"004", "sv4", 8},
                  {"005", "sv5", 10}};

  root_t lst1 = llInit();

  for (int i = sizeof(aSV2) / sizeof(aSV2[0]) - 1; i >= 0 ; i--)
    lst1 = llInsertHead(lst1, aSV2[i]);

  printf("\n\nPrint all\n");
  llPrint(lst1);

  data_t* pStudent1 = binnarySearchName(lst1, "sv3");
  if(pStudent1 == NULL) printf("Khong tim thay\n");
  else 
    showData(*pStudent1);

  lst = llDeleteAll(lst1);

  return 0;
}