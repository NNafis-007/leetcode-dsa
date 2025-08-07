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

vector<vector<int>> levelOrder(TreeNode *root)
{
    if (!root)
        return {};
    queue<TreeNode *> q;
    TreeNode *dummy = new TreeNode(-1e9);
    vector<vector<int>> ans;
    q.push(root);
    q.push(dummy); // end of level marker
    int i = 0;
    ans.push_back({});

    while (q.size() > 1)
    {
        TreeNode *tn = q.front();
        q.pop();

        // level end
        if (tn == dummy)
        {
            q.push(dummy);
            cout << "\n";
            i++;
            ans.push_back({});
            continue;
        }
        else
        {
            if (tn->left)
                q.push(tn->left);
            if (tn->right)
                q.push(tn->right);
        }

        cout << tn->val << " ";
        ans[i].push_back(tn->val);
    }

    reverse(ans.begin(), ans.end());
    
    return ans;
}

void printImage(vector<vector<int>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {

        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "SIZE : " << v.size() << "\n";
}

int main()
{
    TreeNode *root = new TreeNode(3);
    TreeNode *l = new TreeNode(9);
    TreeNode *ll = new TreeNode(0);
    TreeNode *lr = new TreeNode(4);

    TreeNode *r = new TreeNode(20);
    TreeNode *rl = new TreeNode(15);
    TreeNode *rr = new TreeNode(7);

    root->left = l;
    root->right = r;

    // l->left = ll;
    // l->right = lr;

    r->left = rl;
    r->right = rr;

    vector<vector<int>> v = levelOrder(root);
    cout << "-------- Returned ----------\n";
    printImage(v);

    return 0;
}
