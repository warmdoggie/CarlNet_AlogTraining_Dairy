#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    vector<int> res(nums.size(),0);
    int count = 1;
    for(int i = 0;i<nums.size();i++){
        if(i > 0 && nums[i] == nums[i - 1]){
            count++;
        }
        else if(i > 0 &&nums[i] != nums[i - 1]){
            
        }
    }

}
int main(){
    int n;
    cin >> n;
    int i = 0;
    vector<int> nums;
    while(i<n){
        int x;
        cin >> x;
        nums.push_back(x);
        i++;
    }
    int k;
    cin >> k;
    vector<int> res = topKFrequent(nums,k);


}