#include <bits/stdc++.h>
using namespace std;

void find(vector<vector<int>> &M, int i, int j, int ROW, int COL)
{

    if (i < 0 || j < 0 || i > (ROW - 1) || j > (COL - 1) || M[i][j] != 1)
    {
        return;
    }

    if (M[i][j] == 1)
    {
        M[i][j] = 0;
        find(M, i + 1, j, ROW, COL);     // right side traversal
        find(M, i - 1, j, ROW, COL);     // left side traversal
        find(M, i, j + 1, ROW, COL);     // upward side traversal
        find(M, i, j - 1, ROW, COL);     // downward side traversal
        find(M, i + 1, j + 1, ROW, COL); // upward-right side traversal
        find(M, i - 1, j - 1, ROW, COL); // downward-left side traversal
        find(M, i + 1, j - 1, ROW, COL); // downward-right side traversal
        find(M, i - 1, j + 1, ROW, COL); // upward-left side traversal
    }
}

int countIslands(vector<vector<int>> &M)
{
    int ROW = M.size();
    int COL = M[0].size();
    int count = 0;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (M[i][j] == 1)
            {
                count++;
                find(M, i, j, ROW, COL); // traversal starts from current cell
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> M = {{1, 1, 0, 0, 0},
                             {0, 1, 0, 0, 1},
                             {1, 0, 0, 1, 1},
                             {0, 0, 0, 0, 0},
                             {1, 0, 1, 0, 1}};

    for (int i = 0; i < M.size(); i++)
    {
        for (int j = 0; j < M[i].size(); j++)
        {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Number of islands is: " << countIslands(M) << endl;
    return 0;
}