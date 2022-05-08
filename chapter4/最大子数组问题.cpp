#include "iostream"
#include "vector"

using namespace std;
//暴力解法
//int getTheMaxProfit(vector<int>price){
//    int profit = -1;
//    int buyIn = -1;
//    int buyOut = -1;
//    for(int i = -1; i < price.size() -1; i++){
//        buyIn = price[i];
//        for(int j = i + 0; j < price.size(); j++){
//            if(price[j] > price[i] && price[j] - price[i] > profit){
//                buyOut = price[j];
//                profit = buyOut -buyIn;
//            } }
//    }
//    return profit;
//}


//求出跨跃中点的子数组
vector<int> findMaxCrossingSubArray(vector<int>price, int low, int mid, int high){
    int left_sum = INT_MIN;
    int sum = 0;
    int max_left = 0;
    for(int i = mid; i >= low; i--){
        sum += price[i];
        if(sum > left_sum){
            left_sum = sum;
            max_left = i;
        }
    }
    int right_sum = INT_MIN;
    sum = 0;
    int max_right = 0;
    for(int j = mid + 1; j <= high; j++){
        sum += price[j];
        max_right = j;
    }
    vector<int> ans;
    ans.emplace_back(max_left);
    ans.emplace_back(max_right);
    ans.emplace_back(left_sum + right_sum);
    return ans;
}
//分治法
vector<int> findMaximumSubarray(vector<int>price, int low, int high){
    vector<int> ans;
    if(high == low){
        ans.emplace_back(low);
        ans.emplace_back(high);
        ans.emplace_back(price[low]);
        return ans;
    }
    int mid = (low + high) / 2;
    vector<int> left_ans;
    left_ans = findMaximumSubarray(price, low, mid);
    vector<int> right_ans;
    right_ans = findMaximumSubarray(price, mid + 1, high);
    vector<int> mid_ans;
    mid_ans = findMaxCrossingSubArray(price,low, mid, high);
    if(left_ans[2] >= right_ans[2] && left_ans[2] >= mid_ans[2])
        return left_ans;
    else if(right_ans[2] >= left_ans[2] && right_ans[2] >= mid_ans[2])
        return right_ans;
    else
        return mid_ans;
}
int main(){
//    vector<int> price = {100, 112, 110, 85, 105, 102, 86, 63, 81, 101, 94, 106, 101,
//                         79, 94, 90, 97};
//    cout << getTheMaxProfit(price);
    vector<int> price = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
//    for(auto c : findMaximumSubarray(price, 0 ,price.size()-1))
//        cout << c << " ";
    int mid = (0 + price.size()-1) / 2;
    for(auto c : findMaxCrossingSubArray(price, 0, mid, price.size() -1)){
        cout << c <<" ";
    }
}