//You are given an m x n binary matrix grid.An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
//
//The area of an island is the number of cells with a value 1 in the island.
//
//Return the maximum area of an island in grid.If there is no island, return 0.

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int height = grid.size();
        int width = grid[0].size();
        int max_Area{ 0 };
        vector<vector<bool>> visited(height, vector<bool>(width, false));
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int counter{ 0 };
                    max_Area = max(max_Area, dfs(grid, visited, i, j));
                }
            }
        }
        return max_Area;
    }

private:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>> &visited, int i, int j) {

        int height = grid.size();
        int width = grid[0].size();
        if (i < 0 || i >= height || j < 0 || j >= width || grid[i][j] == 0 || visited[i][j]) {
            return 0;
        }
        visited[i][j] = true;
        int counter{ 1 };
        counter += dfs(grid, visited, i + 1, j);
        counter += dfs(grid, visited, i - 1, j);
        counter += dfs(grid, visited, i, j + 1);
        counter += dfs(grid, visited, i, j - 1);
        return counter;
    }
};

//int main() {
//    	Solution sol;
//	vector<vector<int>> grid = { {1, 1, 0, 0, 0},
//    								 {1, 1, 0, 0, 0},
//    								 {0, 0, 0, 1, 1},
//    								 {0, 0, 0, 1, 1} };
//	cout << sol.maxAreaOfIsland(grid) << endl;
//	return 0;
//}