class Solution {
public:
   Node* helper(Node* head, unordered_map<Node*, Node*>& mp) {
        if (head == NULL)
            return NULL;

        Node* newHead = new Node(head->val);
        mp[head] = newHead;
        newHead->next = helper(head->next, mp);
        if (head->random) {
            newHead->random = mp[head->random];
        }

        return newHead;
    }

    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        return helper(head, mp);
    }
};
//t.c 0(n)
//s.c 0(n)

class Solution {
public:
//    Node* helper(Node* head, unordered_map<Node*, Node*>& mp) {
//         if (head == NULL)
//             return NULL;

//         Node* newHead = new Node(head->val);
//         mp[head] = newHead;
//         newHead->next = helper(head->next, mp);
//         if (head->random) {
//             newHead->random = mp[head->random];
//         }

//         return newHead;
//     }
     
    

    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node* it = head;
        //step 1
        while(it){
            Node* cloneNode = new Node(it->val);
            cloneNode->next = it->next;
            it->next = cloneNode;
            it = it->next->next;
        }

        //step 2
        it = head;
        while(it){
            Node* cloneNode = it->next;
            cloneNode->random = it->random ? it->random->next:nullptr;
            it = it->next->next;
        }

        //step 3
        it = head;
        Node* clonehead = it->next;
        while(it){
            Node* cloneNode = it->next;
            it->next = it->next->next;
            if(cloneNode->next){
                cloneNode->next = cloneNode->next->next;
            }
            it = it->next;
        }
        return clonehead;
    }
};

//t.c 0(n)
//s.c 0(1)