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
private: 
    int arraytoNumber(vector<int>& a){
        int num = 0;
        for(int &it:a){
            num = num*10+it;
        }
        return num;
    }
public:
vector<vector<int>>allPaths;
vector<int>path;
    void rootToleaf(TreeNode*root,vector<int> &path){
        if(root==NULL)return;
        path.push_back(root->val);
        if(root->left==NULL && root->right==NULL)allPaths.push_back(path);
        if(root->left)rootToleaf(root->left,path);
        if(root->right)rootToleaf(root->right,path);
        path.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        rootToleaf(root,path);
        int sum = 0;
        for(auto &path:allPaths){
           sum+=arraytoNumber(path);
        }
        return sum;

    }
};