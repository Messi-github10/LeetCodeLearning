#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1){
            return nums.size();
        }
        int prediff = 0;
        int curdiff = 0;
        int result = 1; // 摆动序列长度
        for (int i = 0; i < nums.size() - 1; i++){
            curdiff = nums[i + 1] - nums[i];
            if((prediff <= 0 && curdiff > 0) || (prediff >= 0 && curdiff < 0)){
                result++;
                prediff = curdiff;  // （相对于prediff）坡度摆动发生变化的时候，才需要更新prediff
            }
        }
        return result;
    }
};