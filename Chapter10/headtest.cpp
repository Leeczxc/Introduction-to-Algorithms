#include "iostream"
#include "vector"
#include "myHeap.h"

using namespace std;

int main(){
    myHeap heap;
    if(heap.stackEmpty())
        cout << "True" << endl;
    heap.push(1);
    heap.push(2);
    cout << heap.pop() << endl;
    cout << heap.pop() << endl;
    if(heap.stackEmpty())
        cout << "True" << endl;
};