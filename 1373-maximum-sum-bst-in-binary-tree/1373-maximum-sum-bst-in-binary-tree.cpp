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
class Nodevalue {
public:
    int maxnode;
    int minnode;
    int sum;

    Nodevalue(int maxnode, int minnode, int sum) {
        this->maxnode = maxnode;
        this->minnode = minnode;
        this->sum = sum;
    }
};

class Solution {
public:
    int ans = 0;

    Nodevalue solve(TreeNode* root) {

        // Empty tree
        if (!root) {
            return Nodevalue(INT_MIN, INT_MAX, 0);
        }

        // Get information from left and right subtree
        auto left = solve(root->left);
        auto right = solve(root->right);

        // Check whether current subtree is BST
        if (left.maxnode < root->val &&
            root->val < right.minnode) {

            int sum = left.sum + root->val + right.sum;

            // Update maximum BST sum
            ans = max(ans, sum);

            return Nodevalue(
                max(root->val, right.maxnode),
                min(root->val, left.minnode),
                sum
            );
        }

        // Current subtree is NOT a BST
        return Nodevalue(INT_MAX, INT_MIN, 0);
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};