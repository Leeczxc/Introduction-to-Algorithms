#include "iostream"
#include "myQueue.h"

using namespace std;

int main(){
    myQueue myQue;
    myQue.enQueue(1);
    myQue.enQueue(2);
    cout << myQue.deQueue() << endl;

    cout << myQue.deQueue() << endl;
    if(myQue.empty())
        cout << "True";
    else
        cout << "False";
}