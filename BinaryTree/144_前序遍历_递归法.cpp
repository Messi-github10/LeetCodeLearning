#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:

    void tarversal(TreeNode* cur, vector<int> &vec){
        if(cur == nullptr){
            return;
        }
        vec.push_back(cur->val);
        tarversal(cur->left, vec);
        tarversal(cur->right, vec);
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> results;
        tarversal(root, results);
        return results;
    }
};