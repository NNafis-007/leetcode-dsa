#include <bits/stdc++.h>
using namespace std;

int longestPalindrome(string s)
{
    unordered_map<char, int> m;
    for (char ch : s)
    {
        m[ch]++;
    }
    int ans = 0;
    bool addOne;
    for (auto pr : m)
    {
        ans += pr.second / 2;
        if (!addOne){
            addOne = (pr.second % 2 == 0)? false : true;
        }
    }
    ans = (ans * 2);
    ans = (addOne) ? ans + 1 : ans;
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << "longest Pal leng : " << longestPalindrome(s);
    return 0;
}