//
// Created by Leecz on 2022/5/18.
//

#include "myList.h"

myList* listSearch(myList* list, int k) {
    if(list == nullptr)
        return nullptr;
    if(list->key == k)
        return list;
    list = list->next;
    while(list != nullptr){
        if(list->key == k)
            return list;
    }
        return nullptr;
}

void listInsert(myList *list, int k) {
    myList* needInsert = new myList(k);
    needInsert->next = list->next;
    needInsert->next->prev = needInsert;
    list->next = needInsert;
}

//忽略边界条件
void listDelete(myList *list, int k) {
   myList* needDelete = listSearch(list, k);
   needDelete->prev->next = needDelete->next;
   needDelete->next->prev = needDelete->prev;
   needDelete = nullptr;
}




