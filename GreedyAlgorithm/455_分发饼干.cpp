#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());   // 胃口数组
        sort(s.begin(), s.end());   // 饼干数组
        int index = s.size() - 1;   // 饼干数组的下标
        int result = 0;
        for (int i = g.size() - 1; i >= 0; i--){
            if(s[index] >= g[i] && index >=0){
                result++;
                index--;
            }
        }
        return result;
    }
};