#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string str)
{
    unordered_map<char, int> m;
    int maxi = -1;
    int s = 0, e = 0;
    int n = str.length();
    while(e < n){
        char ch = str[e];

        // char repeated
        if(m.find(ch) != m.end()){
            // remove the string until the first occurance
            int firstOccurance = m[ch];
            while(s <= firstOccurance){
                m.erase(str[s++]);
            }
        }
        m[ch] = e++;
        maxi = max(maxi, e-s);
    }
    return maxi;
}

int main()
{
    string s;
    cin >> s;
    cout << "Ans : " << lengthOfLongestSubstring(s) << endl;
    return 0;
}