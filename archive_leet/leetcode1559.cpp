#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <stack>
#include <map>
#include <random>
#include <queue>
#include <list>
#include <numeric>
#include <algorithm>
#include <sstream>


using namespace std;




class Solution {
public:
    static bool is_valid_ax(int i, int j, vector<vector<char>>& grid) {
        return (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size());
    }
    bool dfs(vector<vector<char>>& grid, 
             vector<vector<int>> &path_index, 
             vector<vector<bool>> &visited, 
             vector<vector<int>> &dir,
             char &c, 
             int cur_len,
             int cur_i,
             int cur_j) {
        if (grid[cur_i][cur_j] != c) {
            return false;
        }
        visited[cur_i][cur_j] = true;
        
        // try 4 directions
        path_index[cur_i][cur_j] = cur_len + 1;

        for (int i = 0; i < 4; i++) {
            int try_i = cur_i + dir[i][0];
            int try_j = cur_j + dir[i][1];

            if (is_valid_ax(try_i, try_j, grid)) {
                if (path_index[try_i][try_j] > 0 && (cur_len + 1) - path_index[try_i][try_j] >= 3) {
                    return true;
                }
                if (path_index[try_i][try_j] == 0) {
                    bool cur_r = dfs(grid, path_index, visited, dir, c, cur_len + 1, try_i, try_j);
                    if (cur_r) {
                        return true;
                    }
                }
            }
        }

        path_index[cur_i][cur_j] = 0;
        return false;

    }

    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<int>> direcrtions(4, vector<int>());
        vector<bool> char_visited(26, true);
        vector<vector<int>> path_index(grid.size(), vector<int>(grid[0].size(), 0));
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        // up
        direcrtions[0].push_back(0 - 1);
        direcrtions[0].push_back(0);
        // down
        direcrtions[1].push_back(1);
        direcrtions[1].push_back(0);
        // left
        direcrtions[2].push_back(0);
        direcrtions[2].push_back(0 - 1);
        // right
        direcrtions[3].push_back(0);
        direcrtions[3].push_back(0 + 1);

        for (auto i: grid) {
            for (auto j: i) {
                char_visited[j - 'a'] = false;
            }
        }


        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                char c = grid[i][j];
                if (visited[i][j]) {
                    continue;
                }

                bool cur_r = dfs(grid, path_index, visited, direcrtions, c, 0, i, j);
                if (cur_r) {
                    return true;
                }

            }
        }
        return false;
    }
};

int main() {
    cout << "shit !" << endl;
    string s = "leetscode";
    vector<string> dic = {"leet","code","leetcode"};
    vector<vector<char>> char_vv = {
        {'a', 'a', 'a'},
        {'a', 'a', 'a'}
    };
   
    Solution ss;
    bool a = ss.containsCycle(char_vv);
    cout << a << endl;



    cout << "shit!" << endl;

    return 0;
}