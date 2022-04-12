#include "iostream"
#include "vector"

using namespace std;
vector<int> addBinaryIntegers(vector<int> array1, vector<int> array2){
    size_t size = array1.size();
    vector<int> res(size + 1, 0);
    int temp = 0;
    for(int i = size - 1; i>= 0; i--){
        res[i + 1] = (temp + array1[i] + array2[i]) % 2;
        temp = (temp + array1[i] + array2[i]) / 2;
    }
    res[0] = temp;
    return res;
}
int main(){
    vector<int> array1 = {1,1,1,0,1};
    vector<int> array2 = {1,0,0,1,1};
    for(auto c : addBinaryIntegers(array1,array2))
        cout << c << " ";
}
