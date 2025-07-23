#include <iostream>
#include <vector>
using namespace std;

// 滑动窗口
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = __INT32_MAX__; // 结果
        int sum = 0;    // 滑动窗口数值之和
        int i = 0;  // 滑动窗口起始位置
        int subLength = 0;  // 滑动窗口的长度
        for (int j = 0; j < nums.size(); j++){
            sum += nums[j];
            while(sum >= target){
                subLength = j - i + 1;
                result = result < subLength ? result : subLength;
                sum -= nums[i++];
            }
        }
        return result == __INT32_MAX__ ? 0 : result;
    }
};