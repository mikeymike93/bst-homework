#include <iostream>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(int value)
{
    TreeNode* newNode = new TreeNode;
    newNode->value = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

TreeNode* insert(TreeNode* root, int value)
{
    if (root == nullptr)
    {
        return createNode(value);
    }

    if (value < root->value)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

void inOrder(TreeNode* root)
{
    if (root != nullptr)
    {
        inOrder(root->left);
        cout << root->value << " ";
        inOrder(root->right);
    }
}

bool search(TreeNode* root, int target)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->value == target)
    {
        return true;
    }
    else if (target < root->value)
    {
        return search(root->left, target);
    }
    else
    {
        return search(root->right, target);
    }
}

int main()
{
    TreeNode* root = nullptr;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "In-order traversal: ";
    inOrder(root);
    cout << endl;

    int number;

    cout << "Enter a number to search for: ";
    cin >> number;

    if (search(root, number))
    {
        cout << number << " was found in the tree." << endl;
    }
    else
    {
        cout << number << " was not found in the tree." << endl;
    }

    return 0;
}