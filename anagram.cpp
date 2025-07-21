#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
        return false;
    int cnts[26] = {};
    for (char ch : s)
    {
        cnts[ch - 'a']++;
    }
    for (char ch : t)
    {
        cnts[ch - 'a']--;
    }

    for (int i = 0; i < 25; i++)
    {
        if (cnts[i] != 0)
            return false;
    }
    return true;
}

int main()
{
    return 0;
}

