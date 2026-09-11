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
void solve(TreeNode* root,stack<TreeNode*> & st,TreeNode* &c1,TreeNode* &c2,int& flag){
    if(root == NULL)return;
    solve(root->left,st,c1,c2,flag);
        if(!st.empty()){
            if(st.top()->val > root->val && flag == 0){
                c1 = st.top();
                c2 = root;
                flag = 1;
            }
            else if(st.top()->val > root->val && flag == 1){
                c2 = root;
            }
            st.pop();
        }
        st.push(root);
    solve(root->right,st,c1,c2,flag);
}
    void recoverTree(TreeNode* root) {
        if(root == NULL) return ;
        stack<TreeNode*> st;
        TreeNode* c1 = NULL;
        TreeNode* c2 = NULL;
        int flag = 0;
        solve(root,st,c1,c2,flag);
        if(c1 != NULL && c2 != NULL){int temp = c1->val;
        c1->val = c2->val;
        c2->val = temp;}
    }
};