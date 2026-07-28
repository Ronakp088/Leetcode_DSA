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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = head;
        ListNode* front = head->next;
        ListNode* NewNode = new ListNode();
        ListNode* NewHead = NewNode;
        int cnt =0;
        while(front != NULL ){
        if(temp->val == front->val){
            temp = temp->next;
            front = front->next;
            cnt =1;
        }
        else if(cnt){
            temp = temp->next;
            front = front->next;
            cnt =0;
        }
        else{
            NewNode->next = temp;
            NewNode = NewNode->next;
            temp = temp->next;
            front = front->next;
            NewNode->next = NULL;
        }
        }
        if(temp != NULL && cnt == 0) NewNode->next = temp;
        return NewHead->next;
    }
};