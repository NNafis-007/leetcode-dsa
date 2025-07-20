#include <bits/stdc++.h>
using namespace std;

bool isValid(string &s)
{
    stack<char> st;
    st.push('$');
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        
        else if ((st.top() == '(' && s[i] == ')') || (st.top() == '{' && s[i] == '}') || (st.top() == '[' && s[i] == ']'))
        {
            st.pop();
        }
        else{
            return false;
        }
    }
    return st.size() == 1;
}

int main()
{
    string s;
    cin >> s;
    cout << "Valid Parentheses : " << isValid(s);
}