class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return head;

        // Check if there are at least k nodes left
        ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            if (!temp) return head; // not enough nodes to reverse
            temp = temp->next;
        }

        // Reverse k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        int count = 0;

        while (curr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        head->next = reverseKGroup(curr, k);

        return prev;
    }
};
