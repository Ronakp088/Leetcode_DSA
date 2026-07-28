/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        int cnt =0;
        if(head == NULL || head->next == nullptr) return NULL;
        ListNode* temp = head; 
        map<ListNode*,int> mpp;
        while(temp != NULL){
            if(mpp.find(temp) != mpp.end()) return temp;
            else{
                mpp[temp] = cnt;
                cnt++;
            }
            temp = temp->next;
        }
        return NULL; 
    }
};