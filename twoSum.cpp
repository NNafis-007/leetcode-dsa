#include <iostream>
#include <unordered_map>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> m;
    m[target - nums[0]] = 0;
    for(int i = 1; i < nums.size(); i++){
        if(m.find(nums[i]) != m.end()){
            // 2 sum indices found
            return {m[nums[i]], i};
        }
        m[target - nums[i]] = i;
    }

    return {};
}

int main(){
    int n, target;
    cin >> n >> target;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    v = twoSum(v, target);
    cout << "Indices : " << v[0] << ", " << v[1];

}