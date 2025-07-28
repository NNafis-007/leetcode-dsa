#include <bits/stdc++.h>
using namespace std;

// KADANE's ALGO
int maxSubArray(vector<int> &nums)
{
    int s = 0, e = 0, endOfSubArr;
    int n = nums.size();
    int sum = 0;
    int maxSum = -1e9; 
    while(e < n){
        cout << "Start " << s << " | end " << e;
        sum += nums[e++];
        if(sum >= maxSum){
            maxSum = sum;
            endOfSubArr = e - 1;
        }
        cout << " | Sum " << sum;
        if(sum < 0){
            sum = 0;
            s = e;
        }
        cout << " | maxSum " << maxSum << endl; 
    }

    cout << "Max subarray start " << s << ", end " << endOfSubArr << endl;
    return maxSum;
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

    cout << "Max subarray sum : " << maxSubArray(v) << endl;
    return 0;
}