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
    pair<int,int> solve(TreeNode* node,int & cnt){
        if(node == NULL) return{0,0};
       pair<int,int> left = solve(node->left,cnt);
       pair<int,int> right = solve(node->right,cnt);
        if((left.first+right.first+node->val)/(left.second+right.second+1) == node->val) cnt++;

        return{left.first+right.first+node->val,left.second+right.second+1};
    }
    int averageOfSubtree(TreeNode* root) {
        int cnt = 0;
        solve(root,cnt);
        return cnt;
    }
};