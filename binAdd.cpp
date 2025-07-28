#include <bits/stdc++.h>
using namespace std;

string addBinary(string a, string b)
{
    char carry = '0';
    int i = a.size() - 1;
    int j = b.size() - 1;
    string ans(max(i + 2, j + 2), '0');
    int k = ans.size() - 1;
    while (i >= 0 && j >= 0)
    {
        // 1+1 or 0+0
        if (a[i] == b[j])
        {
            ans[k] = carry;
            carry = a[i];
        }
        else
        {
            ans[k] = (carry == '0') ? '1' : '0';
            carry = (ans[k] == '0') ? '1' : '0';
        }
        // cout << "At " << k << "th bit, putting " << ans[k] 
        //     << " | Carry: " << carry << endl;
        i--;
        j--;
        k--;
    }
    if (i >= 0)
    {
        do
        {
            if (a[i] == carry)
            {
                ans[k] = '0';
                carry = a[i];
            }
            else
            {
                ans[k] = '1';
                carry = '0';
            }
            // cout << "At " << k << "th bit, putting " << ans[k] 
            //     << "| Carry : " << carry << endl;

            i--;
            k--;
        } while (i>=0);
    }
    else if (j >= 0)
    {
        do
        {
            if (b[j] == carry)
            {
                ans[k] = '0';
                carry = b[j];
            }
            else
            {
                ans[k] = '1';
                carry = '0';
            }
            // cout << "At " << k << "th bit, putting " << ans[k] 
            //     << "| Carry : " << carry << endl;
            j--;
            k--;
        } while (j >= 0);
    }
    if(carry == '1') ans[k--] = '1';
    if(k >= 0 && ans[k] == '0') ans.erase(0,1);
    return ans;
}

int main()
{
    string a, b;
    cin >> a;
    cin >> b;

    cout << addBinary(a, b);
    return 0;
}