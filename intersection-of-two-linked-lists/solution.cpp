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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA; // pointer for A
        ListNode* p2 = headB; // pointer ofr B
        while(p1->next != NULL && p2->next != NULL){
            p1 = p1->next;
            p2 = p2->next;
        }
        int extra =0;
        int flag =0;
        while(p1->next != NULL){
            p1 = p1->next;
            extra++;
            flag =1;
        }
        while(p2->next != NULL){
            p2 = p2->next;
            extra++;
        }
        p1 = headA;
        p2 = headB;
        if(flag == 1){
            while(extra){
                p1 =p1->next;
                extra--;
            }
        }
         else{
            while(extra){
                p2 =p2->next;
                extra--;
            }
        }
        ListNode* check = p1;
        if(p1 == p2) return p1;
        while(p1->next != NULL){
            check = p1->next;
            p1 = p1->next;
            if(p2->next == check) return p1;
            else p2 = p2->next;
        }

        return NULL;
    }
};