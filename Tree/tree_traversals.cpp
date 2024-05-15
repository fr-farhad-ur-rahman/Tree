#include <iostream>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
private:
    TreeNode* root;

    void inorderTraversal(TreeNode* node) const {
        if(node == nullptr) return;

        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    void preorder_traversal(TreeNode* node) const {
        if(node == nullptr) return;

        cout << node->data << " ";
        preorder_traversal(node->left);
        preorder_traversal(node->right);
    }

    void postorder_traversal(TreeNode* node) const {
        if(node == nullptr) return;

        postorder_traversal(node->left);
        postorder_traversal(node->right);
        cout << node->data << " ";
    }
public:
    BinaryTree() : root(nullptr){}

    void insert(int data){
        root = insertNode(root, data);
    }

    TreeNode* insertNode(TreeNode* node, int data){
        if(node == nullptr){
            return new TreeNode(data);
        }

        if(data < node->data){
            node->left = insertNode(node->left, data);
        } else if(data > node->data) {
            node->right = insertNode(node->right, data);
        }

        return node;
    }

    void inorder() const {
        inorderTraversal(root);
        cout << endl;
    }

    void preorder() const {
        preorder_traversal(root);
        cout << endl;
    }

    void postorder() const {
        postorder_traversal(root);
        cout << endl;
    }
};

int main(){
    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    cout << "In-order traversal: ";
    tree.inorder();

    cout << "Pre-order traversal: ";
    tree.preorder();

    cout << "Post-order traversal: ";
    tree.postorder();

    return 0;
}

