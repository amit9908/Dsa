class Solution {
public:
    Node* find_target_and_map_parents(unordered_map<Node*, Node*>& parent, Node* root, int target) {
        Node* targetNode = nullptr;
        parent[root] = nullptr;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* front = q.front();
            q.pop();
            if (front->data == target) {
                targetNode = front;
            }

            if (front->left) {
                parent[front->left] = front;
                q.push(front->left);
            }

            if (front->right) {
                parent[front->right] = front;
                q.push(front->right);
            }
        }
        return targetNode;
    }

    int burnTimeTrees(Node* targetNode, unordered_map<Node*, Node*>& parentMapping) {
        unordered_map<Node*, bool> isBurnt;
        queue<Node*> q;
        q.push(targetNode);
        isBurnt[targetNode] = true;
        int T = 0;

        while (!q.empty()) {
            int size = q.size();
            bool isFireSpreaded = false;
            for (int i = 0; i < size; i++) {
                Node* front = q.front();
                q.pop();
                if (front->left && !isBurnt[front->left]) {
                    q.push(front->left);
                    isBurnt[front->left] = true;
                    isFireSpreaded = true;
                }

                if (front->right && !isBurnt[front->right]) {
                    q.push(front->right);
                    isBurnt[front->right] = true;
                    isFireSpreaded = true;
                }

                if (parentMapping[front] && !isBurnt[parentMapping[front]] && parentMapping[front] != nullptr) {
                    q.push(parentMapping[front]);
                    isBurnt[parentMapping[front]] = true;
                    isFireSpreaded = true;
                }
            }
            if (isFireSpreaded) ++T;
        }
        return T;
    }

    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parentMapping;
        Node* targetNode = find_target_and_map_parents(parentMapping, root, target);
        return burnTimeTrees(targetNode, parentMapping);
    }
};
