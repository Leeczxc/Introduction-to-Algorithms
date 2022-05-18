//
// Created by Leecz on 2022/5/18.
//

#ifndef C_PROJECT_MYLIST_H
#define C_PROJECT_MYLIST_H


class myList {
public:
    myList* prev;
    myList* next = nullptr;
    int key;
    myList(int k){
        key = k;
    }
};

myList* listSearch(myList* list, int k);

void listInsert(myList* list, int k);

void listDelete(myList* list, int k);

#endif //C_PROJECT_MYLIST_H
