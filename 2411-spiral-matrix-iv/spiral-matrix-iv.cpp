class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int dir = 1; 
        int i1 = 0, j1 = 0, i2 = m - 1, j2 = n - 1;

        while (head) {
            if (dir == 1) { 
                for (int k = j1; k <= j2; k++) {
                    ans[i1][k] = head->val;
                    head = head->next;
                    if (!head) break; 
                }
                i1++;
            }
            else if (dir == 2) {
                for (int k = i1; k <= i2; k++) {
                    ans[k][j2] = head->val;
                    head = head->next;
                    if (!head) break;
                }
                j2--;
            }
            else if (dir == 3) { 
                for (int k = j2; k >= j1; k--) {
                    ans[i2][k] = head->val;
                    head = head->next;
                    if (!head) break;
                }
                i2--;
            }
            else if (dir == 4) { 
                for (int k = i2; k >= i1; k--) {
                    ans[k][j1] = head->val;
                    head = head->next;
                    if (!head) break;
                }
                j1++;
            }
            dir = (dir % 4) + 1; 
        }

        return ans;
    }
};
