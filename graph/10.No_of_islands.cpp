// 200. Number of Islands
// Medium

// 7018

// 224

// Add to List

// Share
// Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.



// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3


// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] is '0' or '1'.

// Time COmplex = O(n*m * memory used in stack space)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<char>>& grid, int m, int n, int row, int col) {
    if (row == m || col == n ||
            row == -1 || col == -1 ||
            grid[row][col] != '1'
       )
        return false;
    return true;
}

void no_of_islands(vector<vector<char>> &grid, int row, int col, int m, int n) {
    if (isSafe(grid, m, n, row, col) == false) {
        return;
    }
    grid[row][col] = '2';
    int mov[][2] = {
        {1, 0},
        {0, 1},
        { -1, 0},
        {0, -1}
    };
    for (int i = 0; i < 4; ++i) {
        if (isSafe(grid, m, n, row + mov[i][0] , col + mov[i][1])) {
            no_of_islands(grid, row + mov[i][0], col + mov[i][1], m, n);
        }
    }
    return;

}
int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    int n = grid[0].size();
    int m = grid.size();
    for (int i = 0; i < m; ++i ) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '1') {
                no_of_islands(grid, i, j, m, n);
                count += 1;

            }
        }
    }

    return count;
}


int main() {
    int n = 3, m = 3;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char> (n, '0'));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    int count = numIslands(grid);
    cout << count << "\n";
    return 0;
}