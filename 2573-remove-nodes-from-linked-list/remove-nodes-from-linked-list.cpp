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
    ListNode* removeNodes(ListNode* head) {
       stack<ListNode*>st;
       ListNode*temp=head;
       st.push(temp);
        temp=temp->next;
       while(temp!=NULL){
           while(!st.empty() && st.top()->val<temp->val){
               st.pop();
           }
           st.push(temp);
           temp=temp->next;
       }
       ListNode*ans=NULL;
       while(!st.empty()){
           if(ans==NULL){
               ans=st.top();
               st.pop();
           }
           else{
               ListNode*next=ans;
               ans=st.top();
               ans->next=next;
               st.pop();
}
       }
        return ans;
       
    }
};