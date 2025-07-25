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

bool addP = false, addQ = false;
TreeNode* ans = nullptr;

void postOrder(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root)
        return;

    // Reset state for child nodes
    addP = false;
    addQ = false;

    if(!ans)
        postOrder(root->left, p, q);
    if (ans)
    {
        cout << "LCA FOUND after LEFT CALL of " << root->val << endl;
        return;
    }

    // Store LST states for parent nodes as they might change in child
    bool prevAddp = addP;
    bool prevAddQ = addQ;

    if(!ans)
        postOrder(root->right, p, q);
    if (ans)
    {
        cout << "LCA FOUND after RIGHT CALL of " << root->val << endl;
        return;
    }


    // if current node is an ancestor, parent will be one too
    if (root->val == p->val || prevAddp)
        addP = true;
    if (root->val == q->val || prevAddQ)
        addQ = true;

    if (addP && addQ && !ans)
    {
        ans = root;
        cout << "SETTING " << root->val << " as answer" << endl;
    }
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    postOrder(root, p, q);
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(6);
    TreeNode *l = new TreeNode(2);
    TreeNode *ll = new TreeNode(0);
    TreeNode *lr = new TreeNode(4);

    TreeNode *r = new TreeNode(8);
    TreeNode *rl = new TreeNode(7);
    TreeNode *rr = new TreeNode(9);

    root->left = l;
    root->right = r;

    l->left = ll;
    l->right = lr;

    r->left = rl;
    r->right = rr;

    // inOrder(root);
    // cout << "\n";

    root = lowestCommonAncestor(root, rl, rr);
    // cout << "LCA : " << root->val;
    return 0;
}
