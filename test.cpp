#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {1,1,1,3,3,4,3,2,4,2};
    int xors = 0;
    for(int x : v){
        xors = x ^ xors;
        cout << "After " << x << " | xor = " << xors << endl;
    }
    return 0;
}