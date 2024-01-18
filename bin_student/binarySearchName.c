#include "binarySearchName.h"

data_t* binnarySearchName(root_t lst, char* key){
    node_t* p = NULL;
    int count = 0;
    for (p = lst; p != NULL; p = p->next){
        count++;
    }

    int low = 0;
    int high = count - 1;
    int mid = (low + high) / 2;

    // for (; low <= high; mid = (low + high) / 2) {
    //     p = p->next;
    // }
    
    return NULL;
}