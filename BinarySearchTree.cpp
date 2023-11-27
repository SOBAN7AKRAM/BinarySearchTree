#include <iostream> 
using namespace std;
struct Node
{
    Node* left;
    Node* right;
    int value;
    Node(int val)
    {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};
class BinarySearchTree
{
public:
    Node* insertInBST(Node* root, int val)
    {
        Node* temp = new Node(val);
        if (root == nullptr)
        {
            root = temp;
        }
        else
        {
            if (val > root -> value)
            {
                root -> right = insertInBST(root -> right, val);
            }
            else if (val < root -> value)
            {
                root -> left = insertInBST(root -> left, val);
            }
        }
        return root;
    }
    Node* search(Node* root, int val)
    {
        if (root == nullptr || root -> value == val)
        {
            return root;
        }
        else if (val > root -> value)
        {
            return search(root -> right, val);
        }
        else 
        {
            return search(root -> left, val);
        }
    }
    void inorder(Node* root)
    {
        if (root != nullptr)
        {
            inorder(root -> left);
            cout << root -> value << " ";
            inorder(root -> right);
        }
    }
    
    

};
struct binaryTree
{
    int val;
    binaryTree* left;
    binaryTree* right;
    binaryTree(int val)
    {
        left = right = nullptr;
        this -> val = val;
    }
};
int evenCounts(binaryTree* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int rootCount = (root -> val % 2 == 0) ? 1 : 0;
    int leftCount = evenCounts(root -> left);
    int rightCount = evenCounts(root -> right);
    return rootCount + leftCount + rightCount;
}
int height(binaryTree* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left = height(root -> left);
    int right = height(root -> right);
    if (left > right)
    {
        return left + 1;
    }
    else 
    {
        return right + 1;
    }
}
bool isSameTree(Node* tree1, Node* tree2)
{
    if (tree1 == nullptr && tree2 == nullptr)
    {
        return true;
    }
    else if (tree1 == nullptr || tree2 == nullptr)
    {
        return false;
    }
    else if (tree1 -> value != tree2 -> value)
    {
        return false;
    }
    else
    {
      bool left = isSameTree(tree1 -> left, tree2 -> left);
      bool right = isSameTree(tree1 -> right, tree2 -> right);
      return left && right;
    }
}
int countInternalNodes(Node* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int count = 0;
    if (root -> left != nullptr || root -> right != nullptr)
    {
        count = 1;
    }
    count += countInternalNodes(root -> left);
    count += countInternalNodes(root -> right);
    return count;
}
int countLeafNodes(Node* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int count = 0;
    if (root -> left == nullptr && root -> right == nullptr)
    {
        count = 1;
    }
    count += countLeafNodes(root -> left);
    count += countLeafNodes(root -> right);
    return count;
}

int main()
{
    Node* root = nullptr;
    BinarySearchTree bst;
    root = bst.insertInBST(root, 8);
    bst.insertInBST(root, 3);
    bst.insertInBST(root, 1);
    bst.insertInBST(root, 6);
    bst.insertInBST(root, 7);
    bst.insertInBST(root, 10);
    bst.insertInBST(root, 14);
    // bst.insertInBST(root, 4);
    // cout << countLeafNodes(root) << endl;
    // bst.inorder(root);
    // root = bst.search(root, 102);
    // cout << root -> value << endl;
//    Node* root2 = nullptr;
//     BinarySearchTree bst2;
//     root2 = bst2.insertInBST(root2, 8);
//     bst2.insertInBST(root2, 3);
//     bst2.insertInBST(root2, 4);
//     bst2.insertInBST(root2, 6);
//     bst2.insertInBST(root2, 7);
//     bst2.insertInBST(root2, 10);
//     bst2.insertInBST(root2, 14);
//     bst2.insertInBST(root2, 4);
//      cout << isSameTree(root, root2) << endl;


    // binaryTree* root = new binaryTree(1);
    // root -> left = new binaryTree(2);
    // root -> right = new binaryTree(3);
    // root->left->left = new binaryTree(4);
    // root->left->right = new binaryTree(5);
    // cout << evenCounts(root) << endl;
    // cout << height(root) << endl;
    return 0;
}