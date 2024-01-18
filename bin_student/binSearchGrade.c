#include "binSearchGrade.h"

data_t* binnarySearchGrade(root_t lst, const int key){
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

    // for (; low <= high; mid = (low + high) / 2) {
    //     if (p->data.grade == key)
    //     return &(p->data);
    //     else if (p->data.grade < key)  
    //     low = mid + 1;
    //     else  
    //     high = mid - 1;
    //     p = p->next;
    // }
    return NULL;
}