#include "iostream"
#include "vector"

using namespace std;

vector<int> insertion_sort(vector<int> array){
    size_t size = array.size();
    for(int i = 1; i < size; i++){
        int key = array[i];
        int j = i - 1;
        while(j >= 0 && key >= array[j]){
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
    return array;
};
int main(){
    vector<int> array={1,2,3,4,5,6};
    for(auto c : insertion_sort(array))
        cout << c << " ";
}
