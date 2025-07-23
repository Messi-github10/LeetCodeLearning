#include <iostream>
#include <vector>
using namespace std;


// 双指针法
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int k = nums.size() - 1;
        vector<int> results(nums.size(), 0);
        for (int i = 0, j = nums.size() - 1; i <= j;){
            if(nums[i] * nums[i] < nums[j] * nums[j]){
                results[k--] = nums[j] * nums[j];
                j--;
            }else{
                results[k--] = nums[i] * nums[i];
                i++;
            }
        }
        return results;
    }
};