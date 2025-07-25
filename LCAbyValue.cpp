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

vector<TreeNode *> pa;
vector<TreeNode *> qa;

bool comp(TreeNode *x, TreeNode *y)
{
    return x->val < y->val;
}

void postOrder(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root)
        return;

    // Reset state for child nodes
    addP = false;
    addQ = false;

    postOrder(root->left, p, q);
    if (addP)
        pa.push_back(root);
    if (addQ)
        qa.push_back(root);

    // Store LST states for parent nodes as they might change in child
    bool prevAddp = addP;
    bool prevAddQ = addQ;

    postOrder(root->right, p, q);
    if (addP)
        pa.push_back(root);
    if (addQ)
        qa.push_back(root);

    cout << "at node : " << root->val << "\n";

    // if current node is an ancestor, parent will be one too
    if (root->val == p->val || prevAddp)
        addP = true;
    if (root->val == q->val || prevAddQ)
        addQ = true;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    pa.push_back(p);
    qa.push_back(q);
    postOrder(root, p, q);
    sort(pa.begin(), pa.end(), comp);
    sort(qa.begin(), qa.end(), comp);
    int i = 0, j = 0;
    while (i < pa.size() && j < qa.size())
    {
        if (pa[i]->val == qa[j]->val)
        {
            return pa[i];
        }
        if (pa[i]->val < qa[j]->val)
            i++;
        else
            j++;
    }
    return nullptr;
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

    root = lowestCommonAncestor(root, l, r);
    cout << "LCA : " << root->val;
    return 0;
}
