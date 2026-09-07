/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> vp;
        vector<TreeNode*> vq;
        TreeNode* nodep = root;
        TreeNode* nodeq = root;
        if(nodep->val == p->val) vp.push_back(nodep);
        else
        {
            while(nodep->val != p->val){
                vp.push_back(nodep);
                if(p->val > nodep->val){
                    nodep = nodep->right;
                }
                else{
                    nodep = nodep->left;
                }
            }
            vp.push_back(nodep);
         }

        if(nodeq->val == q->val) vq.push_back(nodeq);
        else
        {
            while(nodeq->val != q->val){
                vq.push_back(nodeq);
                if(q->val > nodeq->val){
                    nodeq = nodeq->right;
                }
                else{
                    nodeq = nodeq->left;
                }
            }
            vq.push_back(nodeq);
         }

        int i =0;
        while(i < vp.size() && i < vq.size() && vp[i]->val == vq[i]->val){
            i++;
        }
        i--;
        return vp[i];
    }
};