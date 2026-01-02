## 209.长度最小的子数组
最短长度： 滑动窗口 （负数不能用）
有多少个： 前缀和

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
## 59.螺旋矩阵II
一定要注意边界条件
辅助变量startx，starty变化
循环次数 loop = n/2
当n为奇数时的处理 if
```
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));// 定义二维数组
        int loop = n / 2;
        int offset = 1,count = 1;       // 初始为1
        int startx = 0,starty = 0;
        int i,j;
        while(loop--) {
            // 每次循环就是一圈，更新转圈的起点
            i = startx;
            j = starty;
            // 开始转圈
            // 每次都是左闭右开
            for(;j < n - offset;j++)    // 注意减去偏移量，，每圈递增偏移量->螺旋->减小遍历的半径
                res[i][j] = count++;    // [ ] [ ] [ ] ....遍历行
            for(;i < n - offset;i++)    
                res[i][j] = count++;    // j不变 第一行开始竖着遍历最后1列 赋值
            for(;j > starty;j--)
                res[i][j] = count++;    // i不变  最后一列开始 倒着向前遍历最后1行
            for(;i > startx;i--)
                res[i][j] = count++;    // j不变 最后一行开始 倒着向上遍历第一列

            // 更新转圈起点 缩小圈的大小
            startx++;
            starty++;
            offset++;   // 偏移量每次要增加
        }  
        if(n % 2 == 1) {
            res[n/2][n/2] = count;  //奇数，中间元素单独赋值
        }    
        return  res;
    }
};
```