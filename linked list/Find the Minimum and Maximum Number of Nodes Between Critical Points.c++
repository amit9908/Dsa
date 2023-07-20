class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};
        ListNode* prev = head;
        if (!prev) return ans;
        ListNode* curr = head->next;
        if (!curr) return ans;
        ListNode* nxt = head->next->next;
        if (!nxt) return ans;

        int firstCp = -1;
        int lastCp = -1;
        int minDist = INT_MAX;
        int i = 1;
        while (nxt) {
            bool isCp = ((curr->val > prev->val && curr->val > nxt->val) || (curr->val < prev->val && curr->val < nxt->val)) ? true : false;
            if (isCp && firstCp == -1) {
                firstCp = i;
                lastCp = i;
            } else if (isCp) {
                minDist = min(minDist, i - lastCp);
                lastCp = i;
            }
            i++;
            prev = prev->next;
            curr = curr->next;
            nxt = nxt->next; // Corrected the variable name from next to nxt
        }
        if (lastCp == firstCp) {
            return ans;
        } else {
            ans[0] = minDist;
            ans[1] = lastCp - firstCp;
        }

        return ans;
    }
};
