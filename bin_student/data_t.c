#include "data_t.h"
#include <stdio.h>

void showData(data_t data) { 
  printf("%s - %s - %d\n", data.id, data.name, data.grade);
}