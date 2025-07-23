#include <iostream>
#include <vector>
using namespace std;

// dp[i]就是爬到第i层楼，有多少种方法
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1){
            return n;
        }
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};