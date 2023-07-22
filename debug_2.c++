class Solution
{
public:
    // Function to remove duplicates from unsorted linked list.
    Node *removeDuplicates(Node *head)
    {
        // your code goes here
        unordered_map<int, bool> mp;
        Node *curr = head;

        if (curr)
        {
            mp[curr->data] = true;
        }

        while (curr != NULL)
        {
            if (mp[curr->next->data] == false)
            {
                Node *temp = curr->next;
                temp->next = NULL;
                if (curr->next->next != NULL)
                {
                    curr->next = curr->next->next;
                }
                curr = curr->next;
            }
            else
            {
                mp[curr->next] = false;
                curr = curr->next;
            }
        }
        return head;
    }
};
