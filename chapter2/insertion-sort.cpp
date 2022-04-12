#include<iostream>
#include<vector>

using namespace std;

vector<int> insertion_sort(vector<int> num){
    for(int i = 1; i < num.size(); i++){
        int key = num[i];
        int j = i - 1;
        while(j >= 0 && num[j] > key){
            num[j+1] = num[j];
            j--;
        }
        num[j+1] = key;
    }
    return num;
}
int main(){
    vector<int> num = {3,53,6,34,41,324,46};
    for(auto c : insertion_sort(num))
        cout << c << " ";
}