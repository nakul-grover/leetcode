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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        
        ListNode* dummy = new ListNode(-1);
        ListNode*head = dummy;

        while(temp1 != NULL && temp2 != NULL){
           if(temp1->val >= temp2->val){
            head->next = temp2;
            temp2 = temp2->next;
           }
           else{
            head->next = temp1;
            temp1= temp1->next;
           }
           head = head->next;
        }
        if(temp1 != NULL ){
            head->next = temp1;

        }
        if(temp2!=NULL){
            head->next = temp2;
        }

        return dummy->next;

    }
};