#include <stdio.h>
#include <stdlib.h>

// Tree structure
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Find LCA
struct TreeNode* findLCA(struct TreeNode* root, int p, int q) {
    if (root == NULL)
        return NULL;

    if (p < root->val && q < root->val)
        return findLCA(root->left, p, q);

    if (p > root->val && q > root->val)
        return findLCA(root->right, p, q);

    return root;
}

int main() {
    int n, p, q;
    scanf("%d", &n);

    struct TreeNode* root = NULL;

    // Input and build BST
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        root = insert(root, val);
    }

    scanf("%d %d", &p, &q);

    struct TreeNode* lca = findLCA(root, p, q);

    if (lca != NULL)
        printf("%d\n", lca->val);

    return 0;
}