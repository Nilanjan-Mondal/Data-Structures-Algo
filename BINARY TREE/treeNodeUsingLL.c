#include <stdio.h>
#include <stdlib.h>

// Node structure for the binary tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create the binary tree from user input
Node* createTree() {
    int value;
    printf("Enter value for node (-1 for no node): ");
    scanf("%d", &value);

    if (value == -1) {
        return NULL; // No node created
    }

    Node* root = createNode(value);
    
    printf("Enter left child of %d:\n", root->data);
    root->left = createTree(); // Recursively create left child

    printf("Enter right child of %d:\n", root->data);
    root->right = createTree(); // Recursively create right child

    return root;
}

// Function to perform inorder traversal (LNR)
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);           // Traverse left child
    printf("%d ", root->data);     // Print root
    inorder(root->right);          // Traverse right child
}

// Function to perform preorder traversal (NLR)
void preorder(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);     // Print root
    preorder(root->left);          // Traverse left child
    preorder(root->right);         // Traverse right child
}

// Function to perform postorder traversal (LRN)
void postorder(Node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);         // Traverse left child
    postorder(root->right);        // Traverse right child
    printf("%d ", root->data);     // Print root
}

// Function to count the number of nodes
int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to calculate the height of the binary tree
int calculateHeight(Node* root) {
    if (root == NULL) {
        return 0;  // Height of an empty tree is 0
    }
    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to count the number of leaf nodes
int countLeafNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;  // Leaf node
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Function to count the number of internal nodes
int countInternalNodes(Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return 0;  // No internal node
    }
    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}

// Function to search for an element in the tree
int search(Node* root, int value) {
    if (root == NULL) {
        return 0;  // Not found
    }
    if (root->data == value) {
        return 1;  // Found
    }
    return search(root->left, value) || search(root->right, value);
}

// Function to free the allocated memory
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    // Create the tree using user input
    Node* root = createTree();

    // Display tree using inorder traversal
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    // Display tree using preorder traversal
    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    // Display tree using postorder traversal
    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    // Count the number of nodes
    printf("Number of nodes: %d\n", countNodes(root));

    // Find the height of the tree
    printf("Height of tree: %d\n", calculateHeight(root));

    // Count the number of leaf nodes
    printf("Number of leaf nodes: %d\n", countLeafNodes(root));

    // Count the number of internal nodes
    printf("Number of internal nodes: %d\n", countInternalNodes(root));

    // Search for a value in the tree
    int value;
    printf("Enter a value to search: ");
    scanf("%d", &value);
    if (search(root, value)) {
        printf("Value %d found in the tree\n", value);
    } else {
        printf("Value %d not found in the tree\n", value);
    }

    // Free the allocated memory
    freeTree(root);

    return 0;
}
