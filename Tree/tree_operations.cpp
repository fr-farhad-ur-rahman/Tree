#include <iostream>
#include <queue>

// Define the structure of a tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Class representing a binary tree
class BinaryTree {
private:
    TreeNode* root;

    // Helper function to recursively insert a node into the tree
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

    // Helper function to recursively delete a node from the tree
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

    // Helper function to calculate the height of a tree
    int calculateHeight(TreeNode* node) const {
        if (node == nullptr)
            return 0;

        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);

        return 1 + std::max(leftHeight, rightHeight);
    }

public:
    // Constructor
    BinaryTree() : root(nullptr) {}

    // Method to insert data into the tree
    void insert(int data) {
        root = insertNode(root, data);
    }

    // Method to search for a node with given data
    TreeNode* search(int data) const {
        return searchNode(root, data);
    }

    // Method to delete a node with given data from the tree
    void remove(int data) {
        root = deleteNode(root, data);
    }

    // Method to calculate the height of the tree
    int height() const {
        return calculateHeight(root);
    }

    // Method to print the tree level by level (Breadth-first traversal)
    void printLevelOrder() const {
        if (root == nullptr)
            return;

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            std::cout << current->data << " ";

            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }
        std::cout << std::endl;
    }
};

int main() {
    BinaryTree tree;

    // Insert some data into the tree
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    // Print the tree level by level
    std::cout << "Level order traversal: ";
    tree.printLevelOrder();

    // Search for a node
    int searchData = 7;
    TreeNode* searchedNode = tree.search(searchData);
    if (searchedNode != nullptr)
        std::cout << "Node with data " << searchData << " found in the tree." << std::endl;
    else
        std::cout << "Node with data " << searchData << " not found in the tree." << std::endl;

    // Remove a node
    int removeData = 3;
    tree.remove(removeData);
    std::cout << "Node with data " << removeData << " removed." << std::endl;

    // Print the updated tree level by level
    std::cout << "Updated level order traversal: ";
    tree.printLevelOrder();

    // Calculate the height of the tree
    std::cout << "Height of the tree: " << tree.height() << std::endl;

    return 0;
}
