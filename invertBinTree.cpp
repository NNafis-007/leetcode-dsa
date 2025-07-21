#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *invertTree(TreeNode *root)
{
    if(root->left == nullptr && root->right == nullptr)
        return root;
    
    TreeNode* nl = invertTree(root->left);
    TreeNode* nr = invertTree(root->right);
    root->left = nr;
    root->right = nl;
    return root;
}

int main()
{
    return 0;
}
