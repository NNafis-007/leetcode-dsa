#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int mjElem = nums[0];
    int cnt = 1;
    int n = nums.size();
    for(int i = 1; i < n; i++){
        if(nums[i] == mjElem) cnt++;
        else{
            cnt--;
            if(cnt==0){
                // cout << "Changing major element from " 
                //     << mjElem << ", to " << nums[i] 
                //     << " - (at index ) " << i <<  endl;
                mjElem = nums[i];
                cnt++;
            }
        }
    }
    return mjElem;

}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    while(n--){
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << "FINAL ANS : " << majorityElement(v);
    return 0;
}