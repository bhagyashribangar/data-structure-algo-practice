// BFS: Level Order Traversal
// DFS: Inorder, Preorder, Postorder Traversal

#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {};
};

class BinaryTree {
public:
    BinaryTree() : root(nullptr) {};
    void insert(int value) {
        insertNode(root, value);
    }

    void levelOrderTravesal() const {
        levelOrderTravesal(root);
    }

    void inorderTraversal() const {
        inorderTraversal(root);
    }
    void preorderTraversal() const {
        preorderTraversal(root);
    }
    void postorderTraversal() const {
        postorderTraversal(root);
    }

    bool searchElement(int value) const {
        return searchElement(root, value);
    }

    int findMin() const {
        return findMin(root)->data;
    }

    int findMax() const {
        return findMax(root)->data;
    }

    void deleteElement(int value) {
        root = deleteElement(root, value);
    }

private:
    TreeNode* root;
    void insertNode(TreeNode*& node, int val) {
        if (node == nullptr) {
            node = new TreeNode(val);
        } else {
            if (val < node->data) {
                insertNode(node->left, val);
            } else {
                insertNode(node->right, val);
            }
        }
    }

    void levelOrderTravesal(const TreeNode* node) const {
        if (node == nullptr) {
            // Empty tree
            return;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* currNode = q.front();
            cout << currNode->data << " ";
            q.pop();

            if (currNode->left) {
                q.push(currNode->left);
            }

            if (currNode->right) {
                q.push(currNode->right);
            }
        }
        cout << endl;
    }

    void preorderTraversal(const TreeNode* node) const {
        if (node != nullptr) {
            cout << node->data << " ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    void postorderTraversal(const TreeNode* node) const {
        if (node != nullptr) {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            cout << node->data << " ";
        }
    }

    void inorderTraversal(const TreeNode* node) const {
        if (node != nullptr) {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    bool searchElement(const TreeNode* node, int value) const {
        if (node == nullptr) {
            return false;
        } else if (value == node->data) {
            return true;
        } else if (value < node->data) {
            searchElement(node->left, value);
        } else {
            searchElement(node->right, value);
        }
    }

    TreeNode* findMin(TreeNode* node) const {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    TreeNode* findMax(TreeNode* node) const {
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    TreeNode* deleteElement(TreeNode* node, int value) {
        if (node == nullptr) {
            return node;
        }
        
        if (value < node->data) {
            node->left = deleteElement(node->left, value);
        } else if (value > node->data) {
            node->right = deleteElement(node->right, value);
        } else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            }
            if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            TreeNode* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteElement(node->right, temp->data);
        }
        return node;
    }
};

int main()
{
    BinaryTree tree;
    tree.insert(6);
    tree.insert(4);
    tree.insert(5);
    cout << "Level Order Traversal is: ";
    tree.levelOrderTravesal();
    cout << "Inorder Traversal is: ";
    tree.inorderTraversal();
    cout << endl;
    cout << "Preorder Traversal is: ";
    tree.preorderTraversal();
    cout << endl;
    cout << "Postorder Traversal is: ";
    tree.postorderTraversal();
    cout << endl;
    int element = 9;
    cout << (tree.searchElement(element) ? "Element found" : "Element not found") << endl;
    cout << "Minimum is: " << tree.findMin() << endl;
    cout << "Maximum is: " << tree.findMax() << endl;

    int delElement = 4;
    tree.deleteElement(delElement);
    tree.inorderTraversal();

    return 0;
}