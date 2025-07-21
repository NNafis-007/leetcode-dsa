#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int maxProf = 0, mini = 1e9;
    for(int price : prices){    
        mini = min(price, mini);
        maxProf = max(maxProf, price - mini);
    }
    return maxProf;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    while (n--)
    {
        int x;
        cin >> x;
    }
    maxProfit(v);
}