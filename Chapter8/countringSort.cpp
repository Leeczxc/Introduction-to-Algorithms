#include "iostream"
#include "vector"

using namespace std;

vector<int> countingSort(vector<int> array, int k){
    vector<int> temp(k + 1,0);
    for(int i =0; i < array.size(); i++)
        temp[array[i]]++;
    for(int i = 1; i <= k; i++)
        temp[i] += temp[i-1];
    int size = array.size();
    vector<int> ans(size,0);
    size--;
    while(size >= 0){
        ans[temp[array[size]] - 1] = array[size];
        temp[array[size]]--;
        size--;
    }
    return ans;
}

int main(){
    vector<int> array = {2, 5, 3, 0, 2, 3, 0, 3};
    for(auto c: countingSort(array,5))
        cout << c <<" ";
}