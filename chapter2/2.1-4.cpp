#include <iostream>
#include "vector"

using namespace std;
int linear_search(vector<int> array, int x){
    int res = -1;
    for(int i = 0;i < array.size(); i++)
        if(array[i] == x){
            res = i;
            break;
        }
    return res;
}
int main(){
    vector<int> array{1,3,4,21,32};
    cout << linear_search(array,5);
}
