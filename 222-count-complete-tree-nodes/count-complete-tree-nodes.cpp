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
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        queue<TreeNode*>q;
        q.push(root);
        int c = 0;
        while(!q.empty()){
            vector<int> level;
            int size = q.size();
            for(int i = 0 ; i <size ; i++){
                TreeNode*node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->right)q.push(node->right);
                if(node->left)q.push(node->left);
            }
            c+=level.size();
        }
        return c;
    }
};