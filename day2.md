## 209.长度最小的子数组
### 暴力解
```
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min = INT32_MAX;
        int flag = 0;
        for(int i = 0;i<nums.size();i++){
            int sum = 0;
            for(int j = i;j < nums.size();j++){
                sum += nums[j];
                if(sum >= target){
                    flag = 1;
                    int len = j - i + 1;
                    min = len < min?len:min;
                    break;
                }
            }
        }
        return flag==1?min : 0;
    }
};
```
### 滑动窗口法
理解还是有点困难，明日需回顾
注意理解代码时间复杂为O(n)
```
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min = INT32_MAX;    //int最大值
        int flag = 0,len;
        int i = 0;
        int sum = 0;
        for(int j = 0;j<nums.size();j++){
            sum += nums[j];
            while(sum >= target){  // 注意while
                flag=1;
                len = j - i + 1;
                min = len < min?len : min;
                sum -= nums[i++]; //精髓
            }
        }
        return flag==1?min : 0;
    }
};
```

