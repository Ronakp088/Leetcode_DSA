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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == NULL)
            return NULL;
        ListNode* p1 = head;
        ListNode* p2 = head;
        while (n && p1->next != NULL) {
            p1 = p1->next;
            n--;
        } // by this upper while loop we are maintaining a diff of "n"
        if (n)
            return head->next; // edge case
        while (p1->next != NULL) {
            p1 = p1->next;
            p2 = p2->next;
        }
        p2->next = p2->next->next;
        return head;
    }
};