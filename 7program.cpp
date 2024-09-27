#include <iostream>
using namespace std;
struct TreeNode
 {
    int data;
    TreeNode* left;
    TreeNode* right;

    
    TreeNode(int val) 
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree
 {
private:
    TreeNode* root;
    void inOrderTraversal(TreeNode* node) 
    {
        if (node == nullptr) return;
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }
    TreeNode* insertNode(TreeNode* node, int val)
     {
        if (node == nullptr)
        {
            return new TreeNode(val);
        }
        if (val < node->data) 
        {
            node->left = insertNode(node->left, val);
        } else {
            node->right = insertNode(node->right, val);
        }
        return node;
    }
    bool search(TreeNode* node, int val) 
    {
        if (node == nullptr) return false;
        if (node->data == val) return true;
        if (val < node->data) return search(node->left, val);
        return search(node->right, val);
    }

public:
    
    BinaryTree()
     {
        root = nullptr;
    }
    void insert(int val) 
    {
        root = insertNode(root, val);
    }

    
    void inOrder() 
    {
        inOrderTraversal(root);
        cout << endl;
    }

    
    bool search(int val) 
    {
        return search(root, val);
    }
};

int main()
 {
    BinaryTree bt;
    bt.insert(50);
    bt.insert(30);
    bt.insert(20);
    bt.insert(40);
    bt.insert(70);
    bt.insert(60);
    bt.insert(80);
    cout << "In-order traversal: ";
    bt.inOrder();
    int searchVal = 40;
    if (bt.search(searchVal))
     {
        cout << searchVal << " found in the tree!" << endl;
    } else 
    {
        cout << searchVal << " not found in the tree!" << endl;
    }

    return 0;
}
