#include <bits/stdc++.h>
using namespace std;

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
}

void printVec(vector<int> &v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << "\n";
}

void helper(vector<vector<int>> &ans, vector<int> &nums, int idx)
{
    cout << "CALLED HELPER FOR idx : " << idx << endl;
    if (idx == nums.size() - 1)
    {
        ans.push_back({vector<int>(1, nums[idx])});
        cout << "pushed " << nums[idx] << " returning ..." << endl;
        return;
    }
    helper(ans, nums, idx + 1);
    int m = ans.size();
    cout << "At index " << idx << ", currently generated perms " << endl;
    printImage(ans);
    for (int i = m - 1; i >= 0; i--)
    {
        int n = ans[i].size();
        for (int j = n; j >= 0; j--)
        {
            vector<int> currPerm = vector<int>(ans[i]);
            currPerm.insert(currPerm.begin() + j, nums[idx]);
            cout << "Generated perm : ";
            printVec(currPerm);
            ans.push_back(currPerm);
        }
        ans.erase(ans.begin() + i);
    }

    cout << "Completed perm at index : " << idx << ", for elem : " << nums[idx] << endl;
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    helper(ans, nums, 0);
    return ans;
}

int main()
{
    int m;
    cin >> m;
    vector<int> v;
    for (int j = 0; j < m; j++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    cout << "input done, ORIGINAL " << endl;
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << "\n";

    permute(v);

    // cout << "---- AFTER ----\n";
    // printImage(image);

    return 0;
}