#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int a  = 0;a<nums.size();a++){
            if(nums[0]>target) return result;
            if(a>0 && nums[a] == nums[a-1])a++;
            for(int b = a+1;b<nums.size();b++){
                if( nums[b] == nums[b-1])b++;
                int c = b + 1;
                int d = nums.size() - 1;
                while(b < c && c < d){
                    if(nums[a] + nums[b] + nums[c] + nums[d] > target)d--;
                    else if(nums[a] + nums[b] + nums[c] + nums[d] < target)c++;
                    else{
                        result.push_back(vector<int>{nums[a] ,nums[b] , nums[c] , nums[d]});
                        while(b < c && c < d && nums[c] ==  nums[c + 1])c++;
                        while(b < c && c < d && nums[d] ==  nums[d - 1])d--;
                        c++;
                        d--;
                    }
                }
            }
        }
        return result;
    }
};
int main(){
    Solution L;
    vector<int> num = {0, 0, 0, 0};
    vector<vector<int>> result = L.fourSum(num, 0);
    return 0;
}