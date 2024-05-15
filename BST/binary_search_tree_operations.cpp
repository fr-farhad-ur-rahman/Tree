#include <iostream>

// Define the structure of a tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Class representing a binary search tree
class BinarySearchTree {
private:
    TreeNode* root;

    // Helper function to recursively insert a node into the BST
    TreeNode* insertNode(TreeNode* node, int data) {
        if (node == nullptr)
            return new TreeNode(data);

        if (data < node->data)
            node->left = insertNode(node->left, data);
        else if (data > node->data)
            node->right = insertNode(node->right, data);

        return node;
    }

    // Helper function to recursively search for a node with given data
    TreeNode* searchNode(TreeNode* node, int data) const {
        if (node == nullptr || node->data == data)
            return node;

        if (data < node->data)
            return searchNode(node->left, data);
        else
            return searchNode(node->right, data);
    }

    // Helper function to find the minimum value node in a subtree
    TreeNode* findMinNode(TreeNode* node) const {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    // Helper function to recursively delete a node from the BST
    TreeNode* deleteNode(TreeNode* node, int data) {
        if (node == nullptr)
            return node;

        if (data < node->data)
            node->left = deleteNode(node->left, data);
        else if (data > node->data)
            node->right = deleteNode(node->right, data);
        else {
            // Node to be deleted found
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            // Node has two children
            TreeNode* temp = findMinNode(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

public:
    // Constructor
    BinarySearchTree() : root(nullptr) {}

    // Method to insert data into the BST
    void insert(int data) {
        root = insertNode(root, data);
    }

    // Method to search for a node with given data
    TreeNode* search(int data) const {
        return searchNode(root, data);
    }

    // Method to delete a node with given data from the BST
    void remove(int data) {
        root = deleteNode(root, data);
    }

    // Method to find the minimum value node in the BST
    TreeNode* findMin() const {
        if (root == nullptr)
            return nullptr;
        return findMinNode(root);
    }
};

int main() {
    BinarySearchTree bst;

    // Insert some data into the BST
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    // Search for a node
    int searchData = 7;
    TreeNode* searchedNode = bst.search(searchData);
    if (searchedNode != nullptr)
        std::cout << "Node with data " << searchData << " found in the BST." << std::endl;
    else
        std::cout << "Node with data " << searchData << " not found in the BST." << std::endl;

    // Find the minimum value node
    TreeNode* minNode = bst.findMin();
    if (minNode != nullptr)
        std::cout << "Minimum value in the BST: " << minNode->data << std::endl;

    // Remove a node
    int removeData = 3;
    bst.remove(removeData);
    std::cout << "Node with data " << removeData << " removed from the BST." << std::endl;

    return 0;
}
