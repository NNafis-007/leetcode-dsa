#include <bits/stdc++.h>
using namespace std;
#define start(i) intervals[i][0]
#define end(i) intervals[i][1]

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    if (intervals.empty())
    {
        intervals.push_back(newInterval);
        return intervals;
    }

    int i = 0;
    int n = intervals.size();
    vector<vector<int>> ans;
    while (i < n && start(i) <= newInterval[0])
    {
        ans.push_back(intervals[i]);
        i++;
    }
    // cout << "Start found before " << i
    //      << "-> " << start(i) << "," << end(i) << endl;

    // merge with prev
    if (i > 0 && newInterval[0] <= end(i - 1))
    {
        // No modifications needed when merging with prev
    }

    // merge with next
    else if (i < n && newInterval[1] >= start(i))
    {
        ans.push_back(intervals[i]);
        ans[ans.size() - 1][0] = min(newInterval[0], start(i));
    }
    // no merge
    else
    {
        // insert at current location
        intervals.insert(intervals.begin() + i, newInterval);
        return intervals;
    }

    while (i < n && newInterval[1] >= start(i))
        i++;
    // cout << "END FOUND before : " << i
    //      << "-> " << start(i) << "," << end(i) << endl;
    ans[ans.size() - 1][1] = max(newInterval[1], end(i - 1));

    while (i < n)
        ans.push_back(intervals[i++]);
    return ans;
}

int main()
{
    int n, ns, ne;
    cin >> n >> ns >> ne;
    vector<vector<int>> v;
    while (n--)
    {
        int s, e;
        cin >> s >> e;
        v.push_back({s, e});
    }

    for (auto pr : v)
    {
        cout << "start : " << pr[0] << " | end : " << pr[1] << endl;
    }

    cout << "-------------\n";

    vector<int> ni = {ns, ne};
    v = insert(v, ni);

    for (auto pr : v)
    {
        cout << "start : " << pr[0] << " | end : " << pr[1] << endl;
    }
    return 0;
}