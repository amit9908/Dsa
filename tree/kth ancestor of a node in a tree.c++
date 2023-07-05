bool findAncestor(Node *root, int &k, int node, int &ans) {
    if (root == NULL) {
        return false;
    }

    if (root->data == node) {
        return true;
    }

    bool b1 = findAncestor(root->left, k, node, ans);
    bool b2 = findAncestor(root->right, k, node, ans);

    if (b1 || b2) {
        k--;

    }
    if (k == 0) { // Update ans only if it's not already set
        ans = root->data;
        k = -1;
    }
    return b1 || b2;
}

int kthAncestor(Node *root, int k, int node) {
    int ans = -1;
    findAncestor(root, k, node, ans);
    return ans;
}