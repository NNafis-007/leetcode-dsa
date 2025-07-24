#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &image, int r, int c, int color, int og_color){
    if(r < 0 || r >= image.size() || c < 0 || c >= image[0].size()) return;
    if(image[r][c] != og_color) return;


    cout << "(" << r << "," << c << ")\n";
    image[r][c] = color;
    dfs(image, r+1, c, color, og_color);
    dfs(image, r-1, c, color, og_color);
    dfs(image, r, c-1, color, og_color);
    dfs(image, r, c+1, color, og_color);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    // We're changing all pixels with the starting_color to Given-color
    // if starting color aldy == given_color
    // then all changable pixel (image[r][c] == starting color) aldy has 
    // the same color as the given_color
    // trivially solved, so return 
    if(image[sr][sc] == color) 
        return image;
    dfs(image, sr, sc, color, image[sr][sc]);
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

    image = floodFill(image, 0, 0, 0);

    cout << "---- AFTER ----\n";
    printImage(image);

    return 0;
}