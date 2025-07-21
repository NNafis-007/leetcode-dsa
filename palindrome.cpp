#include <bits/stdc++.h>
using namespace std;



bool isPalindrome(string str)
{
    int e = str.length() - 1;
    int s = 0;
    while(s < e)
    {
        char ch1 = tolower(str[s]);
        char ch2 = tolower(str[e]);
        if ((ch1 >= 'a' && ch1 <= 'z') || (ch1 >= '0' && ch1 <= '9'))
        {
            if ((ch2 >= 'a' && ch2 <= 'z') || (ch2 >= '0' && ch2 <= '9')){
                // compare
               // cout << "Comparing " << ch1 << " and " << ch2 << endl;
                if(ch1 != ch2) return false;
                s++; e--;
            }
            else{
                e--;
            }
        }
        else{
            s++;
        }
    }
    return true;
}

int main()
{
    string s;
    getline(cin, s);
    cout << isPalindrome(s);
}