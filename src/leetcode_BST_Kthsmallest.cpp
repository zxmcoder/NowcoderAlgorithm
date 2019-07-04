
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//求二叉搜索树中的第K小元素
class Solution {
public:
    vector<int> v;
    void inorder(TreeNode* root){
        if(root==NULL)return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        return v[k-1];
    }
};