class Solution
{
public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node *segregate(Node *head)
    {
        // Check for an empty linked list.
        if (head == NULL)
            return NULL;

        Node *zeroHead = new Node(-1);
        Node *zeroTail = zeroHead;

        Node *oneHead = new Node(-1);
        Node *oneTail = oneHead;

        Node *twoHead = new Node(-1);
        Node *twoTail = twoHead;

        Node *curr = head;

        while (curr != NULL)
        {
            if (curr->data == 0)
            {
                Node *temp = curr;
                curr = curr->next;
                temp->next = NULL;
                zeroTail->next = temp;
                zeroTail = temp;
            }
            else if (curr->data == 1)
            {
                Node *temp = curr;
                curr = curr->next;
                temp->next = NULL;
                oneTail->next = temp;
                oneTail = temp;
            }
            else
            {
                Node *temp = curr;
                curr = curr->next;
                temp->next = NULL;
                twoTail->next = temp;
                twoTail = temp;
            }
        }

        Node *temp = oneHead;
        oneHead = oneHead->next;
        temp->next = NULL;
        delete temp;

        temp = twoHead;
        twoHead = twoHead->next;
        temp->next = NULL;
        delete temp;

        if (oneHead != NULL)
        {
            zeroTail->next = oneHead;
            if (twoHead != NULL)
            {
                oneTail->next = twoHead;
            }
        }
        else
        {
            if (twoHead != NULL)
            {
                zeroTail->next = twoHead;
            }
        }

        temp = zeroHead;
        zeroHead = zeroHead->next;
        temp->next = NULL;
        delete temp;

        return zeroHead;
    }
};