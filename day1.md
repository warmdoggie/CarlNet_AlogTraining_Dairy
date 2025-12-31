## 二分查找
```
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int maxsize = nums.size();
        int mid, low = 0, high = maxsize - 1;
        // 左闭右闭
        while(low <= high){
            mid = (low + high) / 2;
            if(nums[mid] > target){
                high = mid - 1;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else 
                return mid;
        }
        return -1;
    }
};
```


```
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int maxsize = nums.size();
        int mid, low = 0, high = maxsize - 1;
        // 左闭右开
        while(low < high){
            mid = (low + high) / 2;
            if(nums[mid] > target){
                high = mid;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else 
                return mid;
        }
        return -1;
    }
};

```
## 移除元素


### 暴力解
用k标记当前数组长度，随着删除而减少

``` 
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = nums.size();

        for(int i = 0;i < k; i++){
            if(nums[i] == val){
                for(int j = i + 1;j < k; j++)
                    nums[j - 1] = nums[j];
                i--;
                k--;
            }
        }
        return k;
    }
};
```
### 双指针
注意快慢指针的含义
目标代表需要移除的元素
快指针：指向需要放入的元素 不包含目标
快指针指向的元素放入慢指针指向的下标中
```
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for(int fast = 0; fast < nums.size();fast++){
            if(val != nums[fast]){  //不等于的时候才需要存放
                nums[slow++] = nums[fast];  
            }
            //等于的时候slow不动，未来将此下标覆盖，fast继续寻找
        }
        return slow;    //注意slow恰好代表数组长度
    }
};
```
### 有序数组的平方
C++中定义动态数组 **vector<int> result(nums.size(), 0);**
```
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int max = nums.size();
        int k = max - 1;
        vector<int> result(nums.size(), 0);
        for(int i = 0,j = max - 1;i <= j;){ //i 和 j 的变换 在代码中
        // i 和 j 共同向中间收敛，两边绝对值更大，从两边开始，起到排序的作用，谁大谁先放，下标向内收敛
            if(nums[i]*nums[i] > nums[j] * nums[j]){
                result[k--] = nums[i] * nums[i];
                i++;//前进
            }
            else{
                result[k--] = nums[j] * nums[j];
                j--;//后退
            }  
        }
        return result;
    }
};
```
