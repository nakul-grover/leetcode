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
    ListNode* doubleIt(ListNode* newhead) {
        ListNode*prev=NULL;
        ListNode*next=NULL;
        while(newhead){
            next=newhead->next;
            newhead->next=prev;
            prev=newhead;
            newhead=next;
        }
        int borrow=0;
        ListNode*newList=NULL;
        while(prev){
            int value=borrow+2*(prev->val);
            if(newList==NULL){
                ListNode *n=new ListNode(value%10);
                newList=n;
            }
            else{
                ListNode* n =new ListNode(value%10);
                n->next=newList;
                newList=n;
            }
            borrow=value/10;
            prev=prev->next;
        }
        if(borrow){
            ListNode* n =new ListNode(borrow);
            n->next=newList;
            newList=n;

            
        }
        return newList;
    }
};