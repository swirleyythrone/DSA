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
 int diameter=0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
       
        dfs(root);
        return diameter;
    }
private:
   int dfs(TreeNode*node){
       ios_base::sync_with_stdio(false);
       if(!node)return 0;
       int lh = dfs(node->left);
       int rh=dfs(node->right);
       diameter=max(diameter,lh+rh);
       return 1+max(lh,rh);
   }
};