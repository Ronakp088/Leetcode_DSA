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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        vector<int> arr;
        ListNode* temp = head;
        int len =0;
        while(temp != NULL){
            len++;
            arr.push_back(temp->val);
            temp = temp->next;
        }
        k = k%len;
        reverse(arr.begin(),arr.end());
        reverse(arr.begin(),arr.begin()+k);
        reverse(arr.begin()+k,arr.end());
        temp = head;
        int i=0;
        while(temp != NULL){
            temp->val = arr[i];
            i++;
            temp = temp->next;
        }
        return head;
    }
};