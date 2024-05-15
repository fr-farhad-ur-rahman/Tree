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

    // Helper function to recursively perform in-order traversal
    void inorderTraversal(TreeNode* node) const {
        if (node == nullptr)
            return;

        inorderTraversal(node->left);
        std::cout << node->data << " ";
        inorderTraversal(node->right);
    }

    // Helper function to recursively perform pre-order traversal
    void preorderTraversal(TreeNode* node) const {
        if (node == nullptr)
            return;

        std::cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    // Helper function to recursively perform post-order traversal
    void postorderTraversal(TreeNode* node) const {
        if (node == nullptr)
            return;

        postorderTraversal(node->left);
        postorderTraversal(node->right);
        std::cout << node->data << " ";
    }

public:
    // Constructor
    BinarySearchTree() : root(nullptr) {}

    // Method to insert data into the BST
    void insert(int data) {
        root = insertNode(root, data);
    }

    // Method to perform in-order traversal
    void inorder() const {
        inorderTraversal(root);
        std::cout << std::endl;
    }

    // Method to perform pre-order traversal
    void preorder() const {
        preorderTraversal(root);
        std::cout << std::endl;
    }

    // Method to perform post-order traversal
    void postorder() const {
        postorderTraversal(root);
        std::cout << std::endl;
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

    // Perform different tree traversals
    std::cout << "In-order traversal: ";
    bst.inorder();

    std::cout << "Pre-order traversal: ";
    bst.preorder();

    std::cout << "Post-order traversal: ";
    bst.postorder();

    return 0;
}
