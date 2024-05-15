#include <iostream>
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree{
private:
    TreeNode* root;

    TreeNode* insertNode(TreeNode* node, int data) {
        if(node == nullptr) {
            return new TreeNode(data);
        }

        if(data < node->data) {
            node->left = insertNode(node->left, data);
        }
        else if(data > node->data) {
            node->right = insertNode(node->right, data);
        }

        return node;
    }

    TreeNode* searchNode(TreeNode* node, int data) const {
        if(node == nullptr or node->data == data) return node;

        if(data < node->data) {
            return searchNode(node->left, data);
        }
        else {
            return searchNode(node->right, data);
        }
    }

    TreeNode* deleteNode(TreeNode* node, int data) {
        if(node == nullptr) {
            return node;
        }

        if(data < node->data) {
            node->left = deleteNode(node->left, data);
        }
        else if(data > node->data) {
            node->right = deleteNode(node->right, data);
        }
        else {
            if(node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            }
            else if(node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            TreeNode* temp = findMinNode(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    TreeNode* findMinNode(TreeNode* node) const {
        while(node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int data) {
        root = insertNode(root, data);
    }

    TreeNode* search(int data) const {
        return searchNode(root, data);
    }

    void remove(int data) {
        root = deleteNode(root, data);
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

    // Remove a node
    int removeData = 3;
    bst.remove(removeData);
    std::cout << "Node with data " << removeData << " removed from the BST." << std::endl;

    return 0;
}
