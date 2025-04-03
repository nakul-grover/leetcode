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

        int carry = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* head = dummy;

        while(l1 != NULL && l2!= NULL){
            int sum = l1->val + l2->val + carry;
            carry = sum/10;
            sum = sum%10;
             ListNode* temp = new ListNode(sum);
             head->next = temp;
             head=head->next;
             l1 = l1->next;
             l2 = l2->next; 
        }

        while(l1){
            int sum = l1->val + carry;
            carry = sum/10;
            sum = sum%10;
            head->next = new ListNode(sum);
            l1 = l1->next;
            head=head->next;
        }
        while(l2){
            int sum = l2->val + carry;
            carry = sum/10;
            sum = sum%10;
            head->next = new ListNode(sum);
            l2 = l2->next;
            head=head->next;
        }

        if(carry > 0){
            head->next = new ListNode(carry);
        };


        return dummy->next;
    }
};