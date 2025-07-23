#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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

    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> results;
        if(root == nullptr){
            return results;
        }
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            results.push_back(node->val);
            if(node->left != nullptr){
                st.push(node->left);
            }
            if(node->right != nullptr){
                st.push(node->right);
            }
        }
        reverse(results.begin(), results.end());
        return results;
    }
};