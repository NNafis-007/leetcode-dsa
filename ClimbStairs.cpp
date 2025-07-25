#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n)
{
    int n1 = 1;
    int n2 = 2;
    int x;
    if (n <= 2)
        return n;
    for (int i = 3; i <= n; i++)
    {
        x = n2 + n1;
        n1 = n2;
        n2 = x;
    }
    return x;
}

int main()
{
    int n;
    cin >> n;
    cout << "Ways to climb " << n << " stairs : " << climbStairs(n);
    return 0;
}