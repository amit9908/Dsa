int findNodeCount(Node* root) {
    int count = 0;
    Node* curr = root;
    while (curr) {
        if (curr->left == NULL) {
            count++;
            curr = curr->right;
        } else {
            Node* pred = curr->left;
            while (pred->right && pred->right != curr) {
                pred = pred->right;
            }

            if (pred->right == nullptr) {
                pred->right = curr;
                curr = curr->left;
            } else {
                pred->right = NULL;
                count++;
                curr = curr->right;
            }
        }
    }
    return count;
}

float findMedian(Node* root) {
    int count = findNodeCount(root);
    int i = 0;
    int odd = (count + 1) / 2, oddVal = -1;
    int even1 = count / 2, even1Val = -1;
    int even2 = count / 2 + 1, even2Val = -1;
    Node* curr = root;
    while (curr) {
        if (curr->left == NULL) {
            i++;
            if (i == odd) oddVal = curr->data;
            if (i == even1) even1Val = curr->data;
            if (i == even2) even2Val = curr->data;
            curr = curr->right;
        } else {
            Node* pred = curr->left;
            while (pred->right && pred->right != curr) {
                pred = pred->right;
            }

            if (pred->right == nullptr) {
                pred->right = curr;
                curr = curr->left;
            } else {
                pred->right = NULL;
                i++;
                if (i == odd) oddVal = curr->data;
                if (i == even1) even1Val = curr->data;
                if (i == even2) even2Val = curr->data;
                curr = curr->right;
            }
        }
    }
    float median = 0;
    if ((count & 1) == 0)
        median = (even1Val + even2Val) / 2.0;
    else
        median = oddVal;
    return median;
}
