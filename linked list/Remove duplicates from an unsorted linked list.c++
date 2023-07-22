class Solution
{
public:
    // Function to remove duplicates from unsorted linked list.
    Node *removeDuplicates(Node *head)
    {
        if (head == NULL)
            return NULL;

        unordered_map<int, bool> mp;
        Node *curr = head;
        mp[curr->data] = true;
        Node *prev = curr;
        curr = curr->next;

        while (curr != NULL)
        {
            if (mp[curr->data] == false)
            {
                mp[curr->data] = true;
                prev = curr;
                curr = curr->next;
            }
            else
            {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
        }
        return head;
    }
};