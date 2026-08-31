/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> v;
     //   vecotr<int> ans;
        int store = head->val;
        ListNode* curr = head->next;
         ListNode* nextcurr =NULL;
        if(curr->next) nextcurr = curr->next;
        else  return {-1,-1};
        int posi =1;
        int c =0;
        int nc =0;
        while(nextcurr->next != nullptr){
             c = curr->val;
            nc = nextcurr->val;
            if(c>nc && c>store) v.push_back(posi);
            else if(c<nc && c<store) v.push_back(posi);
            
            store = curr->val;
            curr = curr->next;
            nextcurr=nextcurr->next;
            posi++;
        }
        c = curr->val;
        nc = nextcurr->val;
        if(c>nc && c>store) v.push_back(posi);
            else if(c<nc && c<store) v.push_back(posi);
        
        int mini = INT_MAX;
        if(v.size() < 2) return{-1,-1};
        
       int   maxi = v[v.size()-1] -v[0];
        for(int i =1;i<v.size();i++){
            mini = min(v[i]-v[i-1],mini);
        }
        
        return {mini,maxi};
    }
};