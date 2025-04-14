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
    void solve(TreeNode*root,int row,int col,map<pair<int,int>,vector<int>>&mpp){
        if(!root)return;
        mpp[{col,row}].push_back(root->val);
        if(root->left)solve(root->left,row+1,col-1,mpp);
        if(root->right)solve(root->right,row+1,col+1,mpp);
        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        vector<vector<int>>ans;
        map<pair<int,int>,vector<int>>mpp;
        if(!root)return ans;
        map<int,vector<int>>sortedMap;
        solve(root,0,0,mpp);
        for(auto &it:mpp){
            int col=it.first.first;
            int row=it.first.second;
            vector<int> &temp =it.second;
            sort(temp.begin(),temp.end());
            for(int i = 0 ; i< temp.size();i++){
                sortedMap[col].push_back(temp[i]);
            }
        }

        for(auto &x:sortedMap){
            ans.push_back(x.second);
        }
        return ans;
        
    }
};