/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode*node,int targetSum, int currSum, vector<int> &path,vector<vector<int>> &ans){
        if(!node)return;
        currSum+=node->val;
        path.push_back(node->val);
        if(!node->left && !node->right && currSum==targetSum){
            ans.push_back(path);
        }
        dfs(node->left,targetSum,currSum,path,ans);
        dfs(node->right,targetSum,currSum,path,ans);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(root,targetSum,0,path,ans);
        return ans;
    }
};