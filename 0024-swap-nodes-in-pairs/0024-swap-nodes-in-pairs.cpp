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
    ListNode* swapPairs(ListNode* head) {
        
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        
        ListNode* newNode = new ListNode(0);
        ListNode* newHead = newNode;
        ListNode* temp = newHead;
        
        temp->next = p2;
        temp = temp->next;
        
        while(p2 != NULL) {
            ListNode* next = p2->next;
            
            temp->next = p1;
            temp = temp->next;
            
            p1 = next;
            
            if(p1 == NULL)
                break;
            
            p2 = p1->next;
            
            if(p2 != NULL) {
                temp->next = p2;
                temp = temp->next;
            }
        }
        
        if(p1 != NULL)
            temp->next = p1;
        temp = (p1 != NULL) ? p1 : temp;
        temp->next = NULL;
        
        return newHead->next;
    }
};