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
 int maxDepth(TreeNode* node,int& ans) {
        if(node == NULL) return 0;
        int lh = maxDepth(node->left,ans); // left height
        int rh = maxDepth(node->right,ans); // right height
        ans = max(ans,lh+rh);
       return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans =0;
        maxDepth(root,ans);
        return ans;
    }
};