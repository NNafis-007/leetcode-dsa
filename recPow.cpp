#include<bits/stdc++.h>
using namespace std;

unordered_map<int, double> m;

double recPow(double x, int n){
    if(n == 0) return 1;
    if(n == 1) return x;
    if(n == 2) return x*x;
    if(m.find(n) != m.end()) return m[n];

    double ans1 = recPow(x, n/2);
    cout << x << " to the power " << n/2 << " is : " << ans1 << endl;
    m[n/2] = ans1;
    double ans2 =  recPow(x, n-n/2);
    cout << x << " to the power " << n-n/2 << " is : " << ans2 << endl;
    m[n-n/2] = ans2;
    return ans1 * ans2;
}

double myPow(double x, int n){
    if(n > 0) return recPow(x, n);
    else return (1.0 / recPow(x, abs(n)));
}

int main()
{
    int n;
    cin >> n;
    while(n--){
        double x;
        int n;
        cin >> x >> n;
        // cout << x << " to the power " << n << " is : " 
        //     << myPow(x, n) << endl;
        myPow(x,n);
    }
    return 0;
}