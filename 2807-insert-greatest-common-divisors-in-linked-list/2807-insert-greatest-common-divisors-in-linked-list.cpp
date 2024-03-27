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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* dummy=head;
        while(head && head->next){
            ListNode* temp=new ListNode(__gcd(head->val,head->next->val));
            ListNode* next=head->next;
            head->next=temp;
            temp->next=next;
            head=head->next->next;
        }
        return dummy;
    }
};