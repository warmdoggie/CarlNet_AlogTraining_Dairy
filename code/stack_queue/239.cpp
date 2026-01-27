#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int max(vector<int> &nums,int low,int high){
    int max = nums[low];
    for(int i = low;i<=high;i++){
        if(nums[i] > max)
            max = nums[i];
    }
    return max;
}
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    int start = 0;
    while(start <= nums.size() - k){
        int low = start;
        int high = start + k - 1;
        int a = max(nums,low,high);
        res.push_back(a);
        start++;
    }
    return res;
}
int main(){
    int n;
    cin >> n;
    vector<int> nums;
    int i = 0;
    while(i<n){
        int num;
        cin >> num;
        nums.push_back(num);
        i++;
    }
    int k;
    cin >> k;
    vector<int> res = maxSlidingWindow(nums,k);
    for(int x : res){
        cout << x << ' ';
    }
}

