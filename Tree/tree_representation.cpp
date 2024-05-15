#include <iostream>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr){}
};

class BinaryTree{
private:
    TreeNode* root;

    void printTree(TreeNode* node, int depth) const {
        if (node == nullptr) return;

        printTree(node->right, depth + 1);

        for(int i = 0; i < depth; i++){
            cout << "  ";
        }
        cout << node->data << endl;

        printTree(node->left, depth + 1);
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(int data) {
        root = insertNode(root, data);
    }

    TreeNode* insertNode(TreeNode* node, int data){
        if(node == nullptr){
            return new TreeNode(data);
        }

        if(data < node->data){
            node->left = insertNode(node->left, data);
        } else if( data > node -> data ) {
            node->right = insertNode(node->right, data);
        }

        return node;
    }

    void print() const {
        printTree(root, 0);
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

    tree.print();

    return 0;
}
