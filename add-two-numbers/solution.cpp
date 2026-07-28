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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        queue<int> st;
        ListNode* temp1 =l1;
        ListNode* temp2 =l2;
        // while(temp->next != NULL){

        // }
        if(l1->next == nullptr & l2->next == nullptr){
            if(l1->val == 0 && l2->val == 0) return l1;
        }
        int cal=0;
        while(temp1 != NULL && temp2 != NULL){
            if(temp1->val + temp2->val  + cal < 10) {
                st.push(temp1->val + temp2->val + cal);
                cal =0;
            }
            else{
                st.push((temp1->val + temp2->val  + cal)%10);
                cal = 1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
       // if(st.front() == 0) st.push(cal);
        while(temp1 != NULL){
        int sum = temp1->val + cal;
        st.push(sum % 10);
        cal = sum / 10;
        temp1 = temp1->next;
     }

        while(temp2 != NULL){
        int sum = temp2->val + cal;
        st.push(sum % 10);
        cal = sum / 10;
        temp2 = temp2->next;
        }

if(cal > 0) st.push(cal);  // line 37 wala theek hai
        ListNode* head = new ListNode(st.front());
        st.pop();
        ListNode* mover = head;
        while(!st.empty()){
            ListNode* temp = new ListNode(st.front());
            st.pop();
            mover->next = temp;
            mover = temp;
        }
        return head;
   }
};