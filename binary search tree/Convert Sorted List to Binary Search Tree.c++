class Solution {
public:
    TreeNode* solve(ListNode*& head, int cnt) {
        if (cnt <= 0) return NULL;
        
        TreeNode* leftAns = solve(head, (cnt - 1) / 2);
        
        TreeNode* root = new TreeNode(head->val);
        root->left = leftAns;
        
        head = head->next;
        
        root->right = solve(head, cnt - 1 - (cnt - 1) / 2);
        
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) return NULL;
        
        int cnt = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        
        return solve(head, cnt);
    }
};
