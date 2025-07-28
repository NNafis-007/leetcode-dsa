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

int maxD = -1;

int height(TreeNode* root){
    if(!root) return 0;
    int h = max(height(root->left), height(root->right)) + 1;
    //cout << "Height at node " << root->val << " = " << h << endl;
    return h;
}

int main(){
    TreeNode* root = new TreeNode(1);
    TreeNode* l = new TreeNode(2);
    TreeNode* r = new TreeNode(3);
    TreeNode* ll = new TreeNode(4);
    TreeNode* lr = new TreeNode(5);

    root->left = l;
    root->right = r;
    l->left = ll;
    l->right = lr;

    cout << "Max Depth : " << height(root);

}
