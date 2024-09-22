#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Global variables to represent the binary tree
int* tree;  // Array to store the binary tree elements
int size = 0;  // Number of nodes in the tree

void createTree(int data[], int n) {
    tree = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        tree[i] = data[i];
    }
    size = n;
}

// Inorder Traversal (LNR)
void inorder(int index) {
    if (index >= size) {
        return;
    }
    inorder(2 * index + 1);           // Traverse left child
    printf("%d ", tree[index]);       // Print root
    inorder(2 * index + 2);           // Traverse right child
}

// Preorder Traversal (NLR)
void preorder(int index) {
    if (index >= size) {
        return;
    }
    printf("%d ", tree[index]);       // Print root
    preorder(2 * index + 1);          // Traverse left child
    preorder(2 * index + 2);          // Traverse right child
}

// Postorder Traversal (LRN)
void postorder(int index) {
    if (index >= size) {
        return;
    }
    postorder(2 * index + 1);         // Traverse left child
    postorder(2 * index + 2);         // Traverse right child
    printf("%d ", tree[index]);       // Print root
}

// Function to count the number of nodes
int countNodes() {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (tree[i] != -1) {
            count++;
        }
    }
    return count;
}

// Function to calculate the height of the binary tree without log2 and ceil
int calculateHeight(int index) {
    if (index >= size) {
        return -1;  // If node is empty or doesn't exist, return -1 (base height)
    }
    int leftHeight = calculateHeight(2 * index + 1);  // Height of the left subtree
    int rightHeight = calculateHeight(2 * index + 2); // Height of the right subtree
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to count the number of leaf nodes
int countLeafNodes() {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (2 * i + 1 >= size && 2 * i + 2 >= size) {
            count++;
        }
    }
    return count;
}

// Function to count the number of internal nodes
int countInternalNodes() {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (2 * i + 1 < size || 2 * i + 2 < size) {
            count++;
        }
    }
    return count;
}

// Function to search for an element in the tree
int search(int value) {
    for (int i = 0; i < size; i++) {
        if (tree[i] == value) {
            return i;  // Return the index if found
        }
    }
    return -1;  // Return -1 if not found
}



int main() {
    int n = 7;  // Number of nodes in the tree
    // initializeTree(n);

    // Example data to create the tree
    int data[] = {1, 2, 3, 4, 5, 6, 7};
    
    createTree(data, n);

    // Display tree using inorder traversal
    printf("Inorder Traversal: ");
    inorder(0);
    printf("\n");

    // Display tree using preorder traversal
    printf("Preorder Traversal: ");
    preorder(0);
    printf("\n");

    // Display tree using postorder traversal
    printf("Postorder Traversal: ");
    postorder(0);
    printf("\n");

    // Count the number of nodes
    printf("Number of nodes: %d\n", countNodes());

    // Find the height of the tree without using log2 and ceil
    printf("Height of tree: %d\n", calculateHeight(0));

    // Count the number of leaf nodes
    printf("Number of leaf nodes: %d\n", countLeafNodes());

    // Count the number of internal nodes
    printf("Number of internal nodes: %d\n", countInternalNodes());

    // Search for a value in the tree
    int value = 5;
    int searchResult = search(value);
    if (searchResult != -1) {
        printf("Value %d found at index %d\n", value, searchResult);
    } else {
        printf("Value %d not found in the tree\n", value);
    }

}
