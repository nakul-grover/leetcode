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
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(!head){
            return head;
        }

        ListNode * temp = head;

        for(int i=0;i<k-1;i++){
            temp = temp->next;
            if(!temp){
            return head;
        }
        }
        if(!temp){
            return head;
        }

        ListNode* curr = head;
        ListNode* prev = NULL;

            int count = k;
            temp = NULL;
            while(curr != NULL && count>0){
                temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
                count--;
            }
            head->next = reverseKGroup(curr,k);
        return prev;
    }
};