class Solution {
public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2) {
        // code here
        std::map<int, Node*> mp;
        Node* curr = head1;
        while (curr) {
            mp[curr->data] = curr;
            curr = curr->next;
        }

        curr = head2;
        while (curr) {
            mp[curr->data] = curr;
            curr = curr->next;
        }

        Node* UL = nullptr;
        Node* temp = nullptr;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (!UL) {
                UL = it->second;
                temp = UL;
            }
            else {
                temp->next = it->second;
                temp = temp->next;
            }
        }
        if (temp)
            temp->next = nullptr;
        
        return UL;
    }
};
