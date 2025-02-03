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

/**
T.C-O(3N);
The solution uses an upper bound and an external pointer to build a BST out 
The index pointer traverses the preorder vector array .
These parameters are passed through the build function
In this tree gets constructed
1)Base case:
     This is when index reaches the end of the preorder array or the value of the array exceeds the bound. This should return null and go back to the previous condition

We then construct a new node that stores the iterating values of the vector.

2)Normal case:
     left of this node is passed recursively through the build function with the bound set at value of the root to satisfy basic BST conditions
     right of this node is passed recursively through the build function with the bound set at the earlier prexisting bound(INT_MAX initially and then the suceeding root values)
     
    */
class Solution {
private:
    TreeNode*build(vector<int>&v,int &i,int bound){
        if(i==v.size()||v[i]>bound)return NULL;
        TreeNode*root=new TreeNode(v[i++]);
        root->left=build(v,i,root->val);
        root->right=build(v,i,bound);
        return root;

    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(preorder,i,INT_MAX);
    }
};
