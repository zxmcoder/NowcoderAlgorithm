/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//需要一手递归解决这个问题……
//寻找二叉搜索树中两个节点的最近的祖宗节点
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val<root->val&&q->val<root->val)return lowestCommonAncestor(root->left,p,q);
        if(p->val>root->val&&q->val>root->val)return lowestCommonAncestor(root->right,p,q);
        return root;
    }
};