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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int cnt = 0;
        while(temp != nullptr){
            cnt++;
            temp = temp->next;
        }
        int k =0;
        if(cnt%2 == 1) k = (cnt+1)/2;
        else k = cnt/2 +1;

        if(k == 1) return head;
        ListNode* temp1 = head;
        for(int i=1;i<k;i++){
            temp1 = temp1->next;
        }

    return temp1;
    }
};