#include <bits/stdc++.h>
using namespace std;
#define x(i) points[i][0]
#define y(i) points[i][1]
#define PII pair<int, int>

// Max heap wrt distance
struct compare
{
    bool operator()(PII a, PII b)
    {
        int x = (a.first * a.first) + (a.second * a.second);
        int y = (b.first * b.first) + (b.second * b.second);
        return x < y;
    }
};

bool comp(vector<int>& v1, vector<int>& v2){
    // v[0] - x_i, v[1] - y[i]
    int d1 = v1[0]*v1[0] + v1[1]*v1[1];
    int d2 = v2[0]*v2[0] + v2[1]*v2[1];

    return d1 < d2;
}

// TC - O(NlogK), SC - O(k)
// vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
// {
//     priority_queue<PII, vector<PII>, compare> pq;
//     for (int i = 0; i < points.size(); i++)
//     {
//         if (pq.size() < k)
//             pq.push({x(i), y(i)});
//         else
//         {
//             int d1 = x(i) * x(i) + y(i) * y(i);
//             int d2 = pq.top().first * pq.top().first +
//                      pq.top().second * pq.top().second;
//             // push into heap if only less than the top, else same thing will be pushed and popped 
//             if (d1 < d2)
//             {
//                 pq.push({x(i), y(i)});
//                 pq.pop();
//             }
//         }
//     }

//     vector<vector<int>> ans;
//     while(!pq.empty()){
//         vector<int> v = {pq.top().first, pq.top().second};
//         ans.push_back(v);
//         pq.pop();
//     }
//     return ans;
// }


// TC - O(NlogN), SC - O(1)
vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    sort(points.begin(), points.end(), comp);
    while(points.size() > k){
        points.pop_back();
    }
    return points;
}



void printImage(vector<vector<int>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {

        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> points;
    for (int i = 0; i < m; i++)
    {
        vector<int> row;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            row.push_back(x);
        }
        points.push_back(row);
    }

    cout << "input done, ORIGINAL " << endl;
    printImage(points);

    points = kClosest(points, 2);

    cout << "---- AFTER ----\n";
    printImage(points);


    // ----- CUSTOM COMPARATOR TESTING -----
    // priority_queue<PII, vector<PII>, compare> pq;

    // pq.push({-5, 1});
    // pq.push({3, 3});
    // pq.push({2, -4});

    // vector<PII> v;
    // v.push_back({-5,1});
    // v.push_back({3,3});
    // v.push_back({2,-4});

    // sort(v.begin(), v.end(), compare());

    // while(!pq.empty()){
    //     cout << pq.top().first << ", " << pq.top().second << endl;
    //     pq.pop();
    // }

    // cout << "printing pairs :\n";
    // for(auto pr : v){
    //     cout << pr.first << "," << pr.second << endl;
    // }
    return 0;
}