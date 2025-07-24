#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    queue<pair<int, int>> q;
    q.push({sr, sc});
    int starting_color = image[sr][sc];

    // Optimization : if OGcolor aldy color, no need to change color hence visited 
    // vector<vector<bool>> visited(image.size(), 
    //     vector<bool>(image[0].size(), false));

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if(image[r][c] == color) continue;
        
        // do op for current pixel and push neighbors
        if (image[r][c] == starting_color)
        {
            image[r][c] = color; // change color
            if(c > 0){ 
                if(image[r][c-1] != color)
                    q.push({r, c-1}); 
            } 
            if(c < image[0].size() - 1) {
                if(image[r][c+1] != color)
                    q.push({r, c+1});
            }
            if(r > 0) {
                if(image[r-1][c] != color)
                    q.push({r-1, c});
            } 
            if(r < image.size() - 1) {
                if(image[r+1][c] != color)
                    q.push({r+1, c});
            }
        }
    }

    return image;
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

    image = floodFill(image, 1, 1, 2);

    cout << "---- AFTER ----\n";
    printImage(image);

    return 0;
}