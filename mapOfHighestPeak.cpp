#include <bits/stdc++.h>
using namespace std;

#define min4(a, b, c, d) min(a, min(b, min(min(c, d))))
vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct pair_hash
{
    size_t operator()(const pair<int, int> &p) const
    {
        return p.first ^ (p.second << 1);
    }
};

// O(m*n)
vector<vector<int>> highestPeak(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<bool>> visited;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        vector<bool> tmp;
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 1)
            {
                mat[i][j] = 0;
                q.push({i, j});
                tmp.push_back(true);
            }
            else{
                mat[i][j] = 1e9;
                tmp.push_back(false);
            }
        }
        visited.push_back(tmp);
    }

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        // cout << "POPPED " << r << ", " << c << endl;
        q.pop();

        for (auto dir : dirs)
        {
            int nr = r + dir.first;
            int nc = c + dir.second;
            if (nr >= 0 && nr < n && nc >= 0 && nc < m)
            {
                if (mat[nr][nc] == 0)
                {
                    mat[nr][nc] = 0;
                    if (!visited[nr][nc])
                    {
                        q.push({nr, nc});
                        visited[nr][nc] = true;
                    }
                }
                else
                {
                    // updatable
                    if (mat[nr][nc] > mat[r][c] + 1)
                    {
                        // cout << "\tUpdating for (" << nr << ", " << nc << ") = " << mat[r][c] + 1 << endl;
                        mat[nr][nc] = mat[r][c] + 1;
                        if (!visited[nr][nc])
                        {
                            q.push({nr, nc});
                            visited[nr][nc] = true;
                        }
                    }
                }
            }
        }
    }
    return mat;
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
    vector<vector<int>> image;
    for (int i = 0; i < m; i++)
    {
        vector<int> row;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            row.push_back(x);
        }
        image.push_back(row);
    }

    cout << "input done, ORIGINAL " << endl;
    printImage(image);

    image = highestPeak(image);

    cout << "Func done, After " << endl;
    printImage(image);

    return 0;
}