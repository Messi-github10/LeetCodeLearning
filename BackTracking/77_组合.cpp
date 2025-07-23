#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return results;
    }

private:
    void backtracking(int n, int k, int startIndex){
        // 终止条件
        if(path.size() == k){
            results.push_back(path);
            return;
        }

        // 回溯逻辑
        for (int i = startIndex; i <= n; i++){
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }

    vector<int> path;
    vector<vector<int>> results;
};